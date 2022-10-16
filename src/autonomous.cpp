#include "vex.h"
#include "autonomous.h"
using namespace vex;

void SetTimeout(int seconds)
{
  AllLeft.setTimeout(seconds, sec);
  AllRight.setTimeout(seconds, sec);
}

void moveForward(int dist, int speed, int timeout)
{
  SetTimeout(timeout);
  AllLeft.spinFor(forward, double (dist/(8.225*M_PI)), rev, double (speed), rpm, false);
  AllRight.spinFor(forward, double (dist/(8.225*M_PI)), rev, double (speed), rpm, true);
  SetTimeout(0);
}

void TurninPlace(int dist, int speed, int timeout) //a postitve number will turn right, a negative number will turn left//
{
  SetTimeout(timeout);
  AllLeft.spinFor(reverse, double (dist/(8.225*M_PI)), rev, double (speed), rpm, false);
  AllRight.spinFor(forward, double (dist/(8.225*M_PI)), rev, double (speed), rpm, true);
  SetTimeout(0);

}

void movestraightf(int speed)
{
  AllLeft.spin(reverse, speed, pct);
  AllRight.spin(forward, speed, pct);
  
  m3.resetPosition();
  m5.resetPosition();

  while (1)
  {

    
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