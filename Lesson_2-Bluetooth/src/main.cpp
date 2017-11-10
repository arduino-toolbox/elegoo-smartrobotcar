/*
   Main.h

    Created on: 14.10.2017
        Author: RalphG
*/

#include "Main.h"

Framework framework;
Car car;
Bluetooth bluetooth;

void setup(void)
{
	framework.setup();
	car.setup();
}

void loop()
{
	bluetooth.blink(100);
}
