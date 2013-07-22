#include <tf/transform_listener.h>
#include <vector>
#include <math.h>
#include <cob_people_detection_msgs/DetectionArray.h>
#include <iostream>
#include <sensor_msgs/JointState.h>

class vars {
public:
    double last_x, last_y, last_z;
    ros::Publisher listening_pub;
    tf::TransformListener listener;
    
    void locationCallback(const cob_people_detection_msgs::DetectionArray::ConstPtr& detectionArray);
    vars();
};