#pragma once

#include <Arduino.h>

class LED {
public:
    LED(uint8_t pin);

    void enableLED();
    void disableLED();
    void toggleLED();

private:
    const uint8_t m_pin;
    bool m_on;
};
