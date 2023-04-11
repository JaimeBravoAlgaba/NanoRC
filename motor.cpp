#include "NanoRC.h"

Motor::Motor(uint8_t pwm, uint8_t dirA, uint8_t dirB)
{
  _pwm = pwm;
  _dirA = dirA;
  _dirB = dirB;

  pinMode(_pwm, OUTPUT);
  pinMode(_dirA, OUTPUT);
  pinMode(_dirB, OUTPUT);
}

void Motor::move(uint8_t pwm, uint8_t dir)
{
  analogWrite(_pwm, pwm);
  digitalWrite(_dirA, dir);
  digitalWrite(_dirB, !dir);
}

void Motor::stop()
{
  analogWrite(_pwm, 0);
  digitalWrite(_dirA, LOW);
  digitalWrite(_dirB, LOW);
}