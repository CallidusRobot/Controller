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
  pinMode(PIN_WIFI_ENABLE, OUTPUT);
  // Turn on WIFI
  digitalWrite(PIN_WIFI_ENABLE, HIGH); // make low again

  // And open the port
  WIFI_PORT.begin(WIFI_SPEED);
}

void CallidusWifi::update() {

}
