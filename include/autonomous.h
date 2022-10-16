#ifndef AUTONOMOUS
#define AUTONOMOUS

void SetTimeout(int);
void moveForward(int dist, int speed, int seconds); //(int dist, int speed, int timeout(seconds))//
void TurninPlace(int dist, int speed, int seconds); //(int dist, int speed, int timeout(seconds))//
void IntakeSpitAuto(int dist, int speed, int timeout);
void movestraightf(int);
#endif