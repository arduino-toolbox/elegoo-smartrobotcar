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

long Infrared::check()
{
	long key;
	decode_results results;

	if (!irrecv.decode(&results))
	{
		key = 0;
	} else {
		key = results.value;

		framework.print("Infrared::check ");	
		framework.print(key);
		
		switch (key)
		{
		default:		framework.print("DEFAULT");			break;
		case UNKNOWN:	framework.print("UNKNOWN");			break;

		case KEY_1:		framework.print("1      ");			break;
		case KEY_2:		framework.print("2      ");			break;
		case KEY_3:		framework.print("3      ");			break;
		case KEY_4:		framework.print("4      ");			break;
		case KEY_5:		framework.print("5      ");			break;
		case KEY_6:		framework.print("6      ");			break;
		case KEY_7:		framework.print("7      ");			break;
		case KEY_8:		framework.print("8      ");			break;
		case KEY_9:		framework.print("9      ");			break;
		case KEY_0:		framework.print("0      ");			break;

		case KEY_STAR:	framework.print("*      ");			break;
		case KEY_HASH:	framework.print("#      ");			break;

		case KEY_LEFT:	framework.print("LEFT   ");			break;
		case KEY_RIGHT:	framework.print("RIGHT  ");			break;
		case KEY_UP:	framework.print("UP     ");			break;
		case KEY_DOWN:	framework.print("DOWN   ");			break;

		case KEY_OK:	framework.print("OK     ");			break;
		}

		framework.print("  ");

		//
		framework.println("resume receiving");

		irrecv.resume();
		delay(100);
	}

	return key;
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

	case KEY_1:		Serial.print("1");			break;
	case KEY_2:		Serial.print("2");			break;
	case KEY_3:		Serial.print("3");			break;
	case KEY_4:		Serial.print("4");			break;
	case KEY_5:		Serial.print("5");			break;
	case KEY_6:		Serial.print("6");			break;
	case KEY_7:		Serial.print("7");			break;
	case KEY_8:		Serial.print("8");			break;
	case KEY_9:		Serial.print("9");			break;
	case KEY_0:		Serial.print("0");			break;

	case KEY_STAR:	Serial.print("*");			break;
	case KEY_HASH:	Serial.print("#");			break;

	case KEY_LEFT:	Serial.print("LEFT");		break;
	case KEY_RIGHT:	Serial.print("RIGHT");		break;
	case KEY_UP:	Serial.print("UP");			break;
	case KEY_DOWN:	Serial.print("DOWN");		break;

	case KEY_OK:	Serial.print("OK");			break;

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