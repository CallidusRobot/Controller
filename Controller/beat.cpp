#include "beat.h"

#include "hardware.h"
#include "log.h"

void CallidusBeat::setup() {
  Log::info(F("Initializing heartbeat..."));

  // Internal heartbeat LED, active-high
  digitalWrite(PIN_SYS_HEARTBEAT, LOW);
  pinMode(PIN_SYS_HEARTBEAT, OUTPUT);
}

void CallidusBeat::update(bool primary) {
  // TODO: Every update must be synchronized and toggle the LED state every 250ms
  // Stick with the value, if within the last 250ms not both primary and secondary updates have been performed
}
