#include <Servo.h>
#include "Timer.h"

#include "Adafruit_TLC5947.h"

// How many boards do you have chained?
#define NUM_TLC5974 2

#define data   4
#define clock   7
#define latch   8
#define oe -1 //  -1  // set to -1 to not use the enable pin (its optional)

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch);

//PIEZO
int piezo = A0;

// SERVO VARIABLES
Servo servoNeck;
Servo servoHead;
Servo servoArm;
float intialServoHeadPos = 90;
float initialServoNeckPos = 90;
float initialServoArmPos = 10;

// SAY NO 
float sayNoPos = 90;
float sayNoSpeed = 30; //set in the serial event
float sayNoMax = 129;
float sayNoMin = 0;
int sayNoShiftCount = 0;
int sayNoShiftThresh = 4;
boolean sayNoBoolean = false;

// SAY YES
float sayYesPos = 90;
float sayYesSpeed = 0;  //set in the serial event
float sayYesMax = 100;
float sayYesMin = 10;
int sayYesShiftCount = 0;
int sayYesShiftThresh = 4;
boolean sayYesBoolean = false;

// BE SAD
float beSadPos = 90;
float beSadMin = 80;
float beSadSpeed = 0;
boolean beSadBoolean = false;

// BE HAPPY
float beHappyPos = 90;
float beHappyMax = 100;
float beHappySpeed = 0;
boolean beHappyBoolean = false;

// RESET HEAD
float resetHead = 90;
float resetHeadSpeed = 0;
boolean resetHeadBoolean = false;

// RESET NECK
float resetNeck = 90;
float resetNeckSpeed = 0;
boolean resetNeckBoolean = false;

// DANCE NECK 
float danceNeckPos = 90;
float danceNeckSpeed = 0; //set in the serial event
float danceNeckMax = 150;
float danceNeckMin = 30;
int danceNeckShiftCount = 0;
int danceNeckShiftThresh = 4;
boolean danceNeckBoolean = false;

// DANCE HEAD
float danceHeadPos = 90;
float danceHeadSpeed = 0;  //set in the serial event
float danceHeadMax = 110;
float danceHeadMin = 80;
int danceHeadShiftCount = 0;
int danceHeadShiftThresh = 8;
boolean danceHeadBoolean = false;

// BUTTON VARIABLES
int count = 0;
int button = 52;
int prevButtonState = 0;

// HEART LED FADE VARIABLES
float fadeValue = 30;
float fadeSpeed = 0.04;
int fadeLed = 10;

// BLINKING EYE VARIABLES
Timer t;
boolean blinkEyeBool = false;
int blinkCount = 0;
boolean atRest = false;
int blinkInterval = 300;

// SAD EYE TRANSITION
int sadCount = 0;
boolean sadTransitionBoolean = false;
int sadInterval = 250;
boolean sadServoTransition = false;

// HAPPY EYE TRANSITION
int happyCount = 0;
boolean happyTransitionBoolean = false;
int happyInterval = 250;
boolean happyServoTransition = false;

// WAKE UP 
int wakeUpCount = 0;
int wakeUpInterval = 400;
long previousWakeUpMillis = 0;
boolean wakeUpBoolean = false;
boolean wakeUpState = false;
float wakeUpPos = intialServoHeadPos;
float wakeUpSpeed = 0;
boolean wakeUpServo = false;
boolean stopBlink = false;

// HIGH FIVE 
int highfiveCount = 0;
int highfiveInterval = 400;
long previousHighFiveMillis = 0;
boolean highfiveBoolean = false;
boolean highfiveState = false;
//float highfivePos = intialServoArmPos;
float highfiveSpeed = 0;
boolean highfiveServo = false;
//boolean stopBlink = false;

// SLEEP
int sleepCount = 0;
int sleepInterval = 200;
long previousSleepMillis = 0;
boolean sleepBoolean = false;
boolean sleepState = false;
float sleepPos = 90;
float sleepSpeed = 0;
boolean sleepServo = false;

//////////// SETUP ///////////////

void setup(){
   Serial.begin(9600);
//   for(int i=22;i<41;i++){
//      pinMode(i, OUTPUT);
//      //digitalWrite(i, HIGH); 
//   }
   tlc.begin();
   //pinMode(button, INPUT);
   servoNeck.attach(6);
   servoHead.attach(9);
   servoArm.attach(5);
   servoArm.write(initialServoArmPos);
   servoHead.write(intialServoHeadPos);
   t.every(5000, setBlink);
   //put in wake up & sleep
}

///////// LOOP ////////////////

