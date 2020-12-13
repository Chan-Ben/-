#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotor = motor(PORT5, ratio18_1, false);
motor RightMotor = motor(PORT6, ratio18_1, true);
motor LClaw1 = motor(PORT1, ratio18_1, false);
motor RClaw1 = motor(PORT2, ratio18_1, true);
motor Locker = motor(PORT7, ratio18_1, false);
motor Rocket = motor(PORT17, ratio36_1, true);
controller Controller1 = controller(primary);
motor LClaw2 = motor(PORT3, ratio18_1, true);
motor RClaw2 = motor(PORT4, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}