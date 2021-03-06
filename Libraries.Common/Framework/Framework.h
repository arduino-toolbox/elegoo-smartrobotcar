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
	Framework();
	virtual ~Framework();

	int setup();

	int print(const char* line);
	int print(int line);
	int print(long line);

	int println(const char* line);

	int blink(int seconds = 100);
	int setstate(int state, int seconds);
	int changestate(int seconds = 100);
	
	int BLINK_CHANGESTATE = -1;

  private:
	//  VARIABLES
	uint8_t PIN;
	int state;

	//  CONSTANTS
};

#endif /* FRAMEWORK_H_ */
