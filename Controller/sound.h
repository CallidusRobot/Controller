#ifndef SOUND_H
#define SOUND_H

#include <Arduino.h>

class CallidusSound {
  public:
  static void setup();
  static void update();

  static void volume(int volume); //0..30
  static void play(int index, bool repeat);
  static void advert(int index);
  static void stop();
  
  private:
  CallidusSound() {}
};

#endif