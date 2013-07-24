#!/usr/bin/env python

import rospy

# from the rvis user clicked area
from geometry_msgs.msg import PointStamped

class SetUpWayPoints():
        "A class to listen to the RVIS input"

	# Empty String for IO
	transcript = ''
       
	
        def __init__(self):
                rospy.init_node('set_up_waypoints')
                rospy.Subscriber("/clicked_point", PointStamped, self.callback)
                rospy.logdebug(rospy.get_name() + " setting up")
		print "On RViz, use the 'Publish Point' tool to identify an area."

        def callback(self, point):
		# Assign a name to the new point
		user_input = raw_input("Point recorded: x:%.3f, y:%.3f, z:%.3f): \nTo remove point type 'del'\nEnter Point Name:" % (point.point.x, point.point.y, point.point.z)) or 'DefaultPoint'
		# Bypass loop if 'del'
		if user_input != 'del':
			if self.transcript == '':
				self.transcript = "%s,%.10f,%.10f,%.10f" % (user_input, point.point.x, point.point.y, point.point.z)
			else: 
				self.transcript = "%s\n%s,%.10f,%.10f,%.10f" % (self.transcript, user_input, point.point.x, point.point.y, point.point.z)
	
			try:
				self.fo = open("waypoints.cvs", "wb")
				self.fo.write(self.transcript);
				self.fo.close()
				print "CVS updated"
	
			except IOError as e:
   				print "Failed to update CVS file ({0}): {1}\n".format(e.errno, e.strerror)

		else:
			print 'Publish a new point.'
                

if __name__ == '__main__':
	userConfig = SetUpWayPoints()
	rospy.spin()


	
