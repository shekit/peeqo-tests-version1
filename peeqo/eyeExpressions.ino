void allOff(){

   for(int i=0;i<19;i++){
     tlc.setPWM(i,0);
     tlc.write(); 
  }
  for(int i = 24; i < 43; i++){
     tlc.setPWM(i,0);
     tlc.write(); 
  }
}

void fullEye(){
    for(int i=0;i<19;i++){
     tlc.setPWM(i,4095);
     tlc.write(); 
  }
  for(int i = 24; i < 43; i++){
     tlc.setPWM(i,4095);
     tlc.write(); 
  }
}

void halfEye(){
  //turn outer lower rim on
   for(int i=0;i<7;i++){
      tlc.setPWM(i,4095);
      tlc.write();
   } 
   
    //turn inner lower rim on
   for(int i=12;i<16;i++){
      tlc.setPWM(i,4095);
      tlc.write(); 
   }
   
   tlc.setPWM(18,4095);
      tlc.write();
   
   //turn outer above rim off
   for(int i=7;i<12;i++){
     tlc.setPWM(i,0);
      tlc.write();
   }

   //turn inner above rim off
   for(int i=16;i<18;i++){
       tlc.setPWM(i,0);
      tlc.write(); 
   }
}

void happy() {
  //turn outer above rim on
  for(int i=30;i<36;i++){
     tlc.setPWM(i,4095);
      tlc.write();  
  }
  
  tlc.setPWM(24,4095);
      tlc.write(); 
  
  //turn lower outer rim off
  for(int i=25;i<30;i++){
     tlc.setPWM(i,0);
      tlc.write();  
  }
  
  //turn center off
  for(int i=36;i<43;i++){
     tlc.setPWM(i,0);
      tlc.write();  
  }
  
  
  //turn outer above rim on
  for(int i=6;i<12;i++){
     tlc.setPWM(i,4095);
      tlc.write();  
  }
  
  tlc.setPWM(0,4095);
      tlc.write(); 
  
  //turn lower outer rim off
  for(int i=1;i<6;i++){
     tlc.setPWM(i,0);
      tlc.write();  
  }
  
  //turn center off
  for(int i=12;i<19;i++){
     tlc.setPWM(i,0);
      tlc.write(); 
  }
  
  //turn outer lower rim on
  for(int i=0;i<7;i++){
     tlc.setPWM(i,4095);
      tlc.write();  
  }
  
  //turn outer above rim off
  for(int i=7;i<12;i++){
    tlc.setPWM(i,0);
      tlc.write();  
  }
  
  //turn center off
  for(int i=33;i<19;i++){
     tlc.setPWM(i,0);
      tlc.write(); 
  }
}

void sad() {
  //turn outer lower rim on
  for(int i=24;i<31;i++){
     tlc.setPWM(i,4095);
      tlc.write();  
  }
  
  //turn outer above rim off
  for(int i=31;i<36;i++){
    tlc.setPWM(i,0);
      tlc.write();  
  }
  
  //turn center off
  for(int i=36;i<43;i++){
     tlc.setPWM(i,0);
      tlc.write(); 
  }
}


void flatEye(){
//   digitalWrite(22,HIGH);
//   digitalWrite(28, HIGH); 
//   digitalWrite(34, HIGH);
//   digitalWrite(37, HIGH);
//   digitalWrite(40, HIGH);
//   
//   //turn outer lower rim off
//   for(int i=25;i<30;i++){
//      digitalWrite(i, LOW); 
//   }
//   
//   //turn outer above rim off
//   for(int i=29;i<34;i++){
//      digitalWrite(i, LOW); 
//   }
//   
//   //turn inner ones off
//   digitalWrite(35, LOW);
//   digitalWrite(36, LOW);
//   digitalWrite(38, LOW);
//   digitalWrite(39, LOW);
}
