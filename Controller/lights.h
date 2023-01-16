#ifndef LIGHTS_H
#define LIGHTS_H

#include <Arduino.h>

class CallidusLights {
  public:
  static void setup();
  static void update();
  static void setPattern(int pattern);
  
  private:
  CallidusLights() {}
};

#endif