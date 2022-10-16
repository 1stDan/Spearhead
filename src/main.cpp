/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Leo Zubiate                                               */
/*    Created:      Fri Oct 07 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "driving-functions.h"
#include "robot-config.h"
#include "routines.h"
using namespace vex;

competition Competition;

void usercontrol()
{
  int m1speed;
  m1speed = m1.velocity(pct);

  while (1)
  {
    tankdrive();


  if (controller1.ButtonX.pressing())
    {
      int speed = 80;
      AllLeft.spin(reverse, speed, pct);
  AllRight.spin(forward, speed, pct);
  
  m3.resetPosition();
  m5.resetPosition();

    
  int motorLeft = -m3.position(degrees);
  int motorRight = m5.position(degrees);

  //printf("%d, %d \n" , motorLeft, motorRight);
  // wait (50, msec);
 // if (averagespeed >= 40)
 // {
  //  averagespeed = 40;
 // }

Brain.Screen.clearScreen();
Brain.Screen.clearLine();
Brain.Screen.print("%d, %d \n" , motorLeft, motorRight);


  int error = motorLeft - motorRight;
  float kp = 0.3;
  error = int (kp * error);
  if (error > speed) error = speed;


   else if (error < -speed) error = -speed;

   
    AllRight.spin(forward, speed + error, pct);
    AllLeft.spin(reverse, speed - error, pct);
  }
}
}

void Autonomous()
{
  while(1)
  {
  moveinbox();
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
   Competition.drivercontrol(usercontrol);
  Competition.autonomous(Autonomous);
}
