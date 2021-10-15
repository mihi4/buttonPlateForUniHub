#include <Joystick.h>

uint8_t joystickbuttons = 20;
uint8_t val;
uint8_t pin;

Joystick_ Joystick = Joystick_(0x41, JOYSTICK_TYPE_JOYSTICK, joystickbuttons, 0, true, true, true, true, false, false, false, false, false, false, false);

void setup() {
  // put your setup code here, to run once:
  
  for (pin=0;pin<11;pin++) {
    pinMode(pin, INPUT_PULLUP);
  }
  for (pin=14;pin<17;pin++) {
    pinMode(pin, INPUT_PULLUP);
  }
  for (pin=18;pin<22;pin++) {
    pinMode(pin, INPUT_PULLUP);
  }
  Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (pin=0;pin<11;pin++) {
    Joystick.setButton(pin, !(digitalRead(pin)));
  }
  for (pin=14;pin<17;pin++) {
    Joystick.setButton(pin-3, !(digitalRead(pin)));
  }
  for (pin=18;pin<22;pin++) {
    Joystick.setButton(pin-4, !(digitalRead(pin)));
  }
  
}
