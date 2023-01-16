#include "hardware.h"

#include "log.h"

const int ANALOG_WRITE_MIN = 0;
const int ANALOG_WRITE_MAX = 65535;

void CallidusHardware::setup() {
  Log::info(F("Initializing common hardware..."));

  // Analog write range
  analogWriteRange(ANALOG_WRITE_MAX);

  // I2C0 bidirectional data
  pinMode(PIN_I2C_SDA, INPUT_PULLUP);
  // I2C0 clock output
  pinMode(PIN_I2C_SCL, INPUT_PULLUP);
  I2C_PORT.setSDA(PIN_I2C_SDA);
  I2C_PORT.setSCL(PIN_I2C_SCL);
}
