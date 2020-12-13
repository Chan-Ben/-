using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftMotor;
extern motor RightMotor;
extern motor LClaw1;
extern motor RClaw1;
extern motor Locker;
extern motor Rocket;
extern controller Controller1;
extern motor LClaw2;
extern motor RClaw2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );