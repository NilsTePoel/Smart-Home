#pragma once

#include <Arduino.h>

class MotionDetector {
public:
  MotionDetector(uint8_t pin, void (*handler)(void));
  void enableInterrupts() const;
  void disableInterrupts() const;

private:
  const uint8_t m_pin;
  const void (*m_handler)(void);
};
