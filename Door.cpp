#include "Door.h"

Door::Door(uint8_t pin)
  : m_pin(pin) {}

void Door::initDoor() const {
  m_doorServo.attach(m_pin);
  closeDoor();
}

void Door::setDoorPosition(int angle) const {
    m_doorServo.write(angle);
}

void Door::openDoor() const {
    m_doorServo.write(doorOpenPos);
}

void Door::closeDoor() const {
    m_doorServo.write(doorClosedPos);
}
