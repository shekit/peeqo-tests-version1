void surprised() {
   //turn outer rim on
    for(int i=24;i<36;i++){
      tlc.setPWM(i,4095);
     tlc.write();
   } 
   
   //turn center dot on
   tlc.setPWM(42,4095);
     tlc.write();
   
   //turn inner rim off
   for(int i=36;i<42;i++){
      tlc.setPWM(i,0);
     tlc.write(); 
   }
   
   //turn outer rim on
    for(int i=0;i<12;i++){
      tlc.setPWM(i,4095);
     tlc.write();
   } 
   
   //turn center dot on
   tlc.setPWM(18,4095);
     tlc.write();
   
   //turn inner rim off
   for(int i=12;i<18;i++){
      tlc.setPWM(i,0);
     tlc.write(); 
   }
   
}

void angry() {
   
//  //turn outer rim left side on
//  for(int i=24;i<31;i++){
//     digitalWrite(i, HIGH);
//  } 
//  
//  //turn inner side rim on
//  for(int i=35;i<39;i++){
//     digitalWrite(i, HIGH); 
//  }
//  
//  //turn center on
//  digitalWrite(40, HIGH);
//  
//  //turn outer rim right side off
//  for(int i=31;i<35;i++){
//     digitalWrite(i, LOW); 
//  }
//  
//  //turn remaining lights off
//  digitalWrite(22, LOW);
//  digitalWrite(23, LOW);
//  digitalWrite(39, LOW);
}

void verySad() {
  
//   //turn lower outer right rim on
//  for(int i=22;i<27;i++){
//     digitalWrite(i, HIGH);
//  } 
//  
//  //turn top outer right and inner right on
//  for(int i=32;i<37;i++){
//     digitalWrite(i, HIGH); 
//  }
//  
//  //turn remaining on
//  for(int i=39;i<41;i++){
//     digitalWrite(i, HIGH); 
//  }
//
//
//  
//  //turn left outer upper rim off
//  for(int i=27;i<32;i++){
//     digitalWrite(i, LOW); 
//  }
//  
//  //turn inner upper left rim off
//  for(int i=37;i<39;i++){
//     digitalWrite(i, LOW); 
//  }
}

void dead() {
//   digitalWrite(30, HIGH);
//   digitalWrite(32, HIGH);
//   for(int i=38;i<41;i++){
//      digitalWrite(i, HIGH);
//   }
//   digitalWrite(24, HIGH);
//   digitalWrite(26, HIGH);
//   digitalWrite(35, HIGH);
//   digitalWrite(36, HIGH);
//
//   //turn remainder off
//   digitalWrite(22, LOW);
//   digitalWrite(23, LOW);
//   digitalWrite(25, LOW);
//   digitalWrite(27, LOW);
//   digitalWrite(28, LOW);
//   digitalWrite(29, LOW);
//   digitalWrite(31, LOW);
//   digitalWrite(33, LOW);
//   digitalWrite(34, LOW);
//   digitalWrite(37, LOW);   
}

void heart(){
   //turn inner core on
//   for(int i=34;i<41;i++){
//      digitalWrite(i, HIGH);
//   } 
//   
//   digitalWrite(25, HIGH);
//   digitalWrite(29, HIGH);
//   digitalWrite(30, HIGH);
//   digitalWrite(32, HIGH);
//   digitalWrite(33, HIGH);
//   
//   // turn rest off
//   for(int i=22;i<25;i++){
//      digitalWrite(i, LOW); 
//   }
//   
//   for(int i=26;i<29;i++){
//      digitalWrite(i, LOW); 
//   }
//   
//   digitalWrite(31, LOW);
}

void squint() {
//   digitalWrite(30, HIGH);
//   digitalWrite(38, HIGH);
//   digitalWrite(40, HIGH);
//   digitalWrite(36, HIGH);
//   digitalWrite(26, HIGH);
//   
//   for(int i =22;i<26;i++){
//      digitalWrite(i, LOW); 
//   }
//   
//   for(int i=31; i<34;i++){
//      digitalWrite(i, LOW); 
//   }
//   
//   for(int i=27;i<30;i++){
//      digitalWrite(i, LOW); 
//   }
//   
//   digitalWrite(34, LOW);
//   digitalWrite(35, LOW);
//   digitalWrite(37, LOW);
//   digitalWrite(39, LOW);
}

void setBlink(){
  //blinkEyeBool = !blinkEyeBool;
  blinkEyeBool = true;
  //blinkCount = 0;
  //Serial.println("blink");
}  

