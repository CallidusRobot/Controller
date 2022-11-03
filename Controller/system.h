#ifndef SYSTEM_H
#define SYSTEM_H

#include <Arduino.h>

class CallidusSystem {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusSystem() {}
};

#endif