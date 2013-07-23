#include "vars.h"

vars::vars() : node("attention_head") {
    //previous coordiantes
    last_x = 0;
    last_y = 0;
    last_z = 15;
    //current coordinates
    x = 0;
    y = 0;
    z = 0;
    //subscriber feel to get input from cob_people_detection
    sub = node.subscribe("/cob_people_detection/detection_tracker/face_position_array", 4, &vars::locationCallback, this);
    listening_pub = node.advertise<sensor_msgs::JointState>("/head/commanded_state", 10);
}

void vars::locationCallback(const cob_people_detection_msgs::DetectionArray::ConstPtr& detectionArray) {
    z = 15;

    geometry_msgs::PoseStamped poseInCamCoords;
    geometry_msgs::PoseStamped poseInRobotCoords;

    for (unsigned i = 0; i < detectionArray->detections.size(); i++) {

        if (detectionArray->detections[i].pose.pose.position.z < z) {
            poseInCamCoords = detectionArray->detections[i].pose;
        }
    }

    poseInCamCoords.header.frame_id = "/head_xtion_depth_optical_frame";
    listener.transformPose("/head_base_frame", poseInCamCoords, poseInRobotCoords);
    x = poseInRobotCoords.pose.position.x;
    y = poseInRobotCoords.pose.position.y;
    z = poseInRobotCoords.pose.position.z;


    double threshold = 0.2;
    if ((x - last_x > threshold) ||
            (x - last_x < -threshold) ||
            (y - last_y > threshold) ||
            (y - last_y < -threshold) ||
            (z - last_z > threshold) ||
            (z - last_z < -threshold)) 
    {
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
