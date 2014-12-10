long prevMillis = 0;
int ledState = LOW;
int i = 0;
int ledPin = 6;

void setup(){
  pinMode(10, OUTPUT);
}

void loop(){
//  long currMillis = millis();
//  
//  
//  if(currMillis - prevMillis > 500){
//     prevMillis = currMillis;
//     if(ledState == LOW){
//        ledState = HIGH;
//     } else {
//        ledState = LOW; 
//     }
//     
//     digitalWrite(ledPin,ledState);
//  }

digitalWrite(10,HIGH);
}
