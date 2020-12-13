#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMotor = motor(PORT14, ratio18_1, false);
motor RightMotor = motor(PORT13, ratio18_1, false);
motor Elevator = motor(PORT7, ratio36_1, true);
motor Elevator2 = motor(PORT8, ratio36_1, false);
motor LeftClaw = motor(PORT11, ratio18_1, true);
motor RightClaw = motor(PORT12, ratio18_1, false);
motor Elevator3 = motor(PORT20, ratio36_1, false);
motor Elevator4 = motor(PORT10, ratio36_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}