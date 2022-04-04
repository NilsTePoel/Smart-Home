#include "Fan.h"

Fan::Fan(uint8_t inA, uint8_t inB)
  : m_inA(inA), m_inB(inB) {
  pinMode(m_inA, OUTPUT);
  pinMode(m_inB, OUTPUT);
  setSpeed(maxSpeed);
}

void Fan::enableFan() const {
  analogWrite(m_inA, m_speed);
  digitalWrite(m_inB, LOW);
}

void Fan::disableFan() const {
  digitalWrite(m_inA, LOW);
  digitalWrite(m_inB, LOW);
}

void Fan::setSpeed(uint8_t speed) {
  m_speed = speed;
}
