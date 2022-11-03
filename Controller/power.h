#ifndef POWER_H
#define POWER_H

#include <Arduino.h>

class CallidusPower {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusPower() {}
};

#endif