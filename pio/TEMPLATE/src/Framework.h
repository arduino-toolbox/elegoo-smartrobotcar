/*
 * Frmework.h
 *
 *  Created on: 14.10.2017
 *      Author: RalphG
 */

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include <Arduino.h>
#include <Wire.h>

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
