/*
   LED.h

    Created on: 14.10.2017
        Author: RalphG
*/

#ifndef Car_H_
#define Car_H_


class Car
{
  public:
  public:
	Car();
	virtual ~Car();


	int setup();

	int blink(int seconds);
	int println(char *line);

  private:
	//  VARIABLES


	//  CONSTANTS
};

#endif /* Car_H_ */
