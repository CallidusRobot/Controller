#include "sensors.h"

#include "hardware.h"
#include "log.h"

void CallidusSensors::setup() {
  Log::info(F("Initializing sensors subsystem..."));

  // Reflectance via ADC, voltage full-scale inverse-proportional to amount of reflected light
  pinMode(PIN_LINE_REFLECTANCE, INPUT);
  // Line sensor LED enable, active-high
  digitalWrite(PIN_LINE_ENABLE, LOW);
  pinMode(PIN_LINE_ENABLE, OUTPUT);

  // RFID optional IRQ (probably active-high, internal pulldown) or reset/power-save (active-low)
  pinMode(PIN_RFID_IRQ, INPUT_PULLDOWN);
  // RFID SPI clock
  digitalWrite(PIN_RFID_CK, LOW);
  pinMode(PIN_RFID_CK, LOW);
  // RFID SPI data out
  digitalWrite(PIN_RFID_TX, LOW);
  pinMode(PIN_RFID_TX, OUTPUT);
  // RFID SPI data in, internal pulldown
  pinMode(PIN_RFID_RX, INPUT_PULLDOWN);
  // RFID SPI chip select, active-low
  digitalWrite(PIN_RFID_CD, HIGH);
  pinMode(PIN_RFID_CD, OUTPUT);
  RFID_PORT.setSCK(PIN_RFID_CK);
  RFID_PORT.setRX(PIN_RFID_RX);
  RFID_PORT.setTX(PIN_RFID_TX);
  RFID_PORT.setCS(PIN_RFID_CD);
}

void CallidusSensors::update() {

}
