#include "teleop_twist.h"

inline float max(float a, float b) { return a > b ? a : b; }
inline float min(float a, float b) { return a < b ? a : b; }

bool needs_takeoff = false;	//rujian July 30
bool needs_land = false;	//rujian July 30
bool needs_reset = false;
bool reset_state = false;	//false: normal flight; true: emergency.
int do_not_hover = 1;		//rujian July 27
geometry_msgs::Twist cmd_vel;

int cam_state=0; // 0 for forward and 2 for vertical, change to enum later // rujian aug 8

/*
// ros service callback function for toggling Cam
bool toggleCamCallback(std_srvs::Empty::Request& request, std_srvs::Empty::Response& response)
{
  if (cam_state == 0) // toggle to 2*, the vertical camera  //rujian aug 8
    {
      cam_state = 1;
	//cam_state++;

#ifdef _USING_SDK_1_7_
      ARDRONE_TOOL_CONFIGURATION_ADDEVENT (video_channel, &cam_state, NULL);
      fprintf(stderr, "\nToggling aaaaaa.%d\n", cam_state);
#else
      ardrone_at_set_toy_configuration("video:video_channel","1");
#endif

      fprintf(stderr, "\nToggling from frontal camera to vertical camera.\n");
    }
  else if (cam_state == 1) // toggle to the forward camera // rujian aug 8
    {
      cam_state = 0;

#ifdef _USING_SDK_1_7_
      ARDRONE_TOOL_CONFIGURATION_ADDEVENT (video_channel, &cam_state, NULL);
#else
      ardrone_at_set_toy_configuration("video:video_channel","1");
#endif

      fprintf(stderr, "\nToggling from vertical camera to frontal camera.\n");      
    }
  return true;
}
*/ //rujian aug 8


// Older rostopic callback function for toggling Cam
void toggleCamCallback(const std_msgs::Empty &msg)
{
  if (cam_state == 0) // toggle to 1, the vertical camera
    {
      cam_state = 1;	//rujian aug 30
      ARDRONE_TOOL_CONFIGURATION_ADDEVENT (video_channel, &cam_state, NULL);
      //ardrone_at_set_toy_configuration("video:video_channel","1");
      fprintf(stderr, "\nToggling from frontal camera to vertical camera.\n");
    }
  else if (cam_state == 1) // toggle to the forward camera
    {
      cam_state = 0;
      ARDRONE_TOOL_CONFIGURATION_ADDEVENT (video_channel, &cam_state, NULL);
      //ardrone_at_set_toy_configuration("video:video_channel","0");
      fprintf(stderr, "\nToggling from vertical camera to frontal camera.\n");      
    }
}	//rujian aug 8

//callback function for selecting camera mode explicitly with integers		//rujian sept 2
void camselectCallback(const std_msgs::UInt8 &msg)
{
	cam_state = msg.data;
	ARDRONE_TOOL_CONFIGURATION_ADDEVENT (video_channel, &cam_state, NULL);
	fprintf(stderr, "camselect callback - setting cam_state to %d.\n", cam_state);
}	//rujian sept 2


void cmdVelCallback(const geometry_msgs::TwistConstPtr &msg)
{
	do_not_hover = 1;
	const float maxHorizontalSpeed = 0.12; // use 0.1f for testing and 1 for the real thing
	cmd_vel.linear.x  = max(min(-msg->linear.x, maxHorizontalSpeed), -maxHorizontalSpeed);
	cmd_vel.linear.y  = max(min(-msg->linear.y, maxHorizontalSpeed), -maxHorizontalSpeed);
	cmd_vel.linear.z  = max(min(msg->linear.z, 1), -1);
	cmd_vel.angular.x = 0;
	cmd_vel.angular.y = 0;
	cmd_vel.angular.z = max(min(-msg->angular.z, 1), -1);
}

void landCallback(const std_msgs::Empty &msg)
{
	do_not_hover = 0;
	needs_land = true;
}

void resetCallback(const std_msgs::Empty &msg)
{
	do_not_hover = 1;
	needs_reset = true;
}

void takeoffCallback(const std_msgs::Empty &msg)
{
	do_not_hover = 0;
	needs_takeoff = true;
}

void hoverCallback(const std_msgs::Empty &msg)
//rujian July 27
{
	do_not_hover = 0;
	cmd_vel.linear.x  = 0;
	cmd_vel.linear.y  = 0;
	cmd_vel.linear.z  = 0;
	cmd_vel.angular.x = 0;
	cmd_vel.angular.y = 0;
	cmd_vel.angular.z = 0;
}

C_RESULT open_teleop(void)
{
	return C_OK;
}

C_RESULT update_teleop(void)
{
	// This function *toggles* the emergency state, so we only want to toggle the emergency
	// state when we are in the emergency state (because we want to get out of it).
	//fprintf(stderr, "%d\n", int(needs_reset));
	if (needs_reset)
	{
	//	fprintf(stderr, "needs_reset true\n");
		ardrone_tool_set_ui_pad_select(needs_reset);
		needs_reset = false;
	//	fprintf(stderr, "needs_reset false\n");
	}

	// ******dep****** This function sets whether or not the robot should be flying.  If it is flying and you
	// ******dep****** send 0, the robot will slow down the motors and slowly descend to the floor.
	//rujian July 30
	if (needs_takeoff)
	{
		ardrone_tool_set_ui_pad_start(true);
		needs_takeoff = false;
	}

	if (needs_land)
	{
		ardrone_tool_set_ui_pad_start(false);
		needs_land = false;
	}

	float left_right = cmd_vel.linear.y;
	float front_back = cmd_vel.linear.x;
	float up_down = cmd_vel.linear.z;
	float turn = cmd_vel.angular.z;

	ardrone_at_set_progress_cmd(do_not_hover, left_right, front_back, up_down, turn);	//rujian July27
	return C_OK;
}

C_RESULT close_teleop(void)
{
	return C_OK;
}

input_device_t teleop = {
	"Teleop",
	open_teleop,
	update_teleop,
	close_teleop
};

