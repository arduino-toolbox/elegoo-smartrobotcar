/*
   Main.h

    Created on: 14.10.2017
        Author: RalphG
*/

#include "Main.h"

Framework framework;
Car car;

void setup(void)
{
  framework.setup();
  car.setup();
}

void loop()
{
  framework.blink(100);
 
  /* car.selftest(); */
  
  car.drive_auto();

}
