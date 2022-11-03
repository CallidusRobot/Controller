#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>

class CallidusWifi {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusWifi() {}
};

#endif