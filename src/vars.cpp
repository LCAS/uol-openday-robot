#include "vars.h"
#include <sensor_msgs/JointState.h>

vars::vars() {
    last_x = 0;
    last_y = 0;
    last_z = 0;
    ros::NodeHandle n("attention_head");
    //ros::Subscriber sub = 
    n.subscribe("/cob_people_detection/detection_tracker/face_position_array", 4, &vars::locationCallback,this);
    listening_pub = n.advertise<sensor_msgs::JointState>("/head/commanded_state", 10);
}

void vars::locationCallback(const cob_people_detection_msgs::DetectionArray::ConstPtr& detectionArray) {
    double x, y, z = 15;

    for (unsigned i = 0; i < detectionArray->detections.size(); i++) {

        if (detectionArray->detections[i].pose.pose.position.z < z) {
            x = detectionArray->detections[i].pose.pose.position.x;
            y = detectionArray->detections[i].pose.pose.position.y;
            z = detectionArray->detections[i].pose.pose.position.z;
        }
    }
    tf::StampedTransform transform;
    listener.lookupTransform("/head_xtion_depth_optical_frame", "/base_link", ros::Time(0), transform);

    x = transform.getOrigin().x();
    y = transform.getOrigin().y();
    z = transform.getOrigin().z();

    if (((std::atan2(-x, z)*180.0 / M_PI) - (std::atan2(-last_x, last_z)*180.0 / M_PI) > 5) ||
            ((std::atan2(-x, z)*180.0 / M_PI) - (std::atan2(-last_x, last_z)*180.0 / M_PI) < -5) ||
            ((std::atan2(-y + 0.3, z)*180.0 / M_PI) - (std::atan2(-y + 0.3, z)*180.0 / M_PI) > 5) ||
            ((std::atan2(-y + 0.3, z)*180.0 / M_PI) - (std::atan2(-y + 0.3, z)*180.0 / M_PI) < -5)) {
        last_x = x;
        last_y = y;
        last_z = z;

        sensor_msgs::JointState state;
        state.name.push_back("HeadPan");
        state.name.push_back("HeadTilt");

        state.position.push_back(std::atan2(-x, z)*180.0 / M_PI);
        state.position.push_back(std::atan2(-y + 0.3, z)*180.0 / M_PI);
        state.header.stamp = detectionArray->header.stamp;

        if (detectionArray->header.frame_id == "") {
            state.header.frame_id = "/head_xtion";
        } else {
            state.header.frame_id = detectionArray->header.frame_id;
        }
        listening_pub.publish(state);
    }
}