void loop(){
  if(Serial.available() > 0){
     char inByte = Serial.read();
    
     if(inByte == 'w'){
        wakeUpState = true;
        wakeUpCount = 0;
        wakeUpServo = true;
        stopBlink = false; // so that you can wake him up again
        wakeUpSpeed = 0.01;
        sleepPos = 90; // reset it so as to be able to switch correctly between awake and asleep
     }
     
//     if(inByte == 'f'){
//        highfiveState = true;
//        wakeUpCount = 0;
//        wakeUpServo = true;
//        stopBlink = false; // so that you can wake him up again
//        wakeUpSpeed = 0.01;
//        sleepPos = 90; // reset it so as to be able to switch correctly between awake and asleep
//     }
    
     
     
     if(inByte == 'g'){
        sleepState = true;
        atRest = false;
        sleepCount = 0;
        sleepServo = true;
        sleepSpeed = 0.01; 
        wakeUpPos = intialServoHeadPos;  // reset it so as to be able to switch correctly between awake and asleep
     }
     
     
     if(inByte == 'n'){
        atRest = false;
        sayNoBoolean = true;
        sayNoSpeed = 0.1;
     } 
     
     if(inByte == 'y'){
       atRest = false;
       sayYesBoolean = true;
       sayYesSpeed = 0.05;
     }
    
    if(inByte == 's'){
      atRest = false;
      beSadPos = 90;
      beSadBoolean = true;
      beSadSpeed = 0.01;
    }
    
    if(inByte == 'h'){
      atRest = false;
      // resetting variables otherwise screws up speed of movement
      beHappyPos = 90;
      beHappyBoolean = true;
      beHappySpeed = 0.005;
    }
    
    if(inByte == 'r'){  //blinking slowing down when i call this... weird!! Is it cause of servo, if I reset booleans it slows it down, if I call function directly its fine
       fullEye();
       wakeUpState = false;
       atRest = true;
       blinkCount = 0;
       blinkEyeBool = true;
       //resetHeadBoolean = true;
       //resetNeckBoolean = true;
        resetHeadServo();
        resetNeckServo();
        sleepPos = 90; // set this so it transitions correctly to sleep
    }
    
    if(inByte == 'b'){   //blinking does not slow down if I call just this.. so WEIRD
       blinkCount = 0;
       atRest = true; 
    }
    
    if(inByte == 'v'){
       atRest = false;
       setSad(); 
       sadServoTransition = true;
       beSadPos = 90;
       beSadSpeed = 0.01;
    }
    
    if(inByte == 'm'){
       atRest = false;
       setHappy(); 
       happyServoTransition = true;
       beHappyPos = 90;
       beHappySpeed = 0.005;
    }
    
    if(inByte == 'd'){
      atRest = false;
      danceNeckBoolean = true;
      danceHeadBoolean = true;
      danceHeadSpeed = 0.5;
      danceNeckSpeed = 0.1;
    }
    
     
  } // end of Serial available if
  
  t.update();
  // only blink when no other action is happening
  if(atRest){
    // t.update(); 
  }
  
  if(atRest && blinkEyeBool){
     blinkEye(); 
  }
    
  // wake him up
  if(wakeUpState){
     wakeUpEyes();
     if(!stopBlink){
       blinkInterval = 100;
       blinkEye();
     }
  }
  
  if(wakeUpServo){
     wakeUpMovement();
     wakeUp(); 
  }
  
  if(sleepState){
     // do eye stuff here
     sleepEyes();
  }
  
  if(sleepServo) {
     sleepMovement();
     sleep(); 
  }
  
  if(sayNoBoolean){
     sayNoMovement();
     sayNo();
     sad(); 
  }
  
  if(sayYesBoolean){
     sayYesMovement();
     sayYes(); 
     happy();
  }
  
  if(beSadBoolean) {
     beSadMovement();
     beSad();
     verySad(); 
  }
  
  if(beHappyBoolean){
     beHappyMovement();
     beHappy(); 
     happy();
  }
  
  if(resetHeadBoolean){
   // resetHeadMovement();
    resetHeadServo(); 
  }
  
  if(resetNeckBoolean){
   // resetNeckMovement();
    resetNeckServo();
  }
  
  if(sadTransitionBoolean){
      sadTransition(); 
  }
  
  // moved this out to separate check as servo was stopping because sadTransitionBoolean was getting set to false before servo movement was completed
  if(sadServoTransition){
     beSadMovement();
      beSad();
  }
  
  if(happyTransitionBoolean){
      happyTransition(); 
  }
  
  // moved this out to separate check as servo was stopping because happyTransitionBoolean was getting set to false before servo movement was completed
  if(happyServoTransition){
    beHappyMovement();
      beHappy();
  }
  
  if(danceHeadBoolean){
     danceHeadMovement(); 
     danceHead();
     happy(); 
  }
  
  if(danceNeckBoolean){
    danceNeckMovement();
    danceNeck();
    happy();
  }
  
  // FADE LED HEART
  analogWrite(fadeLed, fadeValue);
  fadeValue += fadeSpeed;
  if(fadeValue >= 255 || fadeValue <=30){
     fadeSpeed *= -1; 
  }
      
}








