attention_head
==============

* Please see the set up wiki for install directions before proceeding: https://github.com/LCAS/uol-openday-robot/wiki/Set-up


* It is important that we run cob_people_detection before we start attention head as attention head depends upon cob people detection.

* To start with we need to soruce our workspace. As our rosbuild workspace overlays our catkin workspace we'll need to source the setup file from the rosbuild workspace. We can do this by typing the following command from the root of our rosbuild workspace:


* To run this type :
```
source setup.bash
```

* We can then launch cob_people_detection by running:

```
roslaunch uol_launch people_detection.launch
```

* You should see a window launch with the camera stream in it.

* After this we can start attention_head, open a new terminal and source it:
```
source setup.bash
```

* finally, so start attention head, type:
```
rosrun attention_head attention_head
```



* Once running attention_head can also be used as an actionlib server
* The Goal state is an int32 time. This is the maximum amount of time the server will respond
* The Feedbck state is the Pose which returns the postion
* There is no result, as this would end the server

