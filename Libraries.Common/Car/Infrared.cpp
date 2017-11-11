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
	int val=results->value;

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

	Serial.print(" val="); Serial.print(val, HEX); 
	Serial.print(" ("); Serial.print(results->bits, DEC); Serial.println(" bits)"); 
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