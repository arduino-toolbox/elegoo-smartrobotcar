/*
   Car.cpp

    Created on: 14.10.2017
        Author: RalphG
*/

#include <Car.h>

/* Motor B */
int ENB = 5; /* black   */
int N3 = 6;  /* grey     */
int N4 = 7;  /* white    */

/* Motor A */
int ENA = 8; /* green   */
int N1 = 9;  /* blue     */
int N2 = 8;  /* voilettt */

Car::Car()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

Car::~Car()
{
	// Destructor stub
}

int Car::setup()
{
	pinMode(N1, OUTPUT);
	pinMode(N2, OUTPUT);
	pinMode(N3, OUTPUT);
	pinMode(N4, OUTPUT);

	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);

	return 0;
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
int Car::println(char line[])
{
	return 0;
}
int Car::move(Side side, Direction direction, int speed = 300, int seconds = 500)
{
	speed = direction == forward ? HIGH : LOW;

	framework.println("move");

	switch (side)
	{
	case left:
		digitalWrite(ENA + 1, speed);
		digitalWrite(ENA + 2, 1 - speed);
		break;
	case right:
		digitalWrite(ENB + 1, speed);
		digitalWrite(ENB + 2, 1 - speed);
		break;
	case both:
		digitalWrite(ENA + 1, speed);
		digitalWrite(ENA + 2, 1 - speed);
		digitalWrite(ENB + 1, speed);
		digitalWrite(ENB + 2, 1 - speed);
		break;
	}

	framework.println("motor on");
	switch (side)
	{
	case left:
		digitalWrite(ENA, HIGH);
		break;
	case right:
		digitalWrite(ENB, HIGH);
		break;
	case both:
		digitalWrite(ENA, HIGH);
		digitalWrite(ENB, HIGH);
		break;
	}

	delay(seconds);
	return 0;
}
int Car::stop(int seconds = 500)
{
	framework.println("Car::stop");

	digitalWrite(ENA + 1, LOW);
	digitalWrite(ENA + 2, LOW);
	digitalWrite(ENB + 1, LOW);
	digitalWrite(ENB + 2, LOW);

	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);

	delay(seconds);

	return 0;
}
int Car::drive_forward(int seconds = 1000)
{
	return move(both, forward, 200, seconds);
}
int Car::drive_back(int seconds = 1000)
{
	return move(both, back, 200, seconds);
}
int Car::turn_right(int seconds = 1000)
{
	framework.println("Car::turn_right");
	return move(right, forward, 200, seconds);
}
int Car::turn_left(int seconds = 1000)
{
	framework.println("Car::turn_left");
	return move(left, forward, 200, seconds);
}
int Car::drive_auto()
{
	framework.println("Car::drive_auto");

	drive_forward();
	stop();
	turn_right();
	stop();
	drive_forward();
	stop();
	turn_right();
	stop();
	drive_forward();
	stop();
	turn_right();
	stop();
	drive_forward();
	stop();
	turn_right();
	stop();

	return 0;
}
int Car::selftest()
{
	int speed = 1000;

	framework.println("Car::selftest");

	/**/
	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);

	framework.println("Car::selftest basetest left");
	move(left, forward);
	move(left, back);
	stop(speed);

	framework.println("Car::selftest basetest both");
	move(both, forward);
	move(both, back);
	stop(speed);

	framework.println("Car::selftest basetest right");
	move(right, forward);
	move(right, back);
	stop(speed);

	return 0;
}
