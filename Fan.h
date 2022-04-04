#pragma once

#include <Arduino.h>

const uint8_t maxSpeed = 255;

class Fan {
public:
  Fan(uint8_t inA, uint8_t inB);
  void enableFan() const;
  void disableFan() const;
  void setSpeed(uint8_t speed);

private:
  const uint8_t m_inA;
  const uint8_t m_inB;
  uint8_t m_speed;
};
