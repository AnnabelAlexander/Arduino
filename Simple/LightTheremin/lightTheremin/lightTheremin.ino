int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;

const int pinIn = A0;
const int pinOut = 8;
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);

  while (millis() < 8000){

    sensorVal = analogRead(pinIn);
    if (sensorVal > sensorHigh)
      sensorHigh = sensorVal;
    if (sensorVal < sensorLow)
      sensorLow = sensorVal;
  }
  digitalWrite(ledPin,LOW);
  Serial.begin(9600);
  Serial.print("High val is : ");
  Serial.println(sensorHigh);
  Serial.print("Low val is : ");
  Serial.println(sensorLow);

}

void loop() {
  // put your main code here, to run repeatedly:
    sensorVal = analogRead(pinIn);
    int pitch = map(sensorVal,sensorLow,sensorHigh,50,4000);
    tone(pinOut,pitch,20);
    delay(10);

}
