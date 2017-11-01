/*
   Car.cpp

    Created on: 14.10.2017
        Author: RalphG
*/

#include "Car.h"

extern "C" {
	#include <Arduino.h>
}

Car::Car()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

Car::~Car()
{
	// Destructor stub
}

int Car::blink(int seconds)
{
	Serial.println("LED.blink");

	digitalWrite(LED_BUILTIN, HIGH);
	delay(seconds);
	digitalWrite(LED_BUILTIN, LOW);
	delay(seconds);

	return 0;
}

int Car::setup()
{
	return 0;
}

int Car::println(char *line)
{
	return 0;
}
