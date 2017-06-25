#include <Servo.h>

Servo myServo;

int const potPin = A0;
float potVal;
float angle;

void setup() {
  // put your setup code here, to run once:
  
  //use pin 9 for input
  myServo.attach(9);
  //write to screen
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.print("Volts are : ");
  Serial.print(potVal);
  //maps possible potential values (0-1023) to possible angles (0-179)
  angle = map(potVal,0,1023,0,179);
  Serial.print("\t angle is : ");
  Serial.println(angle);

  //make the servo move
  myServo.write(angle);
  delay(15);

}
