#include "ros/ros.h"
#include <cob_people_detection_msgs/DetectionArray.h>
#include <iostream>
#include <vector>
#include <sensor_msgs/JointState.h>


ros::Publisher listening_pub;

void locationCallback(const cob_people_detection_msgs::DetectionArray::ConstPtr& detectionArray) {
    double x, y, z = 15;

    for (unsigned i = 0; i < detectionArray->detections.size(); i++) {

        if (detectionArray->detections[i].pose.pose.position.z < z) {
            x = detectionArray->detections[i].pose.pose.position.x;
            y = detectionArray->detections[i].pose.pose.position.y;
            z = detectionArray->detections[i].pose.pose.position.z;
        }
    }
    sensor_msgs::JointState state;
    state.position.push_back(x);
    state.position.push_back(y);
    state.header.stamp = detectionArray->header.stamp;
    state.header.frame_id = detectionArray->header.frame_id;
    listening_pub.publish(state);

    sleep(2);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "commanded_state");
    ros::NodeHandle n("commanded_state");
    ros::Subscriber sub = n.subscribe("/cob_people_detection/detection_tracker/face_position_array", 4, locationCallback);
    listening_pub = n.advertise<sensor_msgs::JointState>("/head/commanded_state", 10);
    ros::spin();
    return 0;
}