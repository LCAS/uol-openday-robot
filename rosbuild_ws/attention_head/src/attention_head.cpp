#include "attention_head.h"

//actionLib function
void attention_head::executeCB(const uol_openday_common::Find_peopleGoalConstPtr & goal)
{
    //Makes end variable thread safe
    boost::lock_guard < boost::mutex > lock(mutex);
    //sets the maximum time until the server cancels
    //this value is ignored if canel method called manually by a client
    end = ros::Time::now();
    end.sec += goal->time;
    //sends an empty respone to the client
    as_.setSucceeded(result_);
}

//function to allowed the client to canel attention_head server
void attention_head::preemptCB()
{
    //feedback
    ROS_INFO("Trying to cancel");
    {
	//Makes end variable thread safe
	boost::lock_guard < boost::mutex > lock(mutex);
	end = ros::Time::now();
	//inform client that the process as been canceled
	as_.setPreempted();
	//feedback    
	ROS_INFO("Cancelled");
    }
}

//Call back subscribed to "/cob_people_detection/detection_tracker/face_position_array"
void attention_head::locationCallback(const cob_people_detection_msgs::DetectionArray::ConstPtr & detectionArray)
{
	//set to high number in order to reset closest person
    double z = 15;
	//presume person isn't found
    bool found = false;
	//transformed coordinates from camera level
    geometry_msgs::PoseStamped poseInCamCoords;
	//transformed coordinates from base of the head
    geometry_msgs::PoseStamped poseInRobotCoords;

	//loops through people detected
    for (unsigned i = 0; i < detectionArray->detections.size(); i++) {
	//Finds the closest person and sets cam pose to robot pose
	if (detectionArray->detections[i].pose.pose.position.z < z) {
		//sets new z to find closest person
		z = detectionArray->detections[i].pose.pose.position.z;
		//saves closest pose
	    poseInCamCoords = detectionArray->detections[i].pose;
	    poseInCamCoords.pose.orientation.w = 1.0;
		//Someone has been found
	    found = true;
		//resets to be true the frist time someone isn't found
	    first_notfound = true;
	}
    }
    if (!found) {
		if (first_notfound) {
			//changes first	not foud, but only the first time		
			first_notfound = false;
		} else {
		//skips publishing
			return;
		}
    }
	//sets frame ID incase there isn't one set by default
    poseInCamCoords.header.frame_id = "/head_xtion_rgb_optical_frame";
    
try {
	if (found) {
		//tries to transform the coordinates
	    listener.transformPose("/head_base_frame", poseInCamCoords, poseInRobotCoords);
	} else {
		//if nobody is found point the head forward
	    poseInRobotCoords.pose.position.x = 0.0;
	    poseInRobotCoords.pose.position.y = 0.0;
	    poseInRobotCoords.pose.position.z = 0.0;
	}
    }
    catch(tf::TransformException ex) {
	//feedback	
	ROS_ERROR("%s", ex.what());
    }
	//variables used to work out angles from head position
    double x = poseInRobotCoords.pose.position.x;
    double y = poseInRobotCoords.pose.position.y;
    z = poseInRobotCoords.pose.position.z;

    {
    //Makes end variable thread safe
	boost::lock_guard < boost::mutex > lock(mutex);
	
	if (ros::Time::now() < end) {
	    //keep sever going
		Server_success = true;
		//send feedback, same as result, except server wont exit
	    feedback_.targetPoint.x = x;
	    feedback_.targetPoint.y = y;
	    feedback_.targetPoint.z = z;
		//publish feedback
	    as_.publishFeedback(feedback_);
	} else if (Server_success && ros::Time::now() > end){
	    //stop sever	    
		Server_success = false;
		}
    }

	//prevents the head from jittering, adjust threshold value accordingly. 
    double threshold = 0.1;
    if ((x - last_x > threshold) || (x - last_x < -threshold) || (y - last_y > threshold) || (y - last_y < -threshold) || (z - last_z > threshold) || (z - last_z < -threshold)) {
	
	sensor_msgs::JointState state;
	//add HeadPan
	state.name.push_back("HeadPan");
	//add HeadTilt
	state.name.push_back("HeadTilt");
	//Add HeadPan angle coordinate tp the Joint State Position
	state.position.push_back(std::atan2(y, x) * 180.0 / M_PI);
	//Add HeadTilt angle coordinate tp the Joint State Position
	state.position.push_back(std::atan2(z, x) * 180.0 / M_PI);
	state.header.stamp = detectionArray->header.stamp;
	//publishes coordinates
	listening_pub.publish(state);
	//sets last 
	last_x = x;
	last_y = y;
	last_z = z;
    }
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "find_people");

    attention_head sensible_name(ros::this_node::getName());
    ros::spin();

    return 0;
}

