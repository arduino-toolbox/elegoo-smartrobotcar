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
	framework.println("Car::Car");
	pinMode(LED_BUILTIN, OUTPUT);
}

Car::~Car()
{
	framework.println("Car::~Car");

	// Destructor stub
}

int Car::setup()
{
	framework.println("Car::setup");

	pinMode(N1, OUTPUT);
	pinMode(N2, OUTPUT);
	pinMode(N3, OUTPUT);
	pinMode(N4, OUTPUT);

	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);

	//
	infrared.setup();

	default_speed = 100;
	default_seconds = 100;

	return 0;
}

int Car::set_default_speed(int speed)
{
	default_speed = speed;

	digitalWrite(ENA, LOW);
	digitalWrite(ENB, LOW);

	analogWrite(ENA, default_speed);
	analogWrite(ENB, default_speed);

	return default_speed;
}
int Car::set_default_seconds(int seconds)
{
	framework.print("Car::blink to ");
	framework.print(seconds);

	default_seconds = seconds;

	return default_seconds;
}
int Car::blink(int seconds)
{
	framework.println("Car::blink");

	digitalWrite(LED_BUILTIN, HIGH);
	delay(seconds);
	digitalWrite(LED_BUILTIN, LOW);
	delay(seconds);

	return 0;
}
int Car::move(Side side, Direction direction, int speed, int seconds)
{
	speed = direction == forward ? HIGH : LOW;

	framework.print("Car::move ");
	framework.print("speed="); Serial.print(speed);
	framework.print(" direction="); Serial.print(direction);
	framework.println("");

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

	if (seconds == -1) {
		seconds = default_seconds;
	}
	
	delay(seconds);
	return 0;
}
int Car::stop(int seconds)
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
int Car::move_forward(int seconds)
{
	framework.println("Car::move_forward");
	return move(both, forward, 100, seconds);
}
int Car::move_back(int seconds)
{
	framework.println("Car::move_back");
	return move(both, back, 200, seconds);
}
int Car::move_right(int seconds)
{
	framework.println("Car::move_right");
	return move(right, forward, 200, seconds);
}
int Car::move_left(int seconds)
{
	framework.println("Car::move_left");
	return move(left, forward, 200, seconds);
}
int Car::drive_auto()
{
	framework.println("Car::drive_auto");

	move_forward();
	stop();
	move_right();
	stop();
	move_forward();
	stop();
	move_right();
	stop();
	move_forward();
	stop();
	move_right();
	stop();
	move_forward();
	stop();
	move_right();
	stop();

	return 0;
}

int Car::drive_remotecontrol()
{
	long key = infrared.check();
	
	if (key == 0) {
		return 0;
	}

	framework.print("Car::drive_remotecontrol ");

	switch (key)
	{
	default:
		break;
	case KEY_STAR:
		framework.print("*: STOP ");
		stop();
		break;
	case KEY_HASH:
		framework.print("#: STOP ");
		stop();
		break;

	case KEY_LEFT:
		framework.print("<: LEFT ");
		move_left(100);
		break;
	case KEY_RIGHT:
		framework.print(">: RIGHT");
		move_right(100);
		break;
	case KEY_UP:
		framework.print("^: UP   ");
		move_forward(100);
		break;
	case KEY_DOWN:
		framework.print("V: DOWN ");
		move_back(100);
		break;

	case KEY_OK:
		framework.print("O: OK   ");
		stop();
		break;
	}
	stop();

	framework.println("");

	return key;
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
