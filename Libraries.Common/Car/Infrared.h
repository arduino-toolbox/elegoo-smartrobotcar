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

	long check();
	
	int respondtosignal();
	void dump();
	
	int println(const char *line);

	int selftest();

  private:
	void dump_results(decode_results *results, int withdetails = 0);

	//  CONSTANTS
	#define L	16738455


	#define KEY_1			0xC101E57B
	#define KEY_2			0x97483BFB
	#define KEY_3			0xF0C41643
	#define KEY_4			0x00FF30CF
	#define KEY_5			0x3D9AE3F7
	#define KEY_6			0x6182021B
	#define KEY_7			0x8C22657B
	#define KEY_8			0x488F3CBB
	#define KEY_9			0x0449E79F
	#define KEY_0			0x1BC0157B

	#define KEY_STAR		0x32C6FDF7
	#define KEY_HASH		0x3EC3FC1B

	#define KEY_LEFT		0x52A3D41F
	#define KEY_RIGHT		0x20FE4DBB
	#define KEY_UP			0x00511DBB
	#define KEY_DOWN		0xA3C8EDDB

	#define KEY_OK			0xD7E84B1B

	//  VARIABLES
	Framework framework;

	decode_results results;		//Define structure type
	
};

#endif /* __INFRARED_H_ */
