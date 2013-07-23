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
    for (unsigned i = 0; i < detectionArray->detections.size(); i++) {

        if (detectionArray->detections[i].pose.pose.position.z < z) {
            x = detectionArray->detections[i].pose.pose.position.x;
            y = detectionArray->detections[i].pose.pose.position.y;
            z = detectionArray->detections[i].pose.pose.position.z;
        }
    }
  tf::StampedTransform transform;
    try {
        listener.lookupTransform("/head_xtion_depth_optical_frame", "/base_link",
                ros::Time(0), transform);
    } catch (tf::TransformException ex) {
        std::cout << "something went wrong... We're working on it..." << std::endl;
    }

    std::cout << "x:" << x << std::endl;
    std::cout << "y:" << y << std::endl;
    std::cout << "z:" << z << std::endl;
    std::cout << "Tx:" << transform.getOrigin().x() << std::endl;
    std::cout << "Ty:" << transform.getOrigin().x() << std::endl;
    std::cout << "Tz:" << transform.getOrigin().x() << std::endl;


    double threshold = 0.2;
    if ((x - last_x > threshold) ||
            (x - last_x < -threshold) ||
            (y - last_y > threshold) ||
            (y - last_y < -threshold) ||
            (z - last_z > threshold) ||
            (z - last_z < -threshold)) {

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
        last_x = x;
        last_y = y;
        last_z = z;
    }
}
