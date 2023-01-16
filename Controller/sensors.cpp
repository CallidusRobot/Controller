#include "sensors.h"

#include "hardware.h"
#include "log.h"

void CallidusSensors::setup() {
  Log::info(F("Initializing sensors subsystem..."));

  // Reflectance via ADC, voltage full-scale inverse-proportional to amount of reflected light
  pinMode(PIN_LINE_REFLECTANCE, INPUT);
  // Line sensor LED enable, active-high
  digitalWrite(PIN_LINE_ENABLE, LOW);
  pinMode(PIN_LINE_ENABLE, OUTPUT);
}

void CallidusSensors::update() {

}
