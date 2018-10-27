/* Code for the Knight Rider Lunchbox Robot
 * Made by: WvdK
 * Visit http://www.instructables.com/member/Weseley/ for contact or more instructables.
*/


#include <Servo.h>

const int RForward = 0;
const int RBackward = 170;
const int LForward = 160;
const int LBackward = 0;
const int RNeutral = 104;
const int LNeutral = 104;

int i;
int timer = 100;
int byteRead;

Servo leftMotor;
Servo rightMotor;

void setup()

{
  pinMode(1, OUTPUT);
  for (int thisPin = 2; thisPin < 8; thisPin++) { pinMode(thisPin, OUTPUT);
  pinMode(8, OUTPUT);
  leftMotor.attach(9);
  rightMotor.attach(10);
  leftMotor.write(LNeutral);
  rightMotor.write(RNeutral);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
   }
}

void loop()
{
      

if (Serial.available() > 0) {
  byteRead = Serial.read();

  //forward
  if (byteRead == 'w') {
    leftMotor.write(LForward);
    rightMotor.write(RForward);
    delay(100);
    leftMotor.write(LNeutral);
    rightMotor.write(LNeutral);
  }
  //backward
  if (byteRead == 's') {
    leftMotor.write(LBackward);
    rightMotor.write(RBackward);
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    leftMotor.write(LNeutral);
    rightMotor.write(LNeutral);
  }
  //right
  if (byteRead == 'd') {
    leftMotor.write(LForward);
    rightMotor.write(RBackward);
    delay(100);
    leftMotor.write(LNeutral);
    rightMotor.write(LNeutral);
  }
  //left
  if (byteRead == 'a') {
    leftMotor.write(LBackward);
    rightMotor.write(RForward);
    delay(100);
    leftMotor.write(LNeutral);
    rightMotor.write(LNeutral);
  }

  //Signal light left
  if (byteRead == 'z') {
    for (int i = 0; i < 5; i++) {
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      delay(500);
    }
  }

  //signal light right
  if (byteRead == 'x') {
    for (int i = 0; i < 5; i++) {
      digitalWrite(8, HIGH);
      delay(500);
      digitalWrite(8, LOW);
      delay(500);
    }
  }
  //front lights on/off
  if (byteRead == 'l') {
    digitalWrite(13, HIGH);
  }
  if (byteRead == 'o') {
    digitalWrite(13, LOW);
  }

  //signal front lights
  if (byteRead == 'p') {
    for (int i = 0; i < 5; i++) {
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
    }
  }
  //hazard lights
  if (byteRead == 'c') {
    for (int i = 0; i < 5; i++) {
      digitalWrite(8, HIGH);
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(8, LOW); 
      digitalWrite(12, LOW);
      delay(500);
    }
  }

  //Knight Rider :)
  if (byteRead == 'k') {
    for (int i = 0; i < 5; i++) {
      for (int thisPin = 2; thisPin < 8; thisPin++) {
        digitalWrite(thisPin, HIGH);
        delay(timer);
        digitalWrite(thisPin, LOW);

      }
      for (int thisPin = 7; thisPin >= 2; thisPin--) {
        digitalWrite(thisPin, HIGH);
        delay(timer);
        digitalWrite(thisPin, LOW);
      }
    }
  }
}
}
    
  



