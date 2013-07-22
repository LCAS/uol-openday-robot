#include "ros/ros.h"
#include <cob_people_detection_msgs/DetectionArray.h>
#include <iostream>
#include <sensor_msgs/JointState.h>
#include "vars.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "attention_head");
    vars h;
    ros::spin();
    return 0;
}
