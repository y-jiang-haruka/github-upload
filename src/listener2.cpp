#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials2/Hello.h"
void chatterCallback(const beginner_tutorials2::Hello::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s %f %f %f]", msg->hello.c_str(),
	msg->pos.x, msg->pos.y, msg->pos.z);
}
int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener2");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("chatter2", 1000, chatterCallback);
	ros::spin();
	return 0;
}
