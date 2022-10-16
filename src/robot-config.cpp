#include "vex.h"
#include "robot-config.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller controller1(primary);

// left motor group
motor m1 (PORT4, ratio18_1, true);
motor m2 (PORT5, ratio18_1, true);
motor m3 (PORT6, ratio18_1, false);


// right motor group
motor m4 (PORT1, ratio18_1, true);
motor m5 (PORT2, ratio18_1, true);
motor m6 (PORT3, ratio18_1, false);

// motor grouping

motor_group AllRight (m4, m5, m6);
motor_group AllLeft (m1, m2, m3);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}