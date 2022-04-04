#define LIBCALL_ENABLEINTERRUPT
#include <EnableInterrupt.h>
#include "MotionDetector.h"

MotionDetector::MotionDetector(uint8_t pin, void (*handler)(void))
  : m_pin(pin), m_handler(handler) {
  pinMode(m_pin, INPUT);
}

void MotionDetector::enableInterrupts() const {
   enableInterrupt(m_pin, m_handler, CHANGE);
}

void MotionDetector::disableInterrupts() const {
   disableInterrupt(m_pin);
}
