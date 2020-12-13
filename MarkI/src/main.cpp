/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Chanben                                                   */
/*    Created:      Mon Dec 02 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         5               
// RightMotor           motor         6               
// LClaw1               motor         1               
// RClaw1               motor         2               
// Locker               motor         7               
// Rocket               motor         17              
// Controller1          controller                    
// LClaw2               motor         3               
// RClaw2               motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

const int locker_degree = 210;
int locker_status = 0;// 1: open; 0: closed
const int deadband = 10;
  // Deadband stops the motors when Axis values are close to zero.
int UserControl(void);
void OpenLocker(){if(locker_status) return; else{Locker.spinFor(locker_degree, degrees);locker_status = !locker_status;}}
void CloseLocker(){if(!locker_status) return; else{Locker.spinFor(-locker_degree, degrees);locker_status = !locker_status;}}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  Brain.Screen.print("Running program...");
  vexcodeInit();
  UserControl();
}

int UserControl(void) {
  // Start
  LeftMotor.setVelocity(0,percent);
  RightMotor.setVelocity(0,percent);
  Rocket.setVelocity(0,percent);
  LClaw1.setVelocity(0, percent);
  RClaw1.setVelocity(0, percent);
  LClaw2.setVelocity(0, percent);
  RClaw2.setVelocity(0, percent);
  Rocket.spin(forward);
  LeftMotor.spin(forward);
  RightMotor.spin(forward);
  LClaw1.spin(forward);
  RClaw1.spin(forward);
  LClaw2.spin(forward);
  RClaw2.spin(forward);
  while (true) {
    // --------Motion event---------
    // Get the velocity percentage of the left motor. (Axis3 + Axis4)
    int leftMotorSpeed =
        Controller1.Axis3.position() + Controller1.Axis1.position();
    // Get the velocity percentage of the right motor. (Axis3 - Axis4)
    int rightMotorSpeed =
        Controller1.Axis3.position() - Controller1.Axis1.position();
    if (abs(leftMotorSpeed) < deadband) {
      LeftMotor.setVelocity(0, percent);
    } else {
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    if (abs(rightMotorSpeed) < deadband) {
      RightMotor.setVelocity(0, percent);
    } else {
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }
    // ---------Rocket event-------
    if(Controller1.ButtonUp.pressing()==1) {
      Rocket.setVelocity(30,percent);
    }else if(Controller1.ButtonX.pressing()==1){
      Rocket.setVelocity(3,percent);
    }else if(Controller1.ButtonDown.pressing()==1){
      Rocket.setVelocity(-25,percent);
    }else {
      Rocket.setVelocity(0,percent);
      Rocket.setStopping(hold);
    }
    // End
    // ---------Claw event--------
    if(Controller1.ButtonR1.pressing()==1){
      LClaw1.setVelocity(100,percent);
      RClaw1.setVelocity(100,percent);
    }else if(Controller1.ButtonR2.pressing()==1){
      LClaw1.setVelocity(-10,percent);
      RClaw1.setVelocity(-10,percent);
    }else {
      LClaw1.setVelocity(0,percent);
      RClaw1.setVelocity(0,percent);
    }
    if(Controller1.ButtonL1.pressing()==1){
      LClaw2.setVelocity(80,percent);
      RClaw2.setVelocity(80,percent);
    }else if(Controller1.ButtonL2.pressing()==1){
      LClaw2.setVelocity(-10,percent);
      RClaw2.setVelocity(-10,percent);
    }else{
      LClaw2.setVelocity(0,percent);
      RClaw2.setVelocity(0,percent);
    }
    // End

    // ---------Locker event-------
    if(Controller1.ButtonA.pressing()==1){
      OpenLocker();
    }else if(Controller1.ButtonB.pressing()==1){
      CloseLocker();
    }
    // End
  }
  return 0;
}