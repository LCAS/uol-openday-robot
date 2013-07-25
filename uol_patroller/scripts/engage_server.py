#! /usr/bin/env python

import roslib; roslib.load_manifest('uol_patroller'); roslib.load_manifest('ros_mary_tts');
import rospy
import actionlib
import tf
import time
import math 

from random import randrange, randint

from geometry_msgs.msg import Twist
# Import for rotate
from nav_msgs import *

#anything ross mary-y
from ros_mary_tts.srv import *
from ros_mary_tts.msg import *

from uol_openday_common.msg import *
from uol_patroller.msg import *


marySpeak = actionlib.SimpleActionClient('speak', maryttsAction)
findPeople = actionlib.SimpleActionClient('find_people', Find_peopleAction)
#pub = rospy.Publisher('/odom', String)



class EngageServer:

	

	def __init__(self, speech_name):
		self.server = actionlib.SimpleActionServer('uol_patroller/engage', patrolAction, self.execute, False)
		self.server.start()
		rospy.Subscriber("/find_people/feedback", Find_peopleActionFeedback, self.callback) 
		self.pub = rospy.Publisher('/cmd_vel', Twist)
		self.file_name = speech_name


	def callback(self, fb): 
		# spin the base
		# turning speed
		rospy.loginfo("Looking for people.")
		twist = Twist()
		twist.angular.z = math.atan2(fb.feedback.targetPoint.y,fb.feedback.targetPoint.x)*0.5
		self.pub.publish(twist)

	def execute(self, goal):
		self.count = 5
		# Call Headspin Service 360
		
		myBool = False			
		startTime = time.time()
		
		findPeople.wait_for_server() 	# establish TCP
		find_goal = Find_peopleGoal()		# Define action
		find_goal.time = goal.find_seconds

		# Call Marys Voice
		findPeople.send_goal(find_goal)
		
		rospy.logdebug(rospy.get_name() + " setting up")
		

		File = open(self.file_name)
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
			#if time.time() - startTime > goal.mary_seconds:
			myBool = True
					#monitor person finder and engage for returning finish command 
					#if round((time.time() - startTime)*1000)
		
		print "_ CLOSING COMUNICATION WITH SERVER _"				
		self.server.set_succeeded()


def main():
	rospy.init_node('engage_server')
	if len(sys.argv)<2:
		rospy.logerr("No waypoints file given. Use rosrun waypoint_patroller patroller.py [path to csv waypoints file]. If you are using a launch file, see launch/patroller.launch for an example.")
		
	speech_name=sys.argv[1]
	server = EngageServer(speech_name)
	rospy.spin()

if __name__ == '__main__':
	main()
