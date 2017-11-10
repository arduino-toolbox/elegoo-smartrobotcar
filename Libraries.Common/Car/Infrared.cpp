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
	pinMode(LED_BUILTIN, OUTPUT);
}
Infrared::~Infrared()
{
	// Destructor stub
}

int Infrared::setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	irrecv.enableIRIn(); // Start receiving

	return 0;
}
int Infrared::println(const char *line)
{
	return 0;
}

int Infrared::respondtosignal()
{
	int val;

	if (irrecv.decode(&results))
	{
		val = results.value;

		Serial.print("val=");
		Serial.println(val);

		irrecv.resume();
		delay(150);
		
		if (val == L)
		{
			framework.changestate();
		}
	}

	return 0;
}

int Infrared::selftest()
{
	return 0;
}