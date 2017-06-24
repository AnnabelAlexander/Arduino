const int greenPin = 9;
const int bluePin = 11;
const int redPin = 10;

const int blueSensor = A2;
const int greenSensor = A0;
const int redSensor = A1;

int redVal = 0;
int blueVal = 0;
int greenVal = 0;

int redSensorVal = 0;
int blueSensorVal = 0;
int greenSensorVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(redPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //analog sensor needs a millisecond or so to read
  redSensorVal = analogRead(redSensor);
  delay(5);
  blueSensorVal = analogRead(blueSensor);
  delay(5);
  greenSensorVal = analogRead(greenSensor);
  delay(5);
  Serial.print("Raw sensors values \t Red: ");
  Serial.print(redSensorVal);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorVal);
  Serial.print("\t Green: ");
  //print with new line character
  Serial.println(greenSensorVal);
  //wait 2 sec so see what is going on
  delay(500);
  //sensor in values are between 0 and 1023 - so 1024 values in total
  //the PWM values can be between 0 and 255, 255 will be HIGH all the time, 0 will be LOW all the time
  //and 127 will be on HIGH half the time and LOW the other half 
  //need to convert the sensor input values from 1024 to 256 - therefore divide by 4
  redVal = redSensorVal / 4.0;
  blueVal = blueSensorVal / 4.0;
  greenVal = greenSensorVal / 4.0;
  analogWrite(redPin,redVal);
  analogWrite(bluePin,blueVal);
  analogWrite(greenPin,greenVal);
}
