#include <Dabble.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
int LEDpin = 12;

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600);  
  pinMode(LEDpin, OUTPUT); //led
}

void loop() {
  Dabble.processInput();         
  if (GamePad.isUpPressed())
     {
         takePhoto();
    }
    if (GamePad.isDownPressed())
     {
        digitalWrite(LEDpin, LOW);
    }
}

//execute signals to trigger the camera ir receiver 
void takePhoto(void) {
  int i;
  for (i = 0; i < 76; i++) {
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(7);
  digitalWrite(LEDpin, LOW);
  delayMicroseconds(7);
  }
  delay(27);
  delayMicroseconds(810);
  for (i = 0; i < 16; i++) {
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(7);
  digitalWrite(LEDpin, LOW);
  delayMicroseconds(7);
  }
  delayMicroseconds(1540);
  for (i = 0; i < 16; i++) {
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(7);
  digitalWrite(LEDpin, LOW);
  delayMicroseconds(7);
  }
  delayMicroseconds(3545);
  for (i = 0; i < 16; i++) {
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(7);
  digitalWrite(LEDpin, LOW);
  delayMicroseconds(7);
  }
}
