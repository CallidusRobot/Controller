#include "power.h"

#include "hardware.h"
#include "log.h"

#define VBAT_MIN_RAW 100
#define VBAT_MIN_HYST_RAW ((VBAT_MIN_RAW) + 20)

void poweroff(void) {
  SOUND_PORT.end();
  WIFI_PORT.end();
  RFID_PORT.end();
  I2C_PORT.end();
  
  // tri-state for safety and to turn everything off (backfeeds components if USB is on, otherwise)
  for (int i = 0; i < 28; i++)
    pinMode(i, INPUT);
  
  Log::warning(F("POWEROFF!"));
  delay(2000);

  // Wait until there is power available again (with hysteresis) - only happens if powered off while plugged in via USB
  while(analogRead(PIN_SYS_VBAT) < VBAT_MIN_HYST_RAW);
  
  Log::warning(F("REBOOT!"));
  rp2040.reboot();
  while(true);
}

void CallidusPower::setup() {
  Log::info(F("Initializing power subsystem..."));

  // Power save mode output, active-low, prefers low ripple over efficiency if high
  digitalWrite(PIN_SYS_PWRSAVE, HIGH);
  pinMode(PIN_SYS_PWRSAVE, OUTPUT);
  // Whether a USB host is connected, active-high
  pinMode(PIN_SYS_VBUS, INPUT);
  // VBAT via ADC, 1-3s LiPo, minus drop over U3 then divided
  pinMode(PIN_SYS_VBAT, INPUT);
  // VSYS via ADC, regulated 5V divided by 3
  pinMode(PIN_SYS_VSYS, INPUT);
}

void CallidusPower::update() {
  // check power-off due to switch set to off or empty battery
  if (analogRead(PIN_SYS_VBAT) < VBAT_MIN_RAW)
    poweroff();
}
