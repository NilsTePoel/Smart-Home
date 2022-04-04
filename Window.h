#pragma once

#include <Arduino.h>
#include <Servo.h>

const uint8_t windowOpenPos = 140;
const uint8_t windowClosedPos = 20;

class Window {
public:
    Window(uint8_t pin);

    void initWindow() const;
    void setWindowPosition(int angle) const;
    void openWindow() const;
    void closeWindow() const;

private:
    const uint8_t m_pin;
    const Servo m_windowServo;
};
