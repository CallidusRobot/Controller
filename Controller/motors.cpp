#include "motors.h"

#include "hardware.h"
#include "log.h"

void CallidusMotors::setup() {
  Log::info(F("Initializing motor subsystem..."));

  // Motor channel B PWM
  digitalWrite(PIN_MOTOR_PWMB, LOW);
  pinMode(PIN_MOTOR_PWMB, OUTPUT);
  // Motor channel B input 2
  digitalWrite(PIN_MOTOR_BI2, LOW);
  pinMode(PIN_MOTOR_BI2, OUTPUT);
  // Motor channel B input 1
  digitalWrite(PIN_MOTOR_BI1, LOW);
  pinMode(PIN_MOTOR_BI1, OUTPUT);
  // Motor standby, active-low
  digitalWrite(PIN_MOTOR_STBY, LOW);
  pinMode(PIN_MOTOR_STBY, OUTPUT);
  // Motor channel A input 1
  digitalWrite(PIN_MOTOR_AI1, LOW);
  pinMode(PIN_MOTOR_AI1, OUTPUT);
  // Motor channel A input 2
  digitalWrite(PIN_MOTOR_AI2, LOW);
  pinMode(PIN_MOTOR_AI2, OUTPUT);
  // Motor channel A PWM
  digitalWrite(PIN_MOTOR_PWMA, LOW);
  pinMode(PIN_MOTOR_PWMA, OUTPUT);
}

void CallidusMotors::update() {

}
