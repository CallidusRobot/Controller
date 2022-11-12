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

// Compile with: Debug Port Serial, No exceptions

void setup() {
  Log::setup();
  Log::info(F("Callidus Robot System Controller"));
  Log::info(F("Version 0.1 (2022/11/11)"));
  Log::info(F("--------------------------------"));

  CallidusHardware::setup();
  CallidusPower::setup();
  CallidusSystem::setup();
  CallidusWifi::setup();
  CallidusSensors::setup();
  CallidusLights::setup();
  CallidusSound::setup();
  CallidusMotors::setup();
  CallidusBeat::setup();
}

void setup1() {
  // TODO: Wait for setup to complete
}

void loop() {
  CallidusSystem::update();
  CallidusPower::update();
  CallidusWifi::update();
  CallidusLights::update();
  CallidusSound::update();
  CallidusBeat::update(true);
}

void loop1() {
  CallidusSensors::update();
  CallidusMotors::update();
  CallidusBeat::update(false);
  
  // TODO: Synchronize with loop
}
