#pragma once

#include <Arduino.h>
#include <Servo.h>

const uint8_t doorOpenPos = 75;
const uint8_t doorClosedPos = 145;

class Door {
public:
    Door(uint8_t pin);

    void initDoor() const;
    void setDoorPosition(int angle) const;
    void openDoor() const;
    void closeDoor() const;

private:
    const uint8_t m_pin;
    const Servo m_doorServo;
};