void blinkEye(){
   blinkCount++;
   if(blinkCount == blinkInterval*1){
     //digitalWrite(31, LOW);
     tlc.setPWM(9,0);
     tlc.write();
     tlc.setPWM(33,0);
     tlc.write();
     
   } else if(blinkCount == blinkInterval*2){
     tlc.setPWM(8,0);
     tlc.write();
     tlc.setPWM(10,0);
     tlc.write();
     tlc.setPWM(32,0);
     tlc.write();
     tlc.setPWM(34,0);
     tlc.write();
     //digitalWrite(30, LOW);
     //digitalWrite(32, LOW);
   } else if(blinkCount == blinkInterval*3){
   
     tlc.setPWM(31,0);
     tlc.write();
     tlc.setPWM(40,0);
     tlc.write();
     tlc.setPWM(41,0);
     tlc.write();
     tlc.setPWM(35,0);
     tlc.write();
     tlc.setPWM(7,0);
     tlc.write();
     tlc.setPWM(11,0);
     tlc.write();
     tlc.setPWM(16,0);
     tlc.write();
     tlc.setPWM(17,0);
     tlc.write();
     
   } else if(blinkCount == blinkInterval*4){
 
     tlc.setPWM(30,0);
     tlc.write();
     tlc.setPWM(39,0);
     tlc.write();
     tlc.setPWM(42,0);
     tlc.write();
     tlc.setPWM(36,0);
     tlc.write();
     tlc.setPWM(24,0);
     tlc.write();
     tlc.setPWM(0,0);
     tlc.write();
     tlc.setPWM(12,0);
     tlc.write();
     tlc.setPWM(18,0);
     tlc.write();
     tlc.setPWM(15,0);
     tlc.write();
     tlc.setPWM(6,0);
     tlc.write();
   } else if(blinkCount== blinkInterval*5){

     tlc.setPWM(29,0);
     tlc.write();
     tlc.setPWM(38,0);
     tlc.write();
     tlc.setPWM(37,0);
     tlc.write();
     tlc.setPWM(25,0);
     tlc.write();
     tlc.setPWM(1,0);
     tlc.write();
     tlc.setPWM(5,0);
     tlc.write();
     tlc.setPWM(13,0);
     tlc.write();
     tlc.setPWM(14,0);
     tlc.write();
   } else if(blinkCount == blinkInterval*6){

     tlc.setPWM(26,0);
     tlc.write();
     tlc.setPWM(28,0);
     tlc.write();
     tlc.setPWM(2,0);
     tlc.write();
     tlc.setPWM(4,0);
     tlc.write();
   } else if(blinkCount == blinkInterval*7){

     tlc.setPWM(27,0);
     tlc.write();
     tlc.setPWM(3,0);
     tlc.write();
   } else if(blinkCount == blinkInterval*9){
     tlc.setPWM(27,4095);
     tlc.write();
     tlc.setPWM(3,4095);
     tlc.write();
     
   } else if(blinkCount == blinkInterval*10){

     tlc.setPWM(26,4095);
     tlc.write();
     tlc.setPWM(28,4095);
     tlc.write();
     tlc.setPWM(2,4095);
     tlc.write();
     tlc.setPWM(4,4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*11){
      tlc.setPWM(29,4095);
     tlc.write();
     tlc.setPWM(38,4095);
     tlc.write();
     tlc.setPWM(37,4095);
     tlc.write();
     tlc.setPWM(25,4095);
     tlc.write();
     tlc.setPWM(1,4095);
     tlc.write();
     tlc.setPWM(5,4095);
     tlc.write();
     tlc.setPWM(13,4095);
     tlc.write();
     tlc.setPWM(14,4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*12){

     tlc.setPWM(30,4095);
     tlc.write();
     tlc.setPWM(39,4095);
     tlc.write();
     tlc.setPWM(42,4095);
     tlc.write();
     tlc.setPWM(36,4095);
     tlc.write();
     tlc.setPWM(24,4095);
     tlc.write();
     tlc.setPWM(0,4095);
     tlc.write();
     tlc.setPWM(12,4095);
     tlc.write();
     tlc.setPWM(18,4095);
     tlc.write();
     tlc.setPWM(15,4095);
     tlc.write();
     tlc.setPWM(6,4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*13){
     tlc.setPWM(31,4095);
     tlc.write();
     tlc.setPWM(40,4095);
     tlc.write();
     tlc.setPWM(41,4095);
     tlc.write();
     tlc.setPWM(35,4095);
     tlc.write();
     tlc.setPWM(7,4095);
     tlc.write();
     tlc.setPWM(11,4095);
     tlc.write();
     tlc.setPWM(16,4095);
     tlc.write();
     tlc.setPWM(17,4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*14){
     tlc.setPWM(8,4095);
     tlc.write();
     tlc.setPWM(10,4095);
     tlc.write();
     tlc.setPWM(32,4095);
     tlc.write();
     tlc.setPWM(34,4095);
     tlc.write();
   } else if(blinkCount == blinkInterval*15){
     tlc.setPWM(9,4095);
     tlc.write();
     tlc.setPWM(33,4095);
     tlc.write();
     blinkEyeBool = false;
     blinkCount = 0;
   }
    
}


