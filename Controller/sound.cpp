#include "sound.h"

#include "hardware.h"
#include "log.h"

void CallidusSound::setup() {
  Log::info(F("Initializing sound subsystem..."));

  // Sound module UART transmit
  digitalWrite(PIN_SOUND_TX, HIGH);
  pinMode(PIN_SOUND_TX, OUTPUT);
  // Sound module UART receive, internal pullup
  pinMode(PIN_SOUND_RX, INPUT_PULLUP);
  // Sound module playing input, active-low, internal pullup
  pinMode(PIN_SOUND_BUSY, INPUT_PULLUP);
  SOUND_PORT.setRX(PIN_SOUND_RX);
  SOUND_PORT.setTX(PIN_SOUND_TX);
}

void CallidusSound::update() {

}
