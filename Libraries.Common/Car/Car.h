/*
   LED.h

    Created on: 14.10.2017
        Author: RalphG
*/

#ifndef __CAR_H_
#define __CAR_H_

#include <Framework.h>

enum Side      { left, right, both };
enum Direction { forward = HIGH, back = LOW } ;

class Car
{
  public:
  public:
    Car();
    virtual ~Car();

    int setup();

    int move(Side side, Direction direction, int speed = 100, int seconds = 100);

    int move(int leftBack, int leftForward, int rightBack, int rightForward, char *direction, int seconds = 1000);
    int stop(int seconds = 500);

    int blink(int seconds);
    int println(char line[]);

    int drive_forward(int seconds = 1000);
    int drive_back(int seconds = 1000);

    int turn_right(int seconds = 1000);
    int turn_left(int seconds = 1000);

    int drive_auto();

    int selftest();

  private:
    //  VARIABLES
    Framework framework;

    //  CONSTANTS
};

#endif /* Car_H_ */
