/*
   Framework.cpp

    Created on: 14.10.2017
        Author: RalphG
*/

#include <Framework.h>

Framework::Framework()
{
	pinMode(LED_BUILTIN, OUTPUT);

	PIN = 0;
}

Framework::~Framework()
{
	// Destructor stub
}

int Framework::setup()
{
	Serial.begin(9600);
	Serial.println("Framework::setup");

	return 0;
}

int Framework::println(const char *line)
{
	Serial.println(line);

	return 0;
}

int Framework::print(const char *line)
{
	Serial.print(line);

	return 0;
}
int Framework::print(int line)
{
	Serial.print(line);

	return 0;
}
int Framework::print(long line)
{
	Serial.print(line);

	return 0;
}
int Framework::setstate(int state, int seconds) {
	digitalWrite(LED_BUILTIN, state);
	delay(seconds);

	return 0;
}

int Framework::blink(int seconds)
{
	Serial.println("Framework::blink");

	setstate(seconds, HIGH);
	setstate(seconds, LOW);
	
	return 0;
}
int Framework::changestate(int seconds)
{
	Serial.println("Framework::changestate");

	state = !state;
	return setstate(seconds, state);
}