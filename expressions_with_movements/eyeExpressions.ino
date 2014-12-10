void allOff(){
   for(int i=22;i<41;i++){
      digitalWrite(i,LOW);
   } 
}

void fullEye(){
    for(int i = 22;i<41;i++){
       digitalWrite(i, HIGH); 
    }
}

void halfEye(){
  //turn outer lower rim on
   for(int i=22;i<29;i++){
      digitalWrite(i,HIGH);
   } 
   
    //turn inner lower rim on
   for(int i=34;i<38;i++){
      digitalWrite(i,HIGH); 
   }
   
   digitalWrite(40,HIGH);
   
   //turn outer above rim off
   for(int i=29;i<34;i++){
     digitalWrite(i,LOW);
   }

   //turn inner above rim off
   for(int i=38;i<40;i++){
      digitalWrite(i,LOW); 
   }
}

void happy() {
  //turn outer above rim on
  for(int i=28;i<34;i++){
     digitalWrite(i,HIGH); 
  }
  
  digitalWrite(22,HIGH);
  
  //turn lower outer rim off
  for(int i=23;i<28;i++){
     digitalWrite(i, LOW); 
  }
  
  //turn center off
  for(int i=34;i<41;i++){
     digitalWrite(i, LOW); 
  }
}

void sad() {
  //turn outer lower rim on
  for(int i=22;i<29;i++){
     digitalWrite(i, HIGH); 
  }
  
  //turn outer above rim off
  for(int i=29;i<34;i++){
     digitalWrite(i, LOW); 
  }
  
  //turn center off
  for(int i=34;i<41;i++){
     digitalWrite(i, LOW); 
  }
}


void flatEye(){
   digitalWrite(22,HIGH);
   digitalWrite(28, HIGH); 
   digitalWrite(34, HIGH);
   digitalWrite(37, HIGH);
   digitalWrite(40, HIGH);
   
   //turn outer lower rim off
   for(int i=23;i<28;i++){
      digitalWrite(i, LOW); 
   }
   
   //turn outer above rim off
   for(int i=29;i<34;i++){
      digitalWrite(i, LOW); 
   }
   
   //turn inner ones off
   digitalWrite(35, LOW);
   digitalWrite(36, LOW);
   digitalWrite(38, LOW);
   digitalWrite(39, LOW);
}
