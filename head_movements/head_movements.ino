#include <Servo.h>

Servo servoNeck;
Servo servoHead;


// global current position of each servo
float neckPos = 90;
float neckSpeed = 0;
float neckMax = 179;
float neckMin = 0;
int neckShiftCount = 0;
int neckShiftThresh = 10;

float sheadPos = 90;
float sheadSpeed = 0;
float sheadMax = 120;
float sheadMin = 30;
int sheadShiftCount = 0;
int sheadShiftThresh = 5;

float sayYesHeadPos = 90;
float sayYesHeadMax = 120;
float sayYesHeadMin = 30;
float sayYesHeadSpeed = 0;
float sayYesRepeatCount = 2;

boolean sayNo = false;
boolean sayYes = false;

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
    
    if(inByte == 'a'){
      sayNo = true;
      //headSpeed = 0.1;
      neckSpeed = 0.05;
      Serial.println("say no is true");
    }
    
    if(inByte == 'b'){
       sayYes = true;
       sheadSpeed = 0.5;
        Serial.println("say yes is true");
    }
    
  }
  
  if(sayNo){
     //updateHead();
      
      updateNeck();
        
      updateMotors(); 
      
      //sayNo = false;
  }
  
  if(sayYes) {
     updateHead(sheadPos, sheadMax, sheadMin, sheadSpeed, sheadShiftCount, sheadShiftThresh);
     updateHeadMotor(sheadPos);
  }
}

/////////////////////////////

void updateHeadPosition(float _headPos, float _headMax, float _headMin, float _headSpeed, int _repeatCount) {
   
   if(_headPos >= _headMax || _headPos <= _headMin){
      
     if(_headPos >= _headMax){
        _headPos = _headMax; 
     }else{
        _headPos = _headMin; 
     }
     
     _headSpeed *= -1;
   } 
   
   float prevValue = _headPos;
   boolean transitioned = false;
   
  _headPos += _headSpeed;
  
  if(prevValue < 90 && _headPos >= 90){
     transitioned = true; 
  }
  
  if(prevValue >= 90 && _headPos<90){
     transitioned = true; 
  }
  
  if(transitioned){
    Serial.println("transitioned");
     sheadShiftCount++;
    if(sheadShiftCount >= _repeatCount){
       sheadShiftCount = 0;
       _headSpeed = 0;
    } 
  }
}

void updateHead(float headPos, float headMax, float headMin, float headSpeed, int headShiftCount, int headShiftThresh){
  if(headPos>=headMax || headPos<=headMin){
    
    if(headPos>=headMax){
      headPos = headMax;
    }
    else{
      headPos = headMin;
    }
    
    headSpeed *= -1;
  }
  
  float prevVal = headPos;
  boolean transitioned = false;
  
  headPos += headSpeed;
  
  if(prevVal<90 && headPos>=90){
    transitioned = true;
  }
  if(prevVal>=90 && headPos<90){
    transitioned = true;
  }
  
  if(transitioned){
    headShiftCount++;
    if(headShiftCount>=headShiftThresh){
      headShiftCount = 0;
      headSpeed = 0;
    }
  }
}

/////////////////////////////

void updateNeck(){
  if(neckPos>=neckMax || neckPos<=neckMin){
    
    if(neckPos>=neckMax){
      neckPos = neckMax;
    }
    else{
      neckPos = neckMin;
    }
    
    neckSpeed *= -1;
  }
  
  float prevVal = neckPos;
  boolean transitioned = false;
  
  neckPos += neckSpeed;
  
  if(prevVal<90 && neckPos>=90){
    transitioned = true;
  }
  if(prevVal>=90 && neckPos<90){
    transitioned = true;
  }
  
  if(transitioned){
    neckShiftCount++;
    if(neckShiftCount>=neckShiftThresh){
      neckShiftCount = 0;
      neckSpeed = 0;
      sayNo = false;
      Serial.println("say no is falsE");
    }
  }
}

/////////////////////////////

void updateMotors(){
  servoNeck.write((int)neckPos);
  servoHead.write((int)headPos);
}

void updateHeadMotor(float _headPos){
  servoHead.write((int)_headPos);
}

void updateNeckMotor(float _neckPos) {
  servoNeck.write((int)_neckPos);
}

/////////////////////////////
