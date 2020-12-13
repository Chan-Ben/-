using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor LeftClaw;
extern motor RightClaw;
extern motor Roller1R;
extern motor Roller2L;
extern motor Roller2R;
extern signature VisionSensor__BLUEBALL;
extern signature VisionSensor__REDBALL;
extern signature VisionSensor__SIG_3;
extern signature VisionSensor__SIG_4;
extern signature VisionSensor__SIG_5;
extern signature VisionSensor__SIG_6;
extern signature VisionSensor__SIG_7;
extern vision VisionSensor;
extern motor Roller1L;
extern smartdrive Drivetrain;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );