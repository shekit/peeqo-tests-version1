//Left Eye
int ltopLed1 = 2;
int ltopLed2 = 3;
int lmiddleLed1 = 4;
int lmiddleLed2 =5;
int lmiddleLed3=6;
int lbottomLed1=7;
int lbottomLed2=8;


//Right Eye 
int rtopLed1=9;
int rtopLed2=10;
int rmiddleLed1=11;
int rmiddleLed2=12;
int rmiddleLed3=13;
int rbottomLed1=14;
int rbottomLed2=15;

//button
int button = 16;
int prevButtonState = 0;
boolean changeCount = false;

int count = 0;

void setup(){
  Serial.begin(9600);
   for(int i = 2;i<16;i++){
      pinMode(i, OUTPUT);
   } 
   pinMode(button, INPUT);
}

void loop() {
  
  int currentButtonState = digitalRead(button);
  
  if(currentButtonState != prevButtonState){
     count++; 
     Serial.println("change");
  }
  
  if(count == 0){
    for(int i=2;i<16;i++){
        digitalWrite(i,LOW);
    }
  } else if(count == 1) {
    happy();
  } else if(count ==2){
    sad();
  } else if(count == 3){
    halfEye();
  } else if(count == 4){
    dontCare();    
  } else if(count == 5){
    full();
  } else if(count == 6){
     surprised(); 
  }
  
  if(count > 6){
    count = 0;  
  }

  
  prevButtonState = currentButtonState;
    
}

void happy(){
  digitalWrite(ltopLed1, HIGH);
  digitalWrite(ltopLed2,HIGH);
  digitalWrite(lmiddleLed1, HIGH);
  digitalWrite(lmiddleLed3, HIGH);
  
  digitalWrite(rtopLed1, HIGH);
  digitalWrite(rtopLed2,HIGH);
  digitalWrite(rmiddleLed1, HIGH);
  digitalWrite(rmiddleLed3, HIGH);
  
  digitalWrite(lbottomLed1,LOW);
  digitalWrite(lbottomLed2, LOW);
  digitalWrite(lmiddleLed2, LOW);
  
  digitalWrite(rbottomLed1,LOW);
  digitalWrite(rbottomLed2, LOW);
  digitalWrite(rmiddleLed2, LOW);
}

void sad(){
  digitalWrite(lbottomLed1, HIGH);
  digitalWrite(lbottomLed2,HIGH);
  digitalWrite(lmiddleLed1, HIGH);
  digitalWrite(lmiddleLed3, HIGH);
  
  digitalWrite(rbottomLed1, HIGH);
  digitalWrite(rbottomLed2,HIGH);
  digitalWrite(rmiddleLed1, HIGH);
  digitalWrite(rmiddleLed3, HIGH);
  
  digitalWrite(ltopLed1,LOW);
  digitalWrite(ltopLed2, LOW);
  digitalWrite(lmiddleLed2, LOW);
  
  digitalWrite(rtopLed1,LOW);
  digitalWrite(rtopLed2, LOW);
  digitalWrite(rmiddleLed2, LOW);
}

void halfEye(){
  digitalWrite(lbottomLed1, HIGH);
  digitalWrite(lbottomLed2,HIGH);
  digitalWrite(lmiddleLed1, HIGH);
  digitalWrite(lmiddleLed2,HIGH);
  digitalWrite(lmiddleLed3, HIGH);
  
  digitalWrite(rbottomLed1, HIGH);
  digitalWrite(rbottomLed2,HIGH);
  digitalWrite(rmiddleLed1, HIGH);
  digitalWrite(rmiddleLed2,HIGH);
  digitalWrite(rmiddleLed3, HIGH);
  
  digitalWrite(ltopLed1,LOW);
  digitalWrite(ltopLed2, LOW);
  
  digitalWrite(rtopLed1,LOW);
  digitalWrite(rtopLed2, LOW);
}

void dontCare(){
  digitalWrite(lmiddleLed1, HIGH);
  digitalWrite(lmiddleLed2,HIGH);
  digitalWrite(lmiddleLed3, HIGH);
  
  digitalWrite(rmiddleLed1, HIGH);
  digitalWrite(rmiddleLed2,HIGH);
  digitalWrite(rmiddleLed3, HIGH);
  
  digitalWrite(ltopLed1,LOW);
  digitalWrite(ltopLed2, LOW);
  digitalWrite(lbottomLed1,LOW);
  digitalWrite(lbottomLed2, LOW);
  
  digitalWrite(rtopLed1,LOW);
  digitalWrite(rtopLed2, LOW);
  digitalWrite(rbottomLed1,LOW);
  digitalWrite(rbottomLed2, LOW); 

}

void full(){
  digitalWrite(ltopLed1, HIGH);
  digitalWrite(ltopLed2,HIGH);
  digitalWrite(lbottomLed1, HIGH);
  digitalWrite(lbottomLed2,HIGH);
  digitalWrite(lmiddleLed1, HIGH);
  digitalWrite(lmiddleLed2,HIGH);
  digitalWrite(lmiddleLed3, HIGH);
  
  digitalWrite(rtopLed1, HIGH);
  digitalWrite(rtopLed2,HIGH);
  digitalWrite(rbottomLed1, HIGH);
  digitalWrite(rbottomLed2,HIGH);
  digitalWrite(rmiddleLed1, HIGH);
  digitalWrite(rmiddleLed2,HIGH);
  digitalWrite(rmiddleLed3, HIGH);
}

void surprised() {
  digitalWrite(ltopLed1, HIGH);
  digitalWrite(ltopLed2,HIGH);
  digitalWrite(lbottomLed1, HIGH);
  digitalWrite(lbottomLed2,HIGH);
  digitalWrite(lmiddleLed1, HIGH);
  digitalWrite(lmiddleLed3, HIGH);
  
  digitalWrite(rtopLed1, HIGH);
  digitalWrite(rtopLed2,HIGH);
  digitalWrite(rbottomLed1, HIGH);
  digitalWrite(rbottomLed2,HIGH);
  digitalWrite(rmiddleLed1, HIGH);
  digitalWrite(rmiddleLed3, HIGH);
  
  digitalWrite(lmiddleLed2, LOW);
  digitalWrite(rmiddleLed2, LOW);
}
