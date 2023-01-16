#include "sound.h"

#include "hardware.h"
#include "log.h"

#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini myDFPlayer;

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
  SOUND_PORT.begin(SOUND_SPEED);

  if (!myDFPlayer.begin(SOUND_PORT)) {
    Log::error(F("Sound player is unavailable. No SD or no connection."));
    return;
  }
}

void CallidusSound::volume(int volume) {
  myDFPlayer.volume(volume);
}

void CallidusSound::play(int index, bool repeat) {
  if (repeat)
    myDFPlayer.loop(index);
  else
    myDFPlayer.play(index);
}

void CallidusSound::advert(int index) {
  myDFPlayer.advertise(index);
}

void CallidusSound::stop() {
  myDFPlayer.stop();
}

void CallidusSound::update() {

}
