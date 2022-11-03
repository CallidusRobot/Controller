#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class CallidusSensors {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusSensors() {}
};

#endif