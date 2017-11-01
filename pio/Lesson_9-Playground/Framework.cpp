/*
 * Framework.cpp
 *
 *  Created on: 14.10.2017
 *      Author: RalphG
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

int Framework::blink(int for_seconds)
{
  Serial.println("LED.blink");

  digitalWrite(LED_BUILTIN, HIGH);
  delay(for_seconds);
  digitalWrite(LED_BUILTIN, LOW);
  delay(for_seconds);

  return 0;
}
