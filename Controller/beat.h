#include <Arduino.h>

class CallidusBeat {
  public:
  static void setup();
  static void update(bool primary);
  
  private:
  CallidusBeat() {}
};
