#include "power.h"

#include "hardware.h"
#include "log.h"

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

}
