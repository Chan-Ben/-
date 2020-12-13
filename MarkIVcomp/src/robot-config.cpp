#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor leftMotorA = motor(PORT1, ratio18_1, false);
motor leftMotorB = motor(PORT2, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT3, ratio18_1, true);
motor rightMotorB = motor(PORT4, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
inertial TurnGyroSmart = inertial(PORT5);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, TurnGyroSmart, 319.19, 320, 40, mm, 1);
motor RollerFront = motor(PORT10, ratio18_1, false);
motor RollerDown = motor(PORT7, ratio18_1, false);
motor LeftClaw = motor(PORT8, ratio36_1, true);
motor RightClaw = motor(PORT9, ratio36_1, false);
/*vex-vision-config:begin*/
signature VisionSensor__BLUEBALL = signature (1, -2647, -1909, -2278, 7865, 10013, 8939, 3, 0);
signature VisionSensor__REDBALL = signature (2, 4509, 6241, 5375, 615, 1271, 943, 2.5, 0);
vision VisionSensor = vision (PORT6, 50);
/*vex-vision-config:end*/

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int drivetrainLeftSideSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor next time the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      if (Controller1.ButtonLeft.pressing()==1) {
        leftMotorA.setVelocity(-70, percent);
        leftMotorB.setVelocity(70, percent);
        rightMotorA.setVelocity(70, percent);
        rightMotorB.setVelocity(-70, percent);
        LeftDriveSmart.spin(forward);
        RightDriveSmart.spin(forward);
      } else if (Controller1.ButtonRight.pressing()==1) {
        leftMotorA.setVelocity(70, percent);
        leftMotorB.setVelocity(-70, percent);
        rightMotorA.setVelocity(-70, percent);
        rightMotorB.setVelocity(70, percent);
        LeftDriveSmart.spin(forward);
        RightDriveSmart.spin(forward);
      } else {
        leftMotorA.setVelocity(0, percent);
        leftMotorB.setVelocity(0, percent);
        rightMotorA.setVelocity(0, percent);
        rightMotorB.setVelocity(0, percent);
      }
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
      
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain gyro
  wait(200, msec);
  TurnGyroSmart.calibrate();
  Brain.Screen.print("Calibrating Gyro for Drivetrain");
  // wait for the gyro calibration process to finish
  while (TurnGyroSmart.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}