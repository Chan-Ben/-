/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       chenben                                                   */
/*    Created:      Sun Jul 05 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotor            motor         14              
// RightMotor           motor         13              
// Elevator             motor         7               
// Elevator2            motor         8               
// LeftClaw             motor         11              
// RightClaw            motor         12              
// Elevator3            motor         20              
// Elevator4            motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
const int deadband = 10;
const int clawspeed = 100;
const int elevspeed = 60;
int UserControl(void);

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  Brain.Screen.print("Running program...");
  vexcodeInit();
  UserControl();
}

int UserControl(void) {
  // Initializing motor
  LeftMotor.setVelocity(0, percent);
  RightMotor.setVelocity(0, percent);
  Elevator.setVelocity(0, percent);
  Elevator2.setVelocity(0, percent);
  Elevator3.setVelocity(0, percent);
  Elevator4.setVelocity(0, percent);
  LeftClaw.setVelocity(0, percent);
  RightClaw.setVelocity(0, percent);
  //Start spin
  LeftMotor.spin(forward);
  RightMotor.spin(forward);
  Elevator.spin(forward);
  Elevator2.spin(forward);
  Elevator3.spin(forward);
  Elevator4.spin(forward);
  LeftClaw.spin(forward);
  RightClaw.spin(forward);
  // int degree0 = Elevator.
  // Controller events
  while(true) {
    // Get the velocity percentage of the left motor.
    int leftMotorSpeed =
        Controller1.Axis1.position() + Controller1.Axis3.position();
    // Get the velocity percentage of the right motor.
    int rightMotorSpeed =
        Controller1.Axis1.position() - Controller1.Axis3.position();
    // Spin left
    if (abs(leftMotorSpeed) < deadband) {
      LeftMotor.setVelocity(0, percent);
    } else {
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }
    // Spin right
    if (abs(rightMotorSpeed) < deadband) {
      RightMotor.setVelocity(0, percent);
    } else {
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }
    // Up
    if(Controller1.ButtonX.pressing()==1){
      Elevator.setVelocity(elevspeed,percent);
      Elevator2.setVelocity(elevspeed,percent);
      Elevator3.setVelocity(elevspeed/7,percent);
      Elevator4.setVelocity(elevspeed/7,percent);
    } else if (Controller1.ButtonB.pressing()==1) {
      Elevator.setVelocity(-elevspeed,percent);
      Elevator2.setVelocity(-elevspeed,percent);
      Elevator3.setVelocity(-elevspeed/7-1,percent);
      Elevator4.setVelocity(-elevspeed/7-1,percent);
    } else {
      Elevator.setVelocity(0,percent);
      Elevator.setStopping(hold);
      Elevator2.setVelocity(0,percent);
      Elevator2.setStopping(hold);
      Elevator3.setVelocity(0,percent);
      Elevator3.setStopping(hold);
      Elevator4.setVelocity(0,percent);
      Elevator4.setStopping(hold);
    }
    // Claw event
    if(Controller1.ButtonL2.pressing()==1){
      LeftClaw.setVelocity(clawspeed,percent);
      RightClaw.setVelocity(clawspeed,percent);
    }else if(Controller1.ButtonR2.pressing()==1){
      LeftClaw.setVelocity(-clawspeed,percent);
      RightClaw.setVelocity(-clawspeed,percent);
    }else{
      LeftClaw.setVelocity(0,percent);
      RightClaw.setVelocity(0,percent);
      LeftClaw.setStopping(hold);
      RightClaw.setStopping(hold);
    }
  } //End while

  // End
}