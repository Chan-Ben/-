using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LeftMotor;
extern motor RightMotor;
extern motor Elevator;
extern motor Elevator2;
extern motor LeftClaw;
extern motor RightClaw;
extern motor Elevator3;
extern motor Elevator4;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );