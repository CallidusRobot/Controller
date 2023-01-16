#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

class CallidusMotors {
  public:
  static void setup();
  static void update();
  static void off();
  static void drive(int speedBoth);
  static void drive(int speedLeft, int speedRight);
  static void brake();
  
  private:
  CallidusMotors() {}
};

#endif