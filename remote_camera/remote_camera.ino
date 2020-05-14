#include <Dabble.h>
int LEDpin = 12;
int interval = 1000;
int photosNum = 1;
boolean firstShot = false;
int secondsBeforeFirstPhoto = 1000;

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600);  
  pinMode(LEDpin, OUTPUT); //led
}

void loop() {
  Dabble.processInput();         
  if (GamePad.isUpPressed())
  {
      interval = interval + 1000;
      Serial.print("intervals"); 
  }
  if (GamePad.isDownPressed())
  {
     takeNPhotos(photosNum, interval);
     Serial.print("opa");  
  }
  if (GamePad.isLeftPressed())
  {
      Serial.print("photo"); 
      photosNum++;
  }
  if (GamePad.isRightPressed())
  {
            Serial.print("photo"); 

      secondsBeforeFirstPhoto = secondsBeforeFirstPhoto + 1000;
  }
}

void takeNPhotos(int photos, int interval) {
  firstShot = true;
  for(byte i = 0; i < photos; i++) {    
    takePhoto(secondsBeforeFirstPhoto);        // take the picture
    delay(interval);   
    Serial.println("snap");
  }
  firstShot = false;
  photosNum = 1;
  interval = 1000;
  secondsBeforeFirstPhoto = 1000;
}

void pulseON(int pulseTime) {
  unsigned long endPulse = micros() + pulseTime;        
  while(micros() < endPulse) {
    digitalWrite(LEDpin, HIGH);                       
    delayMicroseconds(13);                              
    digitalWrite(LEDpin, LOW);                        
    delayMicroseconds(13);                             
  }

}

void pulseOFF(unsigned long startDelay) {
  unsigned long endDelay = micros() + startDelay;       // create the microseconds to delay for
  while(micros() < endDelay);
}

//executes signals that trigger the camera ir receiver

void takePhoto(int delayBefore) {
  if(firstShot == false){
      delay(delayBefore);
  }
  for (int i=0; i < 2; i++) {
    pulseON(2000);                                      // pulse for 2000 uS (Microseconds)
    pulseOFF(27850);                                    // turn pulse off for 27850 us
    pulseON(400);                                       // and so on
    pulseOFF(1580);
    pulseON(400);
    pulseOFF(3580);
    pulseON(400);
    pulseOFF(63200);
  }    
}
