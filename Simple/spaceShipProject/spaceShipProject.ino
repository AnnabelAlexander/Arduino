int switchState = 0;

//code will start with constant LED and flashing other LED
//when switch is pressed third LED will start flashing along with second.

void setup() {
  // put your setup code here, to run once:

  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  if (switchState == 0){
    digitalWrite(5,HIGH); //green LED turn on 
    digitalWrite(4,HIGH); //red LED off
    digitalWrite(3,LOW); //yellow LED off
    delay(1000);
    digitalWrite(4,LOW);
    delay(250); 
  }else{
    digitalWrite(5,LOW); //green off
    digitalWrite(4,HIGH); //red on
    digitalWrite(3,HIGH); //yellow on
    delay(250); //wait for 250 miliseconds
    digitalWrite(3,LOW);
    delay(250); //another delay
  }
  
}
