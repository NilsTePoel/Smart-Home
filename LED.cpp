#include "LED.h"

LED::LED(uint8_t pin)
  : m_pin(pin) {
  pinMode(m_pin, OUTPUT);
  disableLED();
}

void LED::enableLED() {
  digitalWrite(m_pin, HIGH);
  m_on = true;
}

void LED::disableLED() {
  digitalWrite(m_pin, LOW);
  m_on = false;
}

void LED::toggleLED() {
  if (m_on) {
    disableLED();
  } else {
    enableLED();
  }
  m_on = !m_on;
}
