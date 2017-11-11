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

	framework.println("Main");
}

void loop()
{
	car.drive_remotecontrol();
}
