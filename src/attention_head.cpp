#include "vars.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "find_people");

    vars sensible_name(ros::this_node::getName());
    ros::spin();

    return 0;
}
