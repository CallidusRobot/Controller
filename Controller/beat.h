#ifndef BEAT_H
#define BEAT_H

#include <Arduino.h>

class CallidusBeat {
  public:
  static void setup();
  static void update(bool primary);
  
  private:
  CallidusBeat() {}
};

#endif