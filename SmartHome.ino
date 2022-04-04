#include <EnableInterrupt.h>
#include <LiquidCrystal_I2C.h>

#include "SmartHome.h"
#include "LED.h"
#include "MotionDetector.h"
#include "Window.h"
#include "Fan.h"
#include "Button.h"
#include "Door.h"
#include "DoorCode.h"

LiquidCrystal_I2C lcd(lcdI2CAddress, lcdColumns, lcdRows);
LED indoorLED(indoorLEDPin);
LED outdoorLED(outdoorLEDPin);
MotionDetector motionDetector(motionDetectorPin, toggleOutdoorLED);
Window window(windowServoPin);
Fan fan(fanInA, fanInB);
Button button1(button1Pin, onButton1Pressed);
Button button2(button2Pin, onButton2Pressed);
Door door(doorServoPin);
DoorCode doorCode(doorCodeNumDigits, correctDoorCode);

volatile bool button1Pressed = false;
volatile bool button2Pressed = false;

void setup() {
  // Bluetooth-Modul initialisieren
  Serial.begin(9600);

  // Standardnachricht für das Display
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Home");

  // Fenster und Tür in Anfangsposition (geschlossen) bringen
  window.initWindow();
  door.initDoor();
}

void loop() {
  if (button1Pressed) {
    if (button1.isDebounced()) {
      incrementCurrentDigitAndVerify();
    }
    button1Pressed = false;
  }

  if (button2Pressed) {
    if (button2.isDebounced()) {
      doorCode.nextDigit();
      printDoorCode();
    }
    button2Pressed = false;
  }
}

void serialEvent() {
  char input = Serial.read();

  switch (input) {
    case indoorLedOn:
    {
      indoorLED.enableLED();
      break;
    }
    case indoorLedOff:
    {
      indoorLED.disableLED();
      break;
    }
    case windowSetPos:
    {
      int angle = Serial.parseInt();
      window.setWindowPosition(angle);
      break;
    }
    case windowOpen:
    {
      window.openWindow();
      break;
    }
    case windowClose:
    {
      window.closeWindow();
      break;
    }
    case motionDetectorOn:
    {
      motionDetector.enableInterrupts();
      break;
    }
    case motionDetectorOff:
    {
      motionDetector.disableInterrupts();
      outdoorLED.disableLED();
      break;
    }
    case fanSetSpeed:
    {
      int speed = Serial.parseInt();
      fan.setSpeed(speed);
      break;
    }
    case fanEnable:
    {
      fan.enableFan();
      break;
    }
    case fanDisable:
    {
      fan.disableFan();
      break;
    }
    case doorSetPos:
    {
      int angle = Serial.parseInt();
      door.setDoorPosition(angle);
      break;
    }
    case doorOpen:
    {
      door.openDoor();
      break;
    }
    case doorClose:
    {
      door.closeDoor();
      break;
    }
  }
}

void toggleOutdoorLED() {
  outdoorLED.toggleLED();
}

void onButton1Pressed() {
  button1Pressed = true;
}

void onButton2Pressed() {
  button2Pressed = true;
}

void printDoorCode() {
  lcd.clear();
  
  // Indikator für die aktuelle zu bearbeitende Ziffer ausgeben
  lcd.setCursor(0, 0);
  lcd.print("      ");
  for (int i = 0; i < doorCode.getCurrentDigit(); i++) {
    lcd.print(" ");
  }
  lcd.print("^");

  // Türcode ausgeben
  lcd.setCursor(0, 1);
  lcd.print("Code: ");
  
  uint8_t *currentCode = doorCode.getCurrentCode();
  for (int i = 0; i < doorCodeNumDigits; i++) {
    lcd.print(currentCode[i]);
  }
}

void incrementCurrentDigitAndVerify() {
  doorCode.incrementCurrentDigit();

  printDoorCode();
  
  // Wurde der korrekte Code eingebenen, wird die Tür geöffnet und die Eingabe zurückgesetzt
  if (doorCode.isValid()) {
    door.openDoor();
    
    doorCode.reset();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Smart Home");
  }
}
