#pragma once

#include <Arduino.h>

const uint32_t debounceDelay = 200; // in ms

class Button {
public:
  Button(uint8_t pin, void (*handler)(void));

  bool isDebounced();
  
private:
  uint32_t lastDebounceTime;
};
