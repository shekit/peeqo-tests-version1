int count = 0;
int button = 22;
int prevButtonState = 0;
boolean changeCount = false;

void setup() {
   for(int i = 2; i<21;i++){
      pinMode(i, OUTPUT);
   } 
   
   pinMode(button, INPUT);
}

void loop() {
  int currentButtonState = digitalRead(button);
  
  if(currentButtonState != prevButtonState){
     count++; 
  }
  
  if(count == 0){
    for(int i=2;i<21;i++){
        digitalWrite(i,LOW);
    }
  } else if(count == 1) {
    happy();
  } else if(count ==2){
    sad();
  } else if(count == 3){
     full(); 
  } else if(count == 4){
     angry(); 
  } else if(count == 5){
     halfEye(); 
  } else if(count == 6){
     outerRim(); 
  }
  
//  else if(count == 3){
//    halfEye();
//  } else if(count == 4){
//    dontCare();    
//  } else if(count == 5){
//    full();
//  } else if(count == 6){
//     surprised(); 
//  }
  
  if(count > 6){
    count = 0;  
  }

  
  prevButtonState = currentButtonState;

}

void happy(){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(13,HIGH); 
  
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(14,LOW);
  digitalWrite(15,LOW);
  digitalWrite(16,LOW);
  digitalWrite(17,LOW);
  digitalWrite(18,LOW);
  digitalWrite(19, LOW);
  digitalWrite(20, LOW);
}

void sad() {
  
  digitalWrite(9,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(14,HIGH);
  digitalWrite(17,HIGH);
  digitalWrite(18,HIGH);
  digitalWrite(19,HIGH);
  digitalWrite(20,HIGH);
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(15,LOW);
  digitalWrite(16,LOW);
}

void full(){
   for(int i=2;i<21;i++){
      digitalWrite(i,HIGH);
   } 
}

void angry(){
   
   digitalWrite(9,HIGH);
   digitalWrite(10,HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(13,HIGH);
   
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   digitalWrite(14,LOW);
   digitalWrite(15,LOW);
   digitalWrite(16,LOW);
   digitalWrite(17,LOW);
   digitalWrite(18,LOW);
   digitalWrite(19,LOW);
   digitalWrite(20, LOW);
   
}

void halfEye() {
  digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   
   for(int i=9;i<21;i++){
      digitalWrite(i,HIGH); 
   }
}

void outerRim(){
   digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(13,HIGH); 
  digitalWrite(14,HIGH);
  digitalWrite(17,HIGH);
  digitalWrite(18,HIGH);
  digitalWrite(19,HIGH);
  digitalWrite(20,HIGH);
  
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(10, LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
}

