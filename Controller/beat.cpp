#include "beat.h"

#include "hardware.h"
#include "log.h"

bool CallidusBeat::state = false;

void CallidusBeat::setup() {
  Log::info(F("Initializing heartbeat..."));

  // Internal heartbeat LED, active-high
  digitalWrite(PIN_SYS_HEARTBEAT, LOW);
  pinMode(PIN_SYS_HEARTBEAT, OUTPUT);
}

void CallidusBeat::update() {
  digitalWrite(PIN_SYS_HEARTBEAT, state);
  state = !state;
}
