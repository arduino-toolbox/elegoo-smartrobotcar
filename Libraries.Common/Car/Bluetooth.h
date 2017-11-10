/*
   Bluetooth.h

    Created on: 14.10.2017
        Author: RalphG
*/

#ifndef __BLUETOOTH_H_
#define __BLUETOOTH_H_

#include <Framework.h>

class Bluetooth
{
  public:
  public:
    Bluetooth();
    virtual ~Bluetooth();

    int setup();

    int blink(int seconds);


  private:
    //  VARIABLES
    Framework framework;

    volatile int state = LOW; //The initial state of the function is defined as a low level
    char getstr;              //Defines a function that receives the Bluetooth character

    //  CONSTANTS
    int LED=13;               //Define 13 pin for LED
};

#endif /* __BLUETOOTH_H_ */
