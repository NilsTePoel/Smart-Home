#include "DoorCode.h"

DoorCode::DoorCode(uint8_t numDigits, char *correctCode)
  : m_numDigits(numDigits), m_correctCode(correctCode) {
  m_currentCode = new char[numDigits];
  reset();
}

DoorCode::~DoorCode() {
  delete[] m_currentCode;
}

void DoorCode::incrementCurrentDigit() {
  m_currentCode[m_currentDigit] = (m_currentCode[m_currentDigit] + 1) % 10;
}

void DoorCode::nextDigit() {
  m_currentDigit = (m_currentDigit + 1) % m_numDigits;
}

const uint8_t *DoorCode::getCurrentCode() const {
  return m_currentCode;
}

const uint8_t DoorCode::getCurrentDigit() const {
  return m_currentDigit;
}

bool DoorCode::isValid() const {
  for (int i = 0; i < m_numDigits; i++) {
    if (m_currentCode[i] != m_correctCode[i]) {
      return false;
    }
  }

  return true;
}

void DoorCode::reset() {
  m_currentDigit = 0;
  for (uint8_t i = 0; i < m_numDigits; i++) {
    m_currentCode[i] = 0;
  }
}
