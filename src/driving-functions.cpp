#include "driving-functions.h"
#include "vex.h"
#include "robot-config.h"
using namespace vex;

void tankdrive()
{
  if (abs(controller1.Axis2.value()) > 5 || abs(controller1.Axis3.value()) > 5)
  {
    AllRight.spin(forward, (controller1.Axis3.value()), pct);
    AllLeft.spin(reverse, (controller1.Axis2.value()), pct); 
  }
  else
  {
    AllRight.stop();
    AllLeft.stop();
  } 
}