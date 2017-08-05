const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;

int motorEnabled = 0;
int motorSpeed = 100;
int motorDirection = 1;

int waitFlag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(controlPin1,OUTPUT);
  pinMode(controlPin2,OUTPUT);
  pinMode(enablePin,OUTPUT);

  digitalWrite(enablePin,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (waitFlag==0){
    delay(1000);
    waitFlag = 1;
  }
  delay(100);
  motorEnabled = !motorEnabled;
  delay(100);
  motorDirection = !motorDirection;

  if (motorDirection == 1){
    digitalWrite(controlPin1,HIGH);
    digitalWrite(controlPin2,LOW);
  }else{
    digitalWrite(controlPin1,LOW);
    digitalWrite(controlPin2,HIGH);
  }

  if (motorEnabled == 1)
    analogWrite(enablePin,motorSpeed);
  else
    analogWrite(enablePin,0);

}
