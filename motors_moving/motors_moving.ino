#include <Servo.h>

Servo servoNeck;
Servo servoHead;
int servoPinNeck = 3;
int servoPinHead = 5;

void setup(){
  Serial.begin(9600);
  servoNeck.attach(servoPinNeck);
  servoHead.attach(servoPinHead);
}

void loop(){
  //int servoAngleNeck; 10;
  //int servoAngleHead; 10;
  
//  servoNeck.write(servoAngleNeck);
//  servoHead.write(servoAngleHead);
  
  for(int pos = 0;pos<180;pos+=1){
     servoNeck.write(pos);
    servoHead.write(pos);
   delay(15); 
  }
  for(int pos = 60;pos>=1;pos-=1){
    servoNeck.write(pos);
    servoHead.write(pos);
    delay(15);
  }
}


