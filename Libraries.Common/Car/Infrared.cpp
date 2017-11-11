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

	if (irrecv.decode(&results))
	{
		dump_results(&results);

		val = results.value;

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

void Infrared::dump_results(decode_results *results, int withdetails)
{
	long val=results->value;

	if (val == -1) {
		return;
	}

	if (withdetails) {
		Serial.print("decode type=");
		Serial.print(results->decode_type);
		Serial.print(": ");

		switch (results->decode_type)
		{
		default:
		case UNKNOWN:		Serial.print("UNKNOWN");		break;
		case NEC:			Serial.print("NEC");			break;
		case SONY:			Serial.print("SONY");			break;
		case RC5:			Serial.print("RC5");			break;
		case RC6:			Serial.print("RC6");			break;
		case DISH:			Serial.print("DISH");			break;
		case SHARP:			Serial.print("SHARP");			break;
		case JVC:			Serial.print("JVC");			break;
		case SANYO:			Serial.print("SANYO");			break;
		case MITSUBISHI:	Serial.print("MITSUBISHI");		break;
		case PANASONIC:		Serial.print("PANASONIC");		break;
		}
	}

	Serial.print(" val="); Serial.print(val, HEX); Serial.print(" "); Serial.print(val, DEC); 
	Serial.print(" "); 

	switch (val)
	{
	default:
	case UNKNOWN:		Serial.print("UNKNOWN");	break;

	case KEY_1:	Serial.print("1");			break;
	case KEY_2:	Serial.print("2");			break;
	case KEY_3:	Serial.print("3");			break;
	case KEY_4:	Serial.print("4");			break;
	case KEY_5:	Serial.print("5");			break;
	case KEY_6:	Serial.print("6");			break;
	case KEY_7:	Serial.print("7");			break;
	case KEY_8:	Serial.print("8");			break;
	case KEY_9:	Serial.print("9");			break;
	case KEY_0:	Serial.print("0");			break;

	case 0x32C6FDF7:	Serial.print("*");			break;
	case 0x3EC3FC1B:	Serial.print("#");			break;

	case 0x52A3D41F:	Serial.print("LEFT");		break;
	case 0x20FE4DBB:	Serial.print("RIGHT");		break;
	case 0x00511DBB:	Serial.print("UP");			break;
	case 0xA3C8EDDB:	Serial.print("DOWN");		break;

	case 0xD7E84B1B:	Serial.print("OK");			break;

	}

	Serial.println("");
}

void Infrared::dump()
{
	if (irrecv.decode(&results))
	{
		dump_results(&results);

		irrecv.resume(); // Receive the next value
	}
}

int Infrared::selftest()
{
	return 0;
}