// LCD-Einstellungen
const uint8_t lcdI2CAddress = 0x27;
const uint8_t lcdColumns = 16;
const uint8_t lcdRows = 2;

// Bluetooth-Codes
const char indoorLedOn = 'a';
const char indoorLedOff = 'b';
const char windowSetPos = 'u';
const char windowOpen = 'n';
const char windowClose = 'o';
const char motionDetectorOn = 'h';
const char motionDetectorOff = 'S';
const char fanSetSpeed = 'w';
const char fanEnable = 'r';
const char fanDisable = 's';
const char doorSetPos = 't';
const char doorOpen = 'l';
const char doorClose = 'm';

// Pins
const uint8_t indoorLEDPin = 5;
const uint8_t outdoorLEDPin = 13;
const uint8_t motionDetectorPin = 2;
const uint8_t windowServoPin = 10;
const uint8_t fanInA = 6;
const uint8_t fanInB = 7;
const uint8_t button1Pin = 4;
const uint8_t button2Pin = 8;
const uint8_t doorServoPin = 9;

// Türcode
const uint8_t doorCodeNumDigits = 4;
const uint8_t correctDoorCode[] = {3, 6, 9, 3};

void toggleOutdoorLED();
void onButton1Pressed();
void onButton2Pressed();
void incrementCurrentDigitAndVerify();
