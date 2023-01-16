#ifndef APP_H
#define APP_H

#include <Arduino.h>

class CallidusApp {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusApp() {}
  static long lastAnnounce;
};

#endif