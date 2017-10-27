/*
   Car.cpp

    Created on: 14.10.2017
        Author: RalphG
*/

#include "Car.h"


/* Motor B */
int ENB = 5; /* black   */
int N3  = 6; /* grey     */
int N4  = 7; /* white    */

/* Motor A */
int ENA = 8;  /* green   */
int N1  = 9; /* blue     */
int N2  = 8; /* voilettt */


Car::Car() {
  pinMode(LED_BUILTIN, OUTPUT);
}

Car::~Car() {
  // Destructor stub
}

int Car::setup() {
  pinMode(N1, OUTPUT);
  pinMode(N2, OUTPUT);
  pinMode(N3, OUTPUT);
  pinMode(N4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  return 0;
}
int Car::blink(int seconds) {
  Serial.println("LED.blink");

  digitalWrite(LED_BUILTIN, HIGH);
  delay(seconds);
  digitalWrite(LED_BUILTIN, LOW);
  delay(seconds);

  return 0;
}
int Car::println(char *line) {
  return 0;
}
int Car::move(Side side, Direction direction, int speed = 100, int seconds = 500) {
  int power;

  switch (direction)
  {
    case forward: power = HIGH; framework.println("Car::move: forward");  break;
    case back: power = LOW; framework.println("Car::move: back");  break;
  }

  switch (side)
  {
    case both: framework.println("Car::move: set power and speed both"); break;
    case left: framework.println("Car::move: set power and speed left"); break;
    case right: framework.println("Car::move: set power and speed left"); break;
  }

  switch (side)
  {
    case both:
    case left:
      digitalWrite(ENA + 1, power);
      digitalWrite(ENA + 2, 1 - power);
      break;
  }

  switch (side)
  {
    case both:
    case right:
      digitalWrite(ENB + 1, power);
      digitalWrite(ENB + 2, 1 - power);
      break;
  }

  switch (side)
  {
    case left:
      analogWrite(ENA, speed);
      break;
    case right:
      analogWrite(ENB, speed);
      break;
    case both:
      analogWrite(ENA, speed);
      analogWrite(ENB, speed);
      break;
  }


  return 0;
}
int Car::stop(int seconds = 0) {
  digitalWrite(ENA + 1, LOW);
  digitalWrite(ENA + 2, LOW);
  digitalWrite(ENB + 1, LOW);
  digitalWrite(ENB + 2, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  delay(seconds);
}
int Car::drive_forward(int seconds = 1000) {
  return move(both, forward, 200, seconds);
}
int Car::drive_back(int seconds = 1000) {
  return move(both, back, 200, seconds);
}
int Car::turn_right(int seconds = 1000) {
  framework.println("Car::turn_right");
  return move(right, forward, 200, seconds);
}
int Car::turn_left(int seconds = 1000) {
  framework.println("Car::turn_left");
  return move(left, forward, 200, seconds);
}
int Car::drive_auto() {
  framework.println("Car::drive_auto");

  drive_forward(1000);
  stop(500);

  turn_right(1000);
  stop(500);

  drive_forward(1000);
  stop(500);

  turn_right(1000);
  stop(500);

  drive_forward(1000);
  stop(500);

  turn_right(1000);
  stop(500);

  drive_forward(1000);
  stop(500);

  turn_right(1000);
  stop(500);

  stop(500);

  return 0;
}

int Car::selftest() {
  framework.println("Car::selftest");

  drive_forward(2000);
  stop(2000);

  drive_back(1000);
  stop(2000);

  turn_right(2000);
  stop(2000);

  turn_left(2000);
  stop(2000);

  return 0;
}

