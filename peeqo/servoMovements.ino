
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
      sadServoTransition = false;
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
      happyServoTransition = false;
   } 
   
   beHappyPos += beHappySpeed;  
}

void beHappy(){
   servoHead.write((int)beHappyPos); 
}

/////////////////////////////
//       RESET HEAD        //
/////////////////////////////

void resetHeadMovement(){
   float resetHeadPos = servoHead.read();
   
   if(resetHeadPos >= resetHead){
     if(resetHeadPos == resetHead){
        resetHeadPos = resetHead;
        resetHeadSpeed = 0;
        resetHeadBoolean = false; 
     }
     
     resetHeadPos -= resetHeadSpeed;
     
   }
     
   if(resetHeadPos <= resetHead){
     if(resetHeadPos == resetHead){
        resetHeadPos = resetHead;
        resetHeadSpeed = 0;
        resetHeadBoolean = false;  
     }
    
     resetHeadPos += resetHeadSpeed; 
   }
      
}

void resetHeadServo(){
   //float resetHeadPos = servoHead.read();
   servoHead.write(90);

}

/////////////////////////////
//       RESET NECK        //
/////////////////////////////

void resetNeckMovement(){
  float resetNeckPos = servoNeck.read();
  
  if(resetNeckPos >= resetNeck){
     if(resetNeckPos == resetNeck){
        resetNeckPos = resetNeck;
        resetNeckSpeed = 0;
        resetNeckBoolean = false; 
     }
     
     resetNeckPos -= resetNeckSpeed;
     
   }
     
   if(resetNeckPos <= resetNeck){
     if(resetNeckPos == resetNeck){
        resetNeckPos = resetNeck;
        resetNeckSpeed = 0;
        resetNeckBoolean = false;  
     }
    
     resetNeckPos += resetNeckSpeed; 
   }
}

void resetNeckServo(){
   //float resetNeckPos = servoNeck.read();
   servoNeck.write(90); 
}

/////////////////////////////
//       WAKE UP           //
/////////////////////////////

void wakeUpMovement() {
    if(servoHead.read() >= 90){
      wakeUpPos = 90;
      wakeUpSpeed = 0;
      wakeUpServo = false;
   } 
   
   wakeUpPos += wakeUpSpeed;
  
}

void wakeUp(){
  servoHead.write((int)wakeUpPos);
}

/////////////////////////////
//       SLEEP             //
/////////////////////////////

void sleepMovement() {
    if(servoHead.read() <= intialServoHeadPos){
      sleepPos = intialServoHeadPos;
      sleepSpeed = 0;
      sleepServo = false;
   } 
   
   sleepPos -= sleepSpeed;
  
}

void sleep(){
  servoHead.write((int)sleepPos);
}

/////////////////////////////
//          DANCE          //
/////////////////////////////

void danceHeadMovement() {
  if(danceHeadPos >= danceHeadMax || danceHeadPos <= danceHeadMin){
      if(danceHeadPos >= danceHeadMax){
         danceHeadPos = danceHeadMax; 
      } else {
         danceHeadPos = danceHeadMin;
      }
      
      danceHeadSpeed *= -1;
   } 
   
   float prevVal = danceHeadPos;
   boolean transitioned = false;
   
   danceHeadPos += danceHeadSpeed;
   
   if(prevVal <90 && danceHeadPos >=90){
      transitioned = true; 
   }
   if(prevVal >=90 && danceHeadPos <90){
      transitioned = true; 
   }
   
   if(transitioned) {
      danceHeadShiftCount++;
      if(danceHeadShiftCount >= danceHeadShiftThresh){
         danceHeadSpeed = 0;
         danceHeadPos = 90;
         danceHeadShiftCount = 0;
         danceHeadBoolean = false;
      } 
   }
  
  
}

void danceNeckMovement() {
  if(danceNeckPos >= danceNeckMax || danceNeckPos <= danceNeckMin){
      if(danceNeckPos >= danceNeckMax){
         danceNeckPos = danceNeckMax; 
      } else {
         danceNeckPos = danceNeckMin;
      }
      
      danceNeckSpeed *= -1;
   } 
   
   float prevVal = danceNeckPos;
   boolean transitioned = false;
   
   danceNeckPos += danceNeckSpeed;
   
   if(prevVal <90 && danceNeckPos >=90){
      transitioned = true; 
   }
   if(prevVal >=90 && danceNeckPos <90){
      transitioned = true; 
   }
   
   if(transitioned) {
      danceNeckShiftCount++;
      if(danceNeckShiftCount >= danceNeckShiftThresh){
         danceNeckSpeed = 0;
         danceNeckPos = 90;
         danceNeckShiftCount = 0;
         danceNeckBoolean = false;
      } 
   }
}

void danceHead() {
  servoHead.write((int)danceHeadPos);
}

void danceNeck() {
  servoNeck.write((int)danceNeckPos);
}

///////////////////////////////
////       high 5           //
///////////////////////////////
//
//void highfiveMovement() {
//    if(servoArm.read() >= 130){
//      highfivePos = 130;
//      highfiveSpeed = 0;
//      highfiveServo = false;
//   } 
//   
//   highfivePos += highfiveSpeed;
//  
//}
//
//void highfive(){
//  servoArm.write((int)highfivePos);
//}
