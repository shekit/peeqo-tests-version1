#include <Servo.h>

Servo servoNeck;
Servo servoHead;



// SAY NO 
float sayNoPos = 90;
float sayNoSpeed = 0; //set in the serial event
float sayNoMax = 179;
float sayNoMin = 0;
int sayNoShiftCount = 0;
int sayNoShiftThresh = 4;
boolean sayNoBoolean = false;

// SAY YES
float sayYesPos = 90;
float sayYesSpeed = 0;  //set in the serial event
float sayYesMax = 120;
float sayYesMin = 30;
int sayYesShiftCount = 0;
int sayYesShiftThresh = 4;
boolean sayYesBoolean = false;

// BE SAD
float beSadPos = 90;
float beSadMin = 20;
float beSadSpeed = 0;
boolean beSadBoolean = false;

// BE HAPPY
float beHappyPos = 90;
float beHappyMax = 120;
float beHappySpeed = 0;
boolean beHappyBoolean = false;

/////////////////////////////

void setup(){
   Serial.begin(9600);
   servoNeck.attach(2);
   servoHead.attach(3);
}

/////////////////////////////

void loop(){
  if(Serial.available() > 0){
    char inByte = Serial.read();
    
    if(inByte == 'n'){
       sayNoBoolean = true;
       sayNoSpeed = 0.1;
    }
    
    if(inByte == 'y'){
       sayYesBoolean = true;
       sayYesSpeed = 0.05;
    }
    
    if(inByte == 's'){
      beSadPos = 90;
      beSadBoolean = true;
      beSadSpeed = 0.01;
    }
    
    if(inByte == 'h'){
      // resetting variables otherwise screws up speed of movement
      beHappyPos = 90;
      beHappyBoolean = true;
      beHappySpeed = 0.005;
    }
    
  }
    
  if(sayNoBoolean){
     sayNoMovement();
     sayNo(); 
  }
  
  if(sayYesBoolean){
     sayYesMovement();
     sayYes(); 
  }
  
  if(beSadBoolean) {
     beSadMovement();
     beSad(); 
  }
  
  if(beHappyBoolean){
     beHappyMovement();
    beHappy(); 
  }
}

/////////////////////////////
//        SAY NO           //
/////////////////////////////


void sayNoMovement(){
   if(sayNoPos >= sayNoMax || sayNoPos <= sayNoMin){
      if(sayNoPos >= sayNoMax){
         sayNoPos = sayNoMax; 
      } else {
         sayNoPos = sayNoMin;
      }
      
      sayNoSpeed *= -1;
   } 
   
   float prevVal = sayNoPos;
   boolean transitioned = false;
   
   sayNoPos += sayNoSpeed;
   
   if(prevVal <90 && sayNoPos >=90){
      transitioned = true; 
   }
   if(prevVal >=90 && sayNoPos <90){
      transitioned = true; 
   }
   
   if(transitioned) {
      sayNoShiftCount++;
      if(sayNoShiftCount >= sayNoShiftThresh){
         sayNoSpeed = 0;
         sayNoPos = 90;
         sayNoShiftCount = 0;
         sayNoBoolean = false;
      } 
   }  
}

void sayNo(){
   servoNeck.write((int)sayNoPos); 
}



/////////////////////////////
//        SAY YES          //
/////////////////////////////


void sayYesMovement(){
   if(sayYesPos >= sayYesMax || sayYesPos <= sayYesMin){
      if(sayYesPos >= sayYesMax){
         sayYesPos = sayYesMax; 
      } else {
         sayYesPos = sayYesMin;
      }
      
      sayYesSpeed *= -1;
   } 
   
   float prevVal = sayYesPos;
   boolean transitioned = false;
   
   sayYesPos += sayYesSpeed;
   //Serial.println(servoHead.read());
   if(prevVal <90 && sayYesPos >=90){
      transitioned = true; 
   }
   if(prevVal >=90 && sayYesPos <90){
      transitioned = true; 
   }
   
   if(transitioned) {
      sayYesShiftCount++;
      if(sayYesShiftCount >= sayYesShiftThresh){
         sayYesSpeed = 0;
         sayYesPos = 90;
         sayYesShiftCount = 0;
         sayYesBoolean = false;
      } 
   }  
}

void sayYes(){
   servoHead.write((int)sayYesPos); 
}

/////////////////////////////
//        BE SAD           //
/////////////////////////////


void beSadMovement(){
   if(beSadPos <= beSadMin){
      beSadPos = beSadMin;
      beSadSpeed = 0;
      beSadBoolean = false;
   } 
   
   beSadPos -= beSadSpeed;  
}

void beSad(){
   servoHead.write((int)beSadPos); 
}

/////////////////////////////
//        BE HAPPY         //
/////////////////////////////


void beHappyMovement(){
   if(beHappyPos >= beHappyMax){
      beHappyPos = beHappyMax;
      beHappySpeed = 0;
      beHappyBoolean = false;
   } 
   
   beHappyPos += beHappySpeed;  
}

void beHappy(){
   servoHead.write((int)beHappyPos); 
}
