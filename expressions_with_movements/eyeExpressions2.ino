void surprised() {
   //turn outer rim on
    for(int i=22;i<34;i++){
      digitalWrite(i, HIGH);
   } 
   
   //turn center dot on
   digitalWrite(40, HIGH);
   
   //turn inner rim off
   for(int i=34;i<40;i++){
      digitalWrite(i, LOW); 
   }
}

void angry() {
   
  //turn outer rim left side on
  for(int i=24;i<31;i++){
     digitalWrite(i, HIGH);
  } 
  
  //turn inner side rim on
  for(int i=35;i<39;i++){
     digitalWrite(i, HIGH); 
  }
  
  //turn center on
  digitalWrite(40, HIGH);
  
  //turn outer rim right side off
  for(int i=31;i<35;i++){
     digitalWrite(i, LOW); 
  }
  
  //turn remaining lights off
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  digitalWrite(39, LOW);
}

void verySad() {
  
   //turn lower outer right rim on
  for(int i=22;i<27;i++){
     digitalWrite(i, HIGH);
  } 
  
  //turn top outer right and inner right on
  for(int i=32;i<37;i++){
     digitalWrite(i, HIGH); 
  }
  
  //turn remaining on
  for(int i=39;i<41;i++){
     digitalWrite(i, HIGH); 
  }


  
  //turn left outer upper rim off
  for(int i=27;i<32;i++){
     digitalWrite(i, LOW); 
  }
  
  //turn inner upper left rim off
  for(int i=37;i<39;i++){
     digitalWrite(i, LOW); 
  }
}

void dead() {
   digitalWrite(30, HIGH);
   digitalWrite(32, HIGH);
   for(int i=38;i<41;i++){
      digitalWrite(i, HIGH);
   }
   digitalWrite(24, HIGH);
   digitalWrite(26, HIGH);
   digitalWrite(35, HIGH);
   digitalWrite(36, HIGH);

   //turn remainder off
   digitalWrite(22, LOW);
   digitalWrite(23, LOW);
   digitalWrite(25, LOW);
   digitalWrite(27, LOW);
   digitalWrite(28, LOW);
   digitalWrite(29, LOW);
   digitalWrite(31, LOW);
   digitalWrite(33, LOW);
   digitalWrite(34, LOW);
   digitalWrite(37, LOW);   
}

void heart(){
   //turn inner core on
   for(int i=34;i<41;i++){
      digitalWrite(i, HIGH);
   } 
   
   digitalWrite(25, HIGH);
   digitalWrite(29, HIGH);
   digitalWrite(30, HIGH);
   digitalWrite(32, HIGH);
   digitalWrite(33, HIGH);
   
   // turn rest off
   for(int i=22;i<25;i++){
      digitalWrite(i, LOW); 
   }
   
   for(int i=26;i<29;i++){
      digitalWrite(i, LOW); 
   }
   
   digitalWrite(31, LOW);
}

void squint() {
   digitalWrite(30, HIGH);
   digitalWrite(38, HIGH);
   digitalWrite(40, HIGH);
   digitalWrite(36, HIGH);
   digitalWrite(26, HIGH);
   
   for(int i =22;i<26;i++){
      digitalWrite(i, LOW); 
   }
   
   for(int i=31; i<34;i++){
      digitalWrite(i, LOW); 
   }
   
   for(int i=27;i<30;i++){
      digitalWrite(i, LOW); 
   }
   
   digitalWrite(34, LOW);
   digitalWrite(35, LOW);
   digitalWrite(37, LOW);
   digitalWrite(39, LOW);
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
     digitalWrite(31, LOW);
   } else if(blinkCount == blinkInterval*2){
     digitalWrite(30, LOW);
     digitalWrite(32, LOW);
   } else if(blinkCount == blinkInterval*3){
     digitalWrite(29, LOW);
     digitalWrite(38, LOW);
     digitalWrite(39, LOW);
     digitalWrite(33, LOW);
   } else if(blinkCount == blinkInterval*4){
     digitalWrite(28, LOW);
     digitalWrite(37, LOW);
     digitalWrite(40, LOW);
     digitalWrite(34, LOW);
     digitalWrite(22, LOW);
   } else if(blinkCount== blinkInterval*5){
     digitalWrite(27, LOW);
     digitalWrite(36, LOW);
     digitalWrite(35, LOW);
     digitalWrite(23, LOW);
   } else if(blinkCount == blinkInterval*6){
     digitalWrite(24, LOW);
     digitalWrite(26, LOW);
   } else if(blinkCount == blinkInterval*7){
     digitalWrite(25, LOW);
   } else if(blinkCount == blinkInterval*9){
     digitalWrite(25, HIGH);
   } else if(blinkCount == blinkInterval*10){
     digitalWrite(24, HIGH);
     digitalWrite(26, HIGH);
   } else if(blinkCount == blinkInterval*11){
     digitalWrite(23, HIGH);
     digitalWrite(36, HIGH);
     digitalWrite(35, HIGH);
     digitalWrite(27, HIGH);
   } else if(blinkCount == blinkInterval*12){
     digitalWrite(28, HIGH);
     digitalWrite(37, HIGH);
     digitalWrite(40, HIGH);
     digitalWrite(34, HIGH);
     digitalWrite(22, HIGH);
   } else if(blinkCount == blinkInterval*13){
     digitalWrite(29, HIGH);
     digitalWrite(38, HIGH);
     digitalWrite(39, HIGH);
     digitalWrite(33, HIGH);
   } else if(blinkCount == blinkInterval*14){
     digitalWrite(30, HIGH);
     digitalWrite(32, HIGH);
   } else if(blinkCount == blinkInterval*15){
     digitalWrite(31, HIGH);
     blinkEyeBool = false;
     blinkCount = 0;
   }
    
}


