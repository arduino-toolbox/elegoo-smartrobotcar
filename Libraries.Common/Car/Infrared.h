/*
   LED.h

    Created on: 14.10.2017
        Author: RalphG
*/

#ifndef __INFRARED_H_
#define __INFRARED_H_

#include <IRremote.h>
#include <Framework.h>

class Infrared
{
  public:
  public:
	Infrared();
	virtual ~Infrared();

	int setup();
	int respondtosignal();

	int println(char *line);

	int selftest();

  private:
	//  CONSTANTS
	#define L	16738455

	//  VARIABLES
	Framework framework;

	decode_results results;		//Define structure type
	
};

#endif /* __INFRARED_H_ */
