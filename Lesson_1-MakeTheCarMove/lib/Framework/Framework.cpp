/*
   Framework.cpp

    Created on: 14.10.2017
        Author: RalphG
*/

#include "Framework.h"

Framework::Framework()
{
  pinMode(LED_BUILTIN, OUTPUT);

  pin = 0;
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

int Framework::println(char* line) {
  Serial.println(line);

  return 0;
}

int Framework::blink(int seconds)
{
  Serial.println("Framework::blink");

  digitalWrite(LED_BUILTIN, HIGH);
  delay(seconds);
  digitalWrite(LED_BUILTIN, LOW);
  delay(seconds);

  return 0;
}


