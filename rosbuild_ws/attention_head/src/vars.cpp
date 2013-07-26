#include "vars.h"

void vars::executeCB(const uol_openday_common::Find_peopleGoalConstPtr &goal) {
    boost::lock_guard<boost::mutex> lock(mutex);
    end = ros::Time::now();
    end.sec += goal->time;
}

void vars::preemptCB() {
    boost::lock_guard<boost::mutex> lock(mutex);
    end = ros::Time::now();
    as_.setPreempted();
}

void vars::locationCallback(const cob_people_detection_msgs::DetectionArray::ConstPtr & detectionArray) {


    z = 15;
    bool found = false;

    geometry_msgs::PoseStamped poseInCamCoords;
    geometry_msgs::PoseStamped poseInRobotCoords;

    for (unsigned i = 0; i < detectionArray->detections.size(); i++) {

        if (detectionArray->detections[i].pose.pose.position.z < z) {
            z = detectionArray->detections[i].pose.pose.position.z;
            poseInCamCoords = detectionArray->detections[i].pose;
            poseInCamCoords.pose.orientation.w = 1.0;
            poseInCamCoords.pose.position.x *= -1.0;
            poseInCamCoords.pose.position.y *= -1.0;
            found = true;
            first_notfound = true;

        }
    }

    if (!found) {
        if (first_notfound) {
            first_notfound = false;
            x = 0;
            y = 0;
            z = 0;
        } else {
            return;
        }
    }

    poseInCamCoords.header.frame_id = "/head_xtion_rgb_optical_frame";
    try {
        listener.transformPose("/head_base_frame", poseInCamCoords, poseInRobotCoords);
    } catch (tf::TransformException ex) {
        ROS_ERROR("%s", ex.what());

    }

    x = poseInRobotCoords.pose.position.x;
    y = poseInRobotCoords.pose.position.y;
    z = poseInRobotCoords.pose.position.z;

    {
        boost::lock_guard<boost::mutex> lock(mutex);
        if (ros::Time::now() < end) {
            Server_success = true;
            feedback_.targetPoint.x = x;
            feedback_.targetPoint.y = y;
            feedback_.targetPoint.z = z;
            as_.publishFeedback(feedback_);
        } else if (Server_success && ros::Time::now() > end) {
            Server_success = false;
            as_.setSucceeded(result_);
        }
    }

    double threshold = 0.1;
    if ((x - last_x > threshold) ||
            (x - last_x < -threshold) ||
            (y - last_y > threshold) ||
            (y - last_y < -threshold) ||
            (z - last_z > threshold) ||
            (z - last_z < -threshold)) {
        sensor_msgs::JointState state;
        state.name.push_back("HeadPan");
        state.name.push_back("HeadTilt");
        state.position.push_back(std::atan2(y, x)*180.0 / M_PI);
        state.position.push_back(std::atan2(z, x)*180.0 / M_PI);
        state.header.stamp = detectionArray->header.stamp;
        listening_pub.publish(state);
        last_x = x;
        last_y = y;
        last_z = z;
    }
}

