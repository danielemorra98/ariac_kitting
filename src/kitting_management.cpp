#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose.h"
#include "../include/ariac_kitting/utils.h"
#include "sensor_msgs/LaserScan.h"


class kitting_manager
{
	public:

        // ACHTUNG: it's right only if we have only one kind of object that spawn on the belt
		void position_obj_callback(const sensor_msgs::LaserScan::ConstPtr& msg)
		{
            float* range_laser = msg->ranges;
            if (laser.min_height != LASER_INIT) {laser.search_min(range_laser)}
            else {

                //update the new ranges
                for (int i = 0; i < laser.laser_width; i++)
                {
                    if (range_laser[i] < laser.actual_iteration) {laser.actual_iteration = range_laser[i];}
                }

                //confront the previous value with the new found and update min_height if it's less
                if (laser.actual_iteration < laser.min_height) {laser.min_height = laser.actual_iteration}              
            }
			// ROS_INFO("I heard: [%d], [%d], [%d]", msg->a, msg->b, msg->c);
		}


    private:
        Laser laser;
}


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
        

        // To do: transform from local to global coordinates
        //
        //
        //
        //
        //
        //
		geometry_msgs::Pose global_position_obj;
		msg.a = 1;
		msg.b = 10;
		msg.c = 100;

		position_object_pub.publish(global_position_obj);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
