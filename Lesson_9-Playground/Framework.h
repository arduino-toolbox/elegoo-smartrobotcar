/*
 * Frmework.h
 *
 *  Created on: 14.10.2017
 *      Author: RalphG
 */

#ifndef __FRAMEWORK_H_
#define __FRAMEWORK_H_

#ifndef __ARDUINO_H_
#define __ARDUINO_H_

#include <Arduino.h>

#endif

class Framework
{
public:
public:
  Framework();
  virtual ~Framework();

  int blink(int for_seconds);

private:
  //  VARIABLES
  uint8_t pin;

  //  CONSTANTS
};

#endif /* FRAMEWORK_H_ */
