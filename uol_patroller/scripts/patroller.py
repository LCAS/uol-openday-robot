#! /usr/bin/env python
import time

import rospy
import csv

import roslib; roslib.load_manifest('uol_patroller')
import actionlib
from random import randrange, randint
import smach
import smach_ros
from smach_ros import SimpleActionState

# Brings in the SimpleActionClient
import actionlib
from actionlib_msgs.msg import *
from move_base_msgs.msg import *
from uol_patroller.msg import *



frame_id="/map"

curLocation = ""

class EngagePeople(smach.State):
    def __init__(self):
        smach.State.__init__(self,
            outcomes    = ['success', 'failure'],
            input_keys=['goal_reached']
            
        )
        
    def execute(self,userdata):

		rospy.loginfo("Engaging people.")
		if rospy.is_shutdown(): # Exiting gracefully when ctrl-c is pressed
			return 'abort'

		rospy.loginfo("Creating engagement client.")
		self.client = actionlib.SimpleActionClient('uol_patroller/engage', patrolAction)
		self.client.wait_for_server()
		rospy.loginfo("Engage client initialized")
		goal = patrolGoal()		# Define action
		goal.find_seconds = 60	# talk for random time
		goal.mary_seconds = 30
		goal.location = curLocation

		# Fill in the goal here
		self.client.send_goal(goal)

		print "Should hang until completion"
		self.client.wait_for_result(rospy.Duration.from_sec(0.0))
		print "Did I?"
		result=self.client.get_state()

		if result != GoalStatus.SUCCEEDED:
			return 'failure'
		return 'success'

class GoTo(smach.State):
    def __init__(self):
        smach.State.__init__(self,
            outcomes    = ['success', 'failure'],
            input_keys=['goal_pose'],
            output_keys=['goal_reached']
            
        )
	
        rospy.loginfo("Creating base movement client.")
        self.baseClient = actionlib.SimpleActionClient(
            'move_base',
            MoveBaseAction
        )
        self.baseClient.wait_for_server()
        rospy.loginfo("Base client initialized")

    def execute(self,userdata):

        rospy.loginfo("Moving the base.")
        if rospy.is_shutdown(): # Exiting gracefully when ctrl-c is pressed
            return 'abort'


        self.baseClient.send_goal(userdata.goal_pose)

        self.baseClient.wait_for_result()

        result=self.baseClient.get_state()
        

        if result != GoalStatus.SUCCEEDED:
            return 'failure'

        return 'success'

      


class PointReader(smach.State):
    def __init__(self, file_name):
        smach.State.__init__(self,
            outcomes    = ['goto_point'],
            output_keys=['goal_pose']
            
        )


	self.points=[]
	with open(file_name, 'rb') as csvfile:
		reader = csv.reader(csvfile, delimiter=',')
		for row in reader:
			current_row=[]
			for element in row:
				try:
					current_row.append(float(element))
				except:
					current_row.append(str(element))
				self.points.append(current_row)

	
	self.current_point=0
	self.n_points=len(self.points)








    def execute(self,userdata):



	next_goal = move_base_msgs.msg.MoveBaseGoal()
	print self.points
	print self.points[self.current_point]
	current_row=self.points[self.current_point]
	next_goal.target_pose.header.frame_id = frame_id
	next_goal.target_pose.header.stamp = rospy.Time.now()
	next_goal.target_pose.pose.position.x=current_row[1]
	next_goal.target_pose.pose.position.y=current_row[2]
	next_goal.target_pose.pose.position.z=current_row[3]
	next_goal.target_pose.pose.orientation.x=0.0000000000
	next_goal.target_pose.pose.orientation.y=0.0000000000
	next_goal.target_pose.pose.orientation.z=-0.7268487981
	next_goal.target_pose.pose.orientation.w=0.6867975135
	
	print 'Heading to the waypoint %s.' % current_row[0]
	curLocation = current_row[0]
	self.current_point=self.current_point+1
	print self.current_point
	print current_row
	if self.current_point==self.n_points:
		self.current_point=0

	userdata.goal_pose=next_goal





     	
        return 'goto_point'








def main():


    rospy.init_node('uol_patroller')

    frame_id="/map"


    if len(sys.argv)<2:
      rospy.logerr("No waypoints file given. Use rosrun waypoint_patroller patroller.py [path to csv waypoints file]. If you are using a launch file, see launch/patroller.launch for an example.")
    #'/home/strands/catkin_ws/src/uol_action_openday/pydev/scripts/waypoints.cvs'
    waypoints_name=sys.argv[1]


    # Create a SMACH state machine
    sm = smach.StateMachine(['succeeded','aborted','preempted'])
    with sm:
        smach.StateMachine.add('POINT_READER', PointReader(waypoints_name), 
                               transitions={'goto_point':'GOING_TO_POINT'},
                               remapping={'goal_pose':'goal_pose'})

        smach.StateMachine.add('GOING_TO_POINT', GoTo(), 
                               transitions={'success':'ENGAGING_PEOPLE','failure':'aborted'},
                               remapping={'goal_pose':'goal_pose'})
                               
        smach.StateMachine.add('ENGAGING_PEOPLE', EngagePeople(), 
                               transitions={'success':'POINT_READER','failure':'POINT_READER'},
                               remapping={'goal_pose':'goal_pose'})



 
    

    # Execute SMACH plan

    sis = smach_ros.IntrospectionServer('server_name', sm, '/SM_ROOT')
    sis.start()
    outcome = sm.execute()

    rospy.spin()
    sis.stop()


if __name__ == '__main__':
    main()






0
