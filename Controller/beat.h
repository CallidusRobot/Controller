#ifndef BEAT_H
#define BEAT_H

#include <Arduino.h>

class CallidusBeat {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusBeat() {}
  static bool state;
};

#endif