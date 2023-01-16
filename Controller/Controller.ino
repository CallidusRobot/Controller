#include "beat.h"
#include "hardware.h"
#include "lights.h"
#include "log.h"
#include "motors.h"
#include "power.h"
#include "sensors.h"
#include "sound.h"
#include "system.h"
#include "wifi.h"
#include "rfid.h"
#include "app.h"

// Compile with: Debug Port Serial, No exceptions

void setup() {
  Log::setup();
  Log::info(F("Callidus Robot System Controller"));
  Log::info(F("Version 0.1 (2023/01/16)"));
  Log::info(F("--------------------------------"));
  Log::info(F("Setting up the hardware..."));

  CallidusHardware::setup();
  CallidusPower::setup();
  CallidusBeat::setup();
  CallidusSystem::setup();
  CallidusSensors::setup();
  CallidusRfid::setup();
  CallidusLights::setup();
  CallidusSound::setup();
  CallidusMotors::setup();
  CallidusWifi::setup();
  CallidusApp::setup();
}

void loop() {
  CallidusSystem::update();
  CallidusPower::update();
  CallidusSensors::update();
  CallidusRfid::update();
  CallidusLights::update();
  CallidusSound::update();
  CallidusMotors::update();
  CallidusWifi::update();
  CallidusBeat::update();
  CallidusApp::update();
}
