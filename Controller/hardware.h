#ifndef HARDWARE_H
#define HARDWARE_H

#include <Arduino.h>

enum {
  // Motor channel B PWM
  PIN_MOTOR_PWMB = 0,
  // Motor channel B input 2
  PIN_MOTOR_BI2 = 1,
  // Motor channel B input 1
  PIN_MOTOR_BI1 = 2,
  // Motor standby, active-low
  PIN_MOTOR_STBY = 3,
  // Motor channel A input 1
  PIN_MOTOR_AI1 = 4,
  // Motor channel A input 2
  PIN_MOTOR_AI2 = 5,
  // Motor channel A PWM
  PIN_MOTOR_PWMA = 6,
  // RFID optional IRQ (probably active-high, internal pulldown) or reset/power-save (active-low)
  PIN_RFID_IRQ = 7,
  // WIFI UART transmit
  PIN_WIFI_TX = 8,
  // WIFI UART receive
  PIN_WIFI_RX = 9,
  // RFID SPI clock
  PIN_RFID_CK = 10,
  // RFID SPI data out
  PIN_RFID_TX = 11,
    // RFID SPI data in, internal pulldown
  PIN_RFID_RX = 12,
  // RFID SPI chip select, active-low
  PIN_RFID_CD = 13,
  // WIFI PMC over-current/under-voltage fault, active-low, internal pullup
  PIN_WIFI_FAULT = 14,
  // WIFI PMC output enable, active-high
  PIN_WIFI_ENABLE = 15,
  // Sound module UART transmit
  PIN_SOUND_TX = 16,
  // Sound module UART receive, internal pullup
  PIN_SOUND_RX = 17,
  // WS2812 channel A output
  PIN_WS2812_A = 18,
  // WS2812 channel B output
  PIN_WS2812_B = 19,
  // I2C0 bidirectional data
  PIN_I2C_SDA = 20,
  // I2C0 clock output
  PIN_I2C_SCL = 21,
  // Sound module playing input, active-low, internal pullup
  PIN_SOUND_BUSY = 22,
  // Power save mode output, active-low, prefers low ripple over efficiency if high
  PIN_SYS_PWRSAVE = 23,
  // Whether a USB host is connected, active-high
  PIN_SYS_VBUS = 24,
  // Internal heartbeat LED, active-high
  PIN_SYS_HEARTBEAT = 25,
  // Reflectance via ADC, voltage full-scale inverse-proportional to amount of reflected light
  PIN_LINE_REFLECTANCE = 26,
  // Line sensor LED enable, active-high
  PIN_LINE_ENABLE = 27,
  // VBAT via ADC, 1-3s LiPo, minus drop over U3 then divided
  PIN_SYS_VBAT = 28,
  // VSYS via ADC, regulated 5V divided by 3
  PIN_SYS_VSYS = 29
};

class CallidusHardware {
  public:
  static void setup();
  
  private:
  CallidusHardware() {}
};

#endif