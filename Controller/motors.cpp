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

  // Power off
  off();
}

void CallidusMotors::off() {
  digitalWrite(PIN_MOTOR_STBY, LOW);
  digitalWrite(PIN_MOTOR_PWMA, LOW);
  digitalWrite(PIN_MOTOR_PWMB, LOW);
  digitalWrite(PIN_MOTOR_AI1, LOW);
  digitalWrite(PIN_MOTOR_AI2, LOW);
  digitalWrite(PIN_MOTOR_BI1, LOW);
  digitalWrite(PIN_MOTOR_BI2, LOW);
}

void CallidusMotors::drive(int speedBoth) {
  drive(speedBoth, speedBoth);
}

void CallidusMotors::drive(int speedLeft, int speedRight) {
  digitalWrite(PIN_MOTOR_STBY, HIGH);
  analogWrite(PIN_MOTOR_PWMA, abs(speedRight));
  analogWrite(PIN_MOTOR_PWMB, abs(speedLeft));
  digitalWrite(PIN_MOTOR_AI1, speedRight < 0 ? HIGH : LOW);
  digitalWrite(PIN_MOTOR_AI2, speedRight < 0 ? LOW : HIGH);
  digitalWrite(PIN_MOTOR_BI1, speedLeft < 0 ? LOW : HIGH);
  digitalWrite(PIN_MOTOR_BI2, speedLeft < 0 ? HIGH : LOW);
}

void CallidusMotors::brake() {
  digitalWrite(PIN_MOTOR_STBY, HIGH);
  digitalWrite(PIN_MOTOR_PWMA, HIGH);
  digitalWrite(PIN_MOTOR_PWMB, HIGH);
  digitalWrite(PIN_MOTOR_AI1, LOW);
  digitalWrite(PIN_MOTOR_AI2, LOW);
  digitalWrite(PIN_MOTOR_BI1, LOW);
  digitalWrite(PIN_MOTOR_BI2, LOW);
}

void CallidusMotors::update() {
  
}
