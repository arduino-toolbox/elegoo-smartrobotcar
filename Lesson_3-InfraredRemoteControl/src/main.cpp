/*
   Main.h

    Created on: 14.10.2017
        Author: RalphG
*/

#include "Main.h"

Framework framework;
Car car;
Bluetooth bluetooth;
Infrared infrared;

void setup(void)
{
	framework.setup();
	car.setup();

	infrared.setup();

	framework.println("Main");
}

void loop()
{
	infrared.dump();
}
