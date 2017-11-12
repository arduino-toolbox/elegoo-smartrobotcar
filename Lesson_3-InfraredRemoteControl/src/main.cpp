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
	car.set_default_seconds(250);
	car.set_default_speed(100);

	framework.println("Main");
}

void loop()
{
	car.drive_remotecontrol();
}