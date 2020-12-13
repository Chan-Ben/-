/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 3, 4, 5   
// RollerFront          motor         10              
// RollerDown           motor         7               
// LeftClaw             motor         8               
// RightClaw            motor         9               
// VisionSensor         vision        6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
competition Competition;
const int clawspeed = 80;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  RollerDown.setVelocity(0, percent);
  RollerFront.setVelocity(0, percent);
  LeftClaw.setVelocity(0,percent);
  RightClaw.setVelocity(0, percent);
  RollerFront.spin(forward);
  RollerDown.spin(forward);
  LeftClaw.spin(forward);
  RightClaw.spin(forward);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {
  
}

void usercontrol(void) {
  while (true) {
    //--------Claw event----------------------
    if (Controller1.ButtonL2.pressing()==1) {
      LeftClaw.setVelocity(-clawspeed,percent);
      RightClaw.setVelocity(-clawspeed,percent);
    } else if (Controller1.ButtonR2.pressing()==1) {
      LeftClaw.setVelocity(clawspeed,percent);
      RightClaw.setVelocity(clawspeed,percent);
    } else {
      LeftClaw.setVelocity(0,percent);
      RightClaw.setVelocity(0,percent);//stop
    }
    // ------Roller event entirely------------------
    if (Controller1.ButtonL1.pressing()==1) {
      RollerFront.setVelocity(-100,percent);
      RollerDown.setVelocity(-100,percent);
    } else if (Controller1.ButtonR1.pressing()==1) {
      RollerFront.setVelocity(100,percent);
      RollerDown.setVelocity(100,percent);
    } else if (Controller1.ButtonX.pressing()==1) {
      RollerFront.setVelocity(100,percent);
    } else if (Controller1.ButtonY.pressing()==1) {
      RollerFront.setVelocity(-100,percent);
    } else if (Controller1.ButtonA.pressing()==1) {
      RollerDown.setVelocity(100,percent);
    } else if (Controller1.ButtonB.pressing()==1) {
      RollerDown.setVelocity(-100,percent);
    } else {
      RollerFront.setVelocity(0,percent);
      RollerDown.setVelocity(0,percent);
    }
    //------END------------
    wait(20, msec);
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
