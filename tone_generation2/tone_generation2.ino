#include "pitches.h"

long previousMillis = 0;       
long interval = 120;  

int melodyCount = 0;  // very good - happy / completion
int melodyMax = 9;
int melody[] = { 
NOTE_F3, NOTE_G4, NOTE_A5, NOTE_G6, NOTE_F3, NOTE_E6, NOTE_D4, NOTE_C4,PAUSE };
int duration[] = {100,100,100,50,50,50,100,250,500};

int melody2Count = 0;  // very good - happy/ processing
int melody2Max = 7;
int melody2[] = { 
NOTE_B3, NOTE_A4, NOTE_B6, NOTE_A6, NOTE_E3, NOTE_A4,PAUSE};
int duration2[] = {50,50,100,150,50,100, 500};

int melody3Count = 0;  // very good - processing
int melody3Max = 7;
int melody3[] = { 
NOTE_A3, NOTE_F4, NOTE_A4, NOTE_F5, NOTE_A3, NOTE_F3, PAUSE};
int duration3[] = {50,150,50,100,50,100, 500};

int melody4Count = 0;  //very good - happy
int melody4Max = 6;
int melody4[] = { 
NOTE_C4, NOTE_D5, NOTE_E6, NOTE_F5, NOTE_G6,PAUSE};
int duration4[] = {50,50,50,50,100,500};

int melody5Count = 0;  // good - sad angry
int melody5Max = 7;
int melody5[] = { 
NOTE_B2, NOTE_C2, NOTE_B2, NOTE_E2, NOTE_B3, NOTE_E3,PAUSE};
int duration5[] = {100,100,100,100,100,100,500};

int melody6Count = 0; // very good - thinking / processing
int melody6Max = 7;
int melody6[] = { 
NOTE_G4, NOTE_D5, NOTE_G6, NOTE_D6, NOTE_G5, NOTE_D5,PAUSE};
int duration6[] = {50,100,50,50,100,150,500};

int melody7Count = 0;  // good - angry
int melody7Max = 6;
int melody7[] = { 
NOTE_G3,PAUSE, NOTE_A3,PAUSE, NOTE_G3, PAUSE};
int duration7[] = {100,150,100,150,100, 500};

int melody8Count = 0;  // good angry - sad
int melody8Max = 6;
int melody8[] = { 
NOTE_C3,NOTE_C3,NOTE_B3, PAUSE, NOTE_A3,PAUSE};
int duration8[] = {100,100,150,200,400,500};

int melody9Count = 0;  //very good - happy
int melody9Max = 7;
int melody9[] = { 
NOTE_B6,NOTE_A6,NOTE_G6, NOTE_D6, NOTE_E6, NOTE_F6, PAUSE};
int duration9[] = {100,100,150,100,100,100, 500};

int melody10Count = 0;  //very good - angry
int melody10Max = 7;
int melody10[] = { 
NOTE_B2,NOTE_B4,NOTE_B3, NOTE_B3, NOTE_B2, NOTE_B2, PAUSE};
int duration10[] = {50,100,150,200,250,300, 500};

const int max = 8;
const int speaker = 12;
//int ledPin = 7;
//int intervalL = 200;
//long prevMillis = 0;
//int ledState = LOW;
//int i = 0;

void setup(){
//  pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop(){
  long currMillis = millis();
  
  
//  if(currMillis - prevMillis > intervalL){
//     prevMillis = currMillis;
//     if(ledState == LOW){
//        ledState = HIGH;
//     } else {
//        ledState = LOW; 
//     }
//     
//     digitalWrite(ledPin,ledState);
//  }
  if(Serial.available() > 0){
     char inByte = Serial.read();
    
    if(inByte == 'a'){
     playMelody(); 
    } 
    
    if(inByte == 's'){
     playMelody2(); 
    } 
    
    if(inByte == 'd'){
     playMelody3(); 
    } 
    
    if(inByte == 'f'){
     playMelody4(); 
    } 
    
    if(inByte == 'g'){
     playMelody5(); 
    } 
    
    if(inByte == 'h'){
     playMelody6(); 
    } 
    
    if(inByte == 'j'){
     playMelody7(); 
    } 
    
    if(inByte == 'k'){
     playMelody8(); 
    } 
    
    if(inByte == 'l'){
     playMelody9(); 
    } 
    
    if(inByte == 'z'){
     playMelody10(); 
    } 
    
  }
   //playMelody10(); 
   playMelody10();
   if(melodyCount == melodyMax){
      melodyCount = melodyMax;
   }
   if(melody2Count == melody2Max){
      melody2Count = melody2Max;
   }
   if(melody3Count == melody3Max){
      melody3Count = melody3Max;
   }
   if(melody4Count == melody4Max){
      melody4Count = melody4Max;
   }
   if(melody5Count == melody5Max){
      melody5Count = melody5Max;
   }
   if(melody6Count == melody6Max){
      melody6Count = melody6Max;
   }
   if(melody7Count == melody7Max){
      melody7Count = melody7Max;
   }
   if(melody8Count == melody8Max){
      melody8Count = melody8Max;
   }
   if(melody9Count == melody9Max){
      melody9Count = melody9Max;
   }
   if(melody10Count == melody10Max){
      melody10Count = melody10Max;
   }

}

void playMelody(){  
  if(melodyCount<=melodyMax) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration[melodyCount]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody[melodyCount],duration[melodyCount]);
      melodyCount++; 
    }
  }
} 

void playMelody2(){  
  if(melody2Count<=melody2Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration2[melody2Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody2[melody2Count],duration2[melody2Count]);
      melody2Count++; 
    }
  }
} 

void playMelody3(){  
  if(melody3Count<=melody3Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration3[melody3Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody3[melody3Count],duration3[melody3Count]);
      melody3Count++; 
    }
  }
} 

void playMelody4(){  
  if(melody4Count<=melody4Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration4[melody4Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody4[melody4Count],duration4[melody4Count]);
      melody4Count++; 
    }
  }
} 

void playMelody5(){  
  if(melody5Count<=melody5Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration5[melody5Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody5[melody5Count],duration5[melody5Count]);
      melody5Count++; 
    }
  }
} 

void playMelody6(){  
  if(melody6Count<=melody6Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration6[melody6Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody6[melody6Count],duration6[melody6Count]);
      melody6Count++; 
    }
  }
} 

void playMelody7(){  
  if(melody7Count<=melody7Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration7[melody7Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody7[melody7Count],duration7[melody7Count]);
      melody7Count++; 
    }
  }
} 

void playMelody8(){  
  if(melody8Count<=melody8Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration8[melody8Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody8[melody8Count],duration8[melody8Count]);
      melody8Count++; 
    }
  }
} 

void playMelody9(){  
  if(melody9Count<=melody9Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration9[melody9Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody9[melody9Count],duration9[melody9Count]);
      melody9Count++; 
    }
  }
} 

void playMelody10(){  
  if(melody10Count<=melody10Max) { 
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > duration10[melody10Count]*1.1) {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      // set the LED with the ledState of the variable:
      tone(speaker,melody10[melody10Count],duration10[melody10Count]);
      melody10Count++; 
    }
  }
} 
