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
// LeftClaw             motor         4               
// RightClaw            motor         5               
// Roller1R             motor         6               
// Roller2L             motor         7               
// Roller2R             motor         8               
// VisionSensor         vision        20              
// Roller1L             motor         12              
// Drivetrain           drivetrain    1, 2, 16        
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
const int clawspeed = 100;
const int rolspeed = 100;

// A global instance of competition
competition Competition;

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  //Initializing Motor
  LeftClaw.setVelocity(0,percent);
  RightClaw.setVelocity(0,percent);
  Roller1L.setVelocity(0,percent);
  Roller1R.setVelocity(0,percent);
  Roller2R.setVelocity(0,percent);
  Roller2L.setVelocity(0,percent);
  // Start spin
  LeftClaw.spin(forward);
  RightClaw.spin(forward);
  Roller1L.spin(forward);
  Roller1R.spin(forward);
  Roller2R.setStopping(hold);
  Roller2L.setStopping(hold);
  //-------END--------------------------------
  Roller2R.spin(forward);
  Roller2L.spin(forward);
  Roller2L.setVelocity(-rolspeed, percent);
  Roller2R.setVelocity(-rolspeed, percent);
  wait(200,msec);
  Roller2L.setVelocity(0, percent);
  Roller2R.setVelocity(0, percent);
  Drivetrain.setDriveVelocity(80, percent);
  Drivetrain.driveFor(forward, 550, mm);
  Drivetrain.setTurnVelocity(80, percent);
  Drivetrain.turnFor(left, 135, degrees);
  /*while(true){//adjust to the corner
    VisionSensor.takeSnapshot(VisionSensor__REDBALL);//VisionSensor__BLUEBALL
    if(VisionSensor.objectCount>0){
      if(VisionSensor.objects[0].centerX>200){
        Drivetrain.setTurnVelocity(50,percent);
        Drivetrain.turn(right);//turnRight
      }else if(VisionSensor.objects[0].centerX<160){
        Drivetrain.setTurnVelocity(50,percent);
        Drivetrain.turn(left);//turnLeft
      }else{
        Drivetrain.setTurnVelocity(0,percent);//Stop
        break;
      }
    }
  }*/
  LeftClaw.setVelocity(-clawspeed,percent);
  RightClaw.setVelocity(-clawspeed,percent);
  Drivetrain.driveFor(forward, 780, mm);
  Drivetrain.drive(forward);
  wait(500,msec);
  Drivetrain.stop();
  Roller1L.setVelocity(rolspeed,percent);
  Roller1R.setVelocity(rolspeed,percent);
  Roller2R.setVelocity(rolspeed,percent);
  Roller2L.setVelocity(rolspeed,percent);
  wait(2,sec);
  Roller1L.setVelocity(0,percent);
  Roller1R.setVelocity(0,percent);
  Roller2R.setVelocity(0,percent);
  Roller2L.setVelocity(0,percent);
  LeftClaw.setVelocity(0,percent);
  RightClaw.setVelocity(0,percent);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  // Initializing Motor
  LeftClaw.setVelocity(0,percent);
  RightClaw.setVelocity(0,percent);
  Roller1L.setVelocity(0,percent);
  Roller1R.setVelocity(0,percent);
  Roller2R.setVelocity(0,percent);
  Roller2L.setVelocity(0,percent);
  Drivetrain.setStopping(coast);
  // Start spin
  LeftClaw.spin(forward);
  RightClaw.spin(forward);
  Roller1L.spin(forward);
  Roller1R.spin(forward);
  Roller2R.spin(forward);
  Roller2L.spin(forward);
  // ...........................................
  while(true){
    // Adjustment
    if(Controller1.ButtonLeft.pressing()==1){
      Drivetrain.setTurnVelocity(25,percent);
      Drivetrain.turn(left);
    }else if(Controller1.ButtonRight.pressing()==1){
      Drivetrain.setTurnVelocity(25,percent);
      Drivetrain.turn(right);
    }else{
      Drivetrain.setTurnVelocity(0,percent);
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
    }
    // Roller event
    if(Controller1.ButtonR1.pressing()==1){
      Roller1L.setVelocity(rolspeed,percent);
      Roller1R.setVelocity(rolspeed,percent);
      Roller2R.setVelocity(rolspeed,percent);
      Roller2L.setVelocity(rolspeed,percent);
    }else if(Controller1.ButtonL1.pressing()==1){
      Roller1L.setVelocity(-rolspeed,percent);
      Roller1R.setVelocity(-rolspeed,percent);
      Roller2R.setVelocity(-rolspeed,percent);
      Roller2L.setVelocity(-rolspeed,percent);
    }else if(Controller1.ButtonX.pressing()==1){
      Roller1L.setVelocity(rolspeed,percent);
      Roller1R.setVelocity(rolspeed,percent);
    }else if(Controller1.ButtonY.pressing()==1){
      Roller1L.setVelocity(-rolspeed,percent);
      Roller1R.setVelocity(-rolspeed,percent);
    }else if(Controller1.ButtonA.pressing()==1){
      Roller2R.setVelocity(rolspeed,percent);
      Roller2L.setVelocity(rolspeed,percent);
    }else if(Controller1.ButtonB.pressing()==1){
      Roller2R.setVelocity(-rolspeed,percent);
      Roller2L.setVelocity(-rolspeed,percent);
    }else{
      Roller1L.setVelocity(0,percent);
      Roller1R.setVelocity(0,percent);
      Roller2R.setVelocity(0,percent);
      Roller2L.setVelocity(0,percent);
    }
    // ........................................................................
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
// ............................................................
// Main will set up the competition functions and callbacks.
// ............................................................
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  vexcodeInit();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
