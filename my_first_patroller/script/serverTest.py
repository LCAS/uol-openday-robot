#! /usr/bin/env python

import roslib; roslib.load_manifest('patroller'); roslib.load_manifest('ros_mary_tts');
import rospy
import actionlib
import tf
import time
import math 

from patroller.msg import *
from random import randrange, randint

from geometry_msgs.msg import Twist
# Import for rotate
from nav_msgs import *

#anything ross mary-y
from ros_mary_tts.srv import *
from ros_mary_tts.msg import *

from uol_openday_common.msg import *


marySpeak = actionlib.SimpleActionClient('speak', maryttsAction)
findPeople = actionlib.SimpleActionClient('find_people', Find_peopleAction)
#pub = rospy.Publisher('/odom', String)



class PatrollerServer:

	

	def __init__(self):
		self.server = actionlib.SimpleActionServer('patroller', patrolAction, self.execute, False)
		self.server.start()
		rospy.Subscriber("/find_people/feedback", Find_peopleActionFeedback, self.callback) 
		self.pub = rospy.Publisher('/cmd_vel', Twist)


	def callback(self, fb): 
		# spin the base
		# turning speed
		print fb
		twist = Twist()
		twist.angular.z = -math.atan2(fb.feedback.targetPoint.y,fb.feedback.targetPoint.x)*0.3
		#twist.angular.z = -math.atan2(fb.feedback.targetPoint.y,fb.feedback.targetPoint.x)*0.3
		self.pub.publish(twist)

	def execute(self, goal):
		self.count = 5
		# Call Headspin Service 360
		turn = randint(0,359)	
		print "Person detected with kinect %i degrees off current position." % turn
		
		myBool = False			
		startTime = time.time()
		
		findPeople.wait_for_server() 	# establish TCP
		find_goal = Find_peopleGoal()		# Define action
		find_goal.time = goal.find_seconds

		# Call Marys Voice
		findPeople.send_goal(find_goal)
		
		rospy.logdebug(rospy.get_name() + " setting up")
		

		File = open("/home/strands/catkin_ws/src/uol_action_openday/pydev/scripts/voiceScript.txt")
		scriptLine = []
		
		while 1:
			line = File.readline()
			if not line:
				break
			pass # do something
			scriptLine.append(line)

		# submit command to engage
		while myBool != True: 		# Loop while counting 
				
			#self.pub = rospy.Publisher('/speak/goal', maryttsActionGoal)
		

			#self.command = maryttsActionGoal() 
			#self.command.goal.text=scriptLine[randrange(0, 26)]
			#self.pub.publish(self.command)

			marySpeak.wait_for_server() 	# establish TCP
			marygoal = maryttsGoal()		# Define action
			script = ""
			script = scriptLine[randrange(0, 26)] # for random time
			marygoal.text = script

			# Call Marys Voice
			marySpeak.send_goal(marygoal)

			# Hang for mary to respond
			marySpeak.wait_for_result(rospy.Duration.from_sec(0.0))

			rospy.sleep(5)					
			if time.time() - startTime > goal.mary_seconds:
				myBool = True
					#monitor person finder and engage for returning finish command 
					#if round((time.time() - startTime)*1000)
		
		print "_ CLOSING COMUNICATION WITH SERVER _"				
		self.server.set_succeeded()


if __name__ == '__main__':
	rospy.init_node('patroller')
	server = PatrollerServer()
	rospy.spin()
