#ifndef SOUND_H
#define SOUND_H

#include <Arduino.h>

class CallidusSound {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusSound() {}
};

#endif