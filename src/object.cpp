#include "ros/ros.h"
#include "std_msgs/String.h"
#include "include/utils.h"
#include "geometry_msgs/Pose.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "position_object");
	ros::NodeHandle n_pub;
    ros::NodeHandle n_sub;
	ros::Publisher position_object_pub = n_pub.advertise<geometry_msgs::Pose>("/ariac/laser_profiler_0", 1000);
	ros::Subscriber position_object_sub = n_sub.subscribe("/ariac/laser_profiler_0", 1000, position_obj_callback);
    ros::Rate loop_rate(10);
	while (ros::ok())
	{
		example_pkg::example_msg_1 msg;
		msg.a = 1;
		msg.b = 10;
		msg.c = 100;

		//ROS_INFO("%d",msg.a);
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
