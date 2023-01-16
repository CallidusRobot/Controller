#include "app.h"

#include "hardware.h"
#include "log.h"

#include "sound.h"
#include "motors.h"
#include "lights.h"

long CallidusApp::lastAnnounce = 0;

void CallidusApp::setup() {
  Log::info(F("Initializing personality app..."));

  CallidusSound::volume(5);
}

enum {
  CMD_STOP = 0,
  CMD_FORWARD,
  CMD_BACKWARD,
  CMD_LEFT,
  CMD_RIGHT,
  CMD_PLAY,
  CMD_VOLUME,
  CMD_LIGHT
};

void CallidusApp::update() {
  // Indicate that the image should be rotated
  if (millis() - lastAnnounce > 500) {
    WIFI_PORT.write((byte) 0xff);
    WIFI_PORT.write((byte) 0x00);
    lastAnnounce = millis();
  }

  if (WIFI_PORT.available() < 1)
    return;

  byte message = WIFI_PORT.read();
  byte type = message & 7;
  byte param = message >> 3;

  int speed = map(param, 0, 31, ANALOG_WRITE_MIN, ANALOG_WRITE_MAX);

  switch (type) {
    case CMD_STOP:
      if (param == 0)
        CallidusMotors::brake();
      else
        CallidusMotors::off();
    break;
    case CMD_FORWARD:
      CallidusMotors::drive(speed);
    break;
    case CMD_BACKWARD:
      CallidusMotors::drive(-speed);
    break;
    case CMD_LEFT:
      CallidusMotors::drive(-speed, speed);
    break;
    case CMD_RIGHT:
      CallidusMotors::drive(speed, -speed);
    break;
    case CMD_PLAY:
      CallidusSound::play(param & 15, (param & 16) > 0);
    break;
    case CMD_VOLUME:
      if (param < 1)
        CallidusSound::stop();
      else
        CallidusSound::volume(param);
      break;
    case CMD_LIGHT:
      CallidusLights::setPattern(param);
    break;
  }
}
