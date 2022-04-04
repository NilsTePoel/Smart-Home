#define LIBCALL_ENABLEINTERRUPT
#include <EnableInterrupt.h>
#include "Button.h"

Button::Button(uint8_t pin, void (*handler)(void))
  : lastDebounceTime(millis()) {
  pinMode(pin, INPUT);
  enableInterrupt(pin, handler, FALLING);
}

bool Button::isDebounced() {
  if ((millis() - lastDebounceTime) >= debounceDelay) {
    lastDebounceTime = millis();
    return true;
  } else {
    return false;
  }
}
