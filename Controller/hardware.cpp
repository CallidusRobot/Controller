#include "hardware.h"

#include "log.h"

void CallidusHardware::setup() {
  Log::info(F("Initializing common hardware..."));

  // I2C0 bidirectional data
  pinMode(PIN_I2C_SDA, INPUT_PULLUP);
  // I2C0 clock output
  pinMode(PIN_I2C_SCL, INPUT_PULLUP);
  I2C_PORT.setSDA(PIN_I2C_SDA);
  I2C_PORT.setSCL(PIN_I2C_SCL);
}
