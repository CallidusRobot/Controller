#include "lights.h"

#include "hardware.h"
#include "log.h"

void CallidusLights::setup() {
  Log::info(F("Initializing lights subsystem..."));

  // WS2812 channel A output
  digitalWrite(PIN_WS2812_A, LOW);
  pinMode(PIN_WS2812_A, OUTPUT);
  // WS2812 channel B output
  digitalWrite(PIN_WS2812_B, LOW);
  pinMode(PIN_WS2812_B, OUTPUT);
}

void CallidusLights::update() {

}
