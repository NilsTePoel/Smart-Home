#include "Window.h"

Window::Window(uint8_t pin)
  : m_pin(pin) {}

void Window::initWindow() const {
  m_windowServo.attach(m_pin);
  closeWindow();
}

void Window::setWindowPosition(int angle) const {
    m_windowServo.write(angle);
}

void Window::openWindow() const {
    m_windowServo.write(windowOpenPos);
}

void Window::closeWindow() const {
    m_windowServo.write(windowClosedPos);
}
