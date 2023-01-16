#ifndef RFID_H
#define RFID_H

#include <Arduino.h>

class CallidusRfid {
  public:
  static void setup();
  static void update();
  
  private:
  CallidusRfid() {}
};

#endif