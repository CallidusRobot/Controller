#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

class CallidusMotors {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusMotors() {}
};

#endif