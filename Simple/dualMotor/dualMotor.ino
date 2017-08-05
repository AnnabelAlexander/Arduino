const int motor1Pin1 = 3;
const int motor1Pin2 = 2;
const int motor2Pin3 = 5;
const int motor2Pin4 = 6;
const int enableMotor1Pin = 9;
const int enableMotor2Pin = 10;

const int echoPin = 12;
const int trigPin = 11;

int curr_direction;

double duration, distance, prev_distance, tol;

int waitFlag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1Pin1,OUTPUT);
  pinMode(motor1Pin2,OUTPUT);
  pinMode(enableMotor1Pin,OUTPUT);
  pinMode(motor2Pin3,OUTPUT);
  pinMode(motor2Pin4,OUTPUT);
  pinMode(enableMotor2Pin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);

  digitalWrite(enableMotor1Pin,LOW);
  digitalWrite(enableMotor2Pin,LOW);
  digitalWrite(trigPin,LOW);

  Serial.begin(9600);
  prev_distance = 0;
  tol = 1E-3;
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (waitFlag==0){
    delay(1000);
    waitFlag = 1;
  }
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  distance = duration*0.034/2;

  enableMotors();

  if (distance < 2.0){
    reverseDirection();
    delay(500);
    sharpRight();
    delay(200);
    curr_direction = 0;
  }else if (distance < 5.0){
    turnLeft();
    delay(150);
    forwardDirection();
    delay(500);
    curr_direction = 1;
  }else if (distance < 10){
    turnRight();
    delay(150);
    forwardDirection();
    delay(500);
    curr_direction = 1;
  }else{
    forwardDirection();
    delay(500);
    curr_direction = 1;
  }

  if(abs(prev_distance - distance)<=tol){
    if (curr_direction==1){
      reverseDirection();
      delay(500);
      sharpRight();
      delay(300);
      curr_direction = 0;
    }else{
      forwardDirection();
      delay(500);
      sharpLeft();
      delay(300);
      curr_direction = 1;
    }   
  }
  prev_distance = distance;
   
}

void enableMotors(){
  analogWrite(enableMotor1Pin,100);
  analogWrite(enableMotor2Pin,100);
}

void disableMotors(){
  analogWrite(enableMotor1Pin,0);
  analogWrite(enableMotor2Pin,0);
}

void reverseDirection(){

  digitalWrite(motor1Pin1,HIGH);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin3,LOW);
  digitalWrite(motor2Pin4,HIGH);

}

void forwardDirection(){
  
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor2Pin3,HIGH);
  digitalWrite(motor2Pin4,LOW);
}

void turnLeft(){

  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor2Pin3,LOW);
  digitalWrite(motor2Pin4,LOW);
  
}

void turnRight(){

  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin3,HIGH);
  digitalWrite(motor2Pin4,LOW);
  
}

void sharpLeft(){

  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor2Pin3,LOW);
  digitalWrite(motor2Pin4,HIGH);
}

void sharpRight(){

  digitalWrite(motor1Pin1,HIGH);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin3,HIGH);
  digitalWrite(motor2Pin4,LOW);
}

