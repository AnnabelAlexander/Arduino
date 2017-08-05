const int sensorPin = A0;
float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  //calibrate the baselineTemp first
  baselineTemp = convertToTemp(analogRead(sensorPin));

  Serial.begin(9600); //open a serial port on 9600
  //setup the LED pins to be output and start LOW
  for (int i = 3; i <=5; ++i){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
  Serial.print("baseline temperature is ");
  Serial.println(baselineTemp);
  //pause for 1 second
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //write the temperature to the screen
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value : ");
  Serial.print(sensorVal);
  Serial.print(" , Voltage is ");
  Serial.print(convertToVolts(sensorVal));
  Serial.print(" , Temperature is : ");
  Serial.println(convertToTemp(sensorVal));
  
  float temp = convertToTemp(sensorVal);
  if (temp < baselineTemp){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  else if (temp >= baselineTemp && temp <= baselineTemp+1.0){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }else if (temp > baselineTemp + 1.0 && temp <= baselineTemp + 2.0){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }else{
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
  }
  delay(2000);
}

float convertToTemp(int sensorVal){

  float volts = convertToVolts(sensorVal);
  return (volts - 0.5) * 100.0;
}

float convertToVolts(int sensorVal){

  return (sensorVal / 1024.0) * 5.0;
  
}

