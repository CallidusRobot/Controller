#include "wifi.h"

#include "hardware.h"
#include "log.h"

void CallidusWifi::setup() {
  Log::info(F("Initializing WiFi subsystem..."));

  digitalWrite(PIN_WIFI_TX, HIGH);
  pinMode(PIN_WIFI_TX, OUTPUT);
  pinMode(PIN_WIFI_RX, INPUT_PULLUP);
  WIFI_PORT.setRX(PIN_WIFI_RX);
  WIFI_PORT.setTX(PIN_WIFI_TX);
  // WIFI PMC over-current/under-voltage fault, active-low, internal pullup
  pinMode(PIN_WIFI_FAULT, INPUT_PULLUP);
  // WIFI PMC output enable, active-high
  digitalWrite(PIN_WIFI_ENABLE, LOW);
  pinMode(PIN_WIFI_ENABLE, OUTPUT);
}

void CallidusWifi::update() {

}
