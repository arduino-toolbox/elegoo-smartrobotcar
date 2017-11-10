/*
   Infrared.cpp

    Created on: 14.10.2017
        Author: RalphG
*/

#include <Infrared.h>

int PIN = 12;
IRrecv irrecv(PIN); //initialization

Infrared::Infrared()
{
	framework.println("Infrared::Infrared()");

	pinMode(LED_BUILTIN, OUTPUT);
}
Infrared::~Infrared()
{
	framework.println("Infrared::~Infrared()");
}

int Infrared::setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	irrecv.enableIRIn();

	framework.println("Infrared::setup");

	return 0;
}
int Infrared::println(const char *line)
{
	return 0;
}

int Infrared::respondtosignal()
{
	int val;

	rc=irrecv.decode(&results);

	if (rc)
	{
		val = results.value;

		Serial.print("rc=");
		Serial.print(rc);
		Serial.print(" val=");
		Serial.println(val);

		irrecv.resume();
		delay(100);
		
		if (val == L)
		{
			framework.println("Infrared::respondtosignal: changestate");
			framework.changestate();
		}
	}

	return 0;
}

int Infrared::selftest()
{
	return 0;
}