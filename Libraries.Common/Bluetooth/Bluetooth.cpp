/*
   Bluetooth.cpp

    Created on: 14.10.2017
        Author: RalphG
*/

#include <Bluetooth.h>

Bluetooth::Bluetooth()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

Bluetooth::~Bluetooth()
{
	// Destructor stub
}

int Bluetooth::setup()
{
	pinMode(LED, OUTPUT);

	return 0;
}
int Bluetooth::blink(int seconds)
{
	Serial.println("LED.blink");

	getstr=Serial.read(); //The Bluetooth serial port to receive the data in the function
	Serial.println(getstr);

	if (getstr=='A') {
		state = !state;
		digitalWrite(LED, state);
	}

	return 0;
}

