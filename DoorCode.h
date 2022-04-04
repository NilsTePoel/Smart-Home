#pragma once

#include <Arduino.h>

class DoorCode {
public:
  DoorCode(uint8_t numDigits, char *correctCode);
  ~DoorCode();
  
  void incrementCurrentDigit();
  void nextDigit();
  
  const uint8_t *getCurrentCode() const;
  const uint8_t getCurrentDigit() const;
  
  bool isValid() const;
  void reset();

private:
  const uint8_t m_numDigits;
  char *m_currentCode;
  uint8_t m_currentDigit;
  const char *m_correctCode;
};
