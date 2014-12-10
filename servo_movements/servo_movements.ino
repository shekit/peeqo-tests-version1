#include <Servo.h>

Servo servoNeck;
Servo servoHead;

int pos = 0;
int servoHeadPosition = 0;

int button =52;

int lastServoNeckPosition = 0;
int lastServoHeadPosition = 0;

void setup(){
  Serial.begin(9600);
   servoNeck.attach(2);
   servoHead.attach(3); 
   
   pinMode(button, OUTPUT);
   
   establishContact();
}

void loop(){
  if(Serial.available() > 0){
     char inByte = Serial.read();
    
    if(inByte == 'q'){
       no();
    } else if(inByte == 'w'){
       yes(); 
    } else if(inByte == 'e'){
      sadHead();
    } else if(inByte == 'r'){
      happyHead();
    }
  }
  pos=20;
  no();
}

void no(){
  
  if(servoNeck.detached()){
     servoNeck.attach(2); 
  }
  
  for(int i =0;i<3;i++){

    for(pos = 30; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      servoNeck.write(pos);       // tell servo to go to position in variable 'pos' 
      lastServoNeckPosition = servoNeck.read();
      Serial.println(lastServoNeckPosition);
      delay(10);                       // waits 15ms for the servo to reach the position 
    } 
    for(pos = 150; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
      servoNeck.write(pos);              // tell servo to go to position in variable 'pos' 
      lastServoNeckPosition = servoNeck.read();
      Serial.println(lastServoNeckPosition);
      delay(10);                       // waits 15ms for the servo to reach the position 
    } 
   if(i == 2){
      servoNeck.write(90);
      delay(5);
      servoNeck.detach(); 
   }
  }

}

void yes(){
  if(servoHead.detached()){
     servoHead.attach(3); 
  }
  
  for(int i=0;i<3;i++){
    
    for(pos = 60; pos < 120;pos+=1){
       servoHead.write(pos); 
       delay(15);
    }
    
    for(pos = 120; pos>=60;pos -= 1){
       servoHead.write(pos);
       delay(15); 
    }
    
    if(i == 2){
       servoHead.write(90);
       delay(5);
       servoHead.detach();
    }
  }
  
}

void sadHead() {
  
   if(servoHead.detached()){
      servoHead.attach(3); 
   }
    
   for(pos = 60; pos >= 1; pos-=1){
      servoHead.write(pos);
      delay(10);
   } 
   if(servoHead.read() == 1){
      servoHead.detach(); 
   }
}

void happyHead() {
  
  if(servoHead.detached()){
     servoHead.attach(3); 
  }
  for(pos = 60; pos < 120; pos+=1){
      servoHead.write(pos);
   } 
   
   if(servoHead.read() > 118){
      servoHead.detach(); 
   }
}

void establishContact(){
   while(Serial.available() <= 0){
      Serial.write("peeqo");
   } 
}
