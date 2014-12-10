#include <Servo.h>
#include "Timer.h"

Servo servoNeck;
Servo servoHead;

Timer t;
long previousTime = 0;
int servoNeckPosition = 0;
int servoHeadPosition = 0;

int count = 0;
int button = 52;
int prevButtonState = 0;

boolean blinkEyeBool = false;

int eyecount = 0;

void setup(){
  Serial.begin(9600);
   for(int i=22;i<41;i++){
      pinMode(i, OUTPUT); 
   }
   
   pinMode(button, INPUT);
   servoNeck.attach(2);
   servoHead.attach(3);
   t.every(2000, setBlinky);
}

void loop(){

  int currentButtonState = digitalRead(button);
  
  if(currentButtonState != prevButtonState){
     count++; 
  }
  if(count == 0){
    t.update();
  }else if(count == 1){
      allOff();
  } else if(count == 2){
     fullEye(); 
  } else if(count == 3){
     halfEye(); 
  } else if(count == 4){
    happy();
  } else if(count == 5){
    sad();
  } else if(count == 6){
    surprised();
  } else if(count == 7){
    flatEye();
  } else if(count == 8){
    angry();
  } else if(count == 9){
     verySad(); 
  } else if(count == 10){
    dead();
  } else if(count == 11){
     heart(); 
  } else if(count == 12) {
     squint(); 
  }
  
  
  

  
  sayYesMovement();
  sayYes();
  
    if(blinkEyeBool){
     blinky(); 
  }
  
  if(count > 12){
     count = 0; 
  }
  
  prevButtonState = currentButtonState;
}

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
  for(int i=33;i>27;i--){
     digitalWrite(i,HIGH); 
  }
  
  digitalWrite(22,HIGH);
  
  //turn lower outer rim off
  for(int i=23;i<29;i++){
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
  for(int i=37;i<40;i++){
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

void setBlinky(){
  blinkEyeBool = !blinkEyeBool;
  eyecount = 0;
  //Serial.println("called blinky");
}  

void blinky(){
   eyecount ++;
   //Serial.println(eyecount);
   if(eyecount == 500){
   digitalWrite(31, LOW);
   } else if(eyecount == 1000){
   digitalWrite(30, LOW);
   digitalWrite(32, LOW);
   } else if(eyecount == 1500){
   digitalWrite(29, LOW);
   digitalWrite(38, LOW);
   digitalWrite(39, LOW);
   digitalWrite(33, LOW);
   } else if(eyecount == 2000){
   digitalWrite(28, LOW);
   digitalWrite(37, LOW);
   digitalWrite(40, LOW);
   digitalWrite(34, LOW);
   digitalWrite(22, LOW);
   } else if(eyecount==2500){
   digitalWrite(27, LOW);
   digitalWrite(36, LOW);
   digitalWrite(35, LOW);
   digitalWrite(23, LOW);
   } else if(eyecount == 3000){
   digitalWrite(24, LOW);
   digitalWrite(26, LOW);
   } else if(eyecount == 3500){
   digitalWrite(25, LOW);
   } else if(eyecount == 4500){
     digitalWrite(25, HIGH);
   } else if(eyecount == 5000){
   digitalWrite(24, HIGH);
   digitalWrite(26, HIGH);
   } else if(eyecount == 5500){
   digitalWrite(23, HIGH);
   digitalWrite(36, HIGH);
   digitalWrite(35, HIGH);
   digitalWrite(27, HIGH);
   } else if(eyecount == 6000){
   digitalWrite(28, HIGH);
   digitalWrite(37, HIGH);
   digitalWrite(40, HIGH);
   digitalWrite(34, HIGH);
   digitalWrite(22, HIGH);
   } else if(eyecount == 6500){
   digitalWrite(29, HIGH);
   digitalWrite(38, HIGH);
   digitalWrite(39, HIGH);
   digitalWrite(33, HIGH);
   } else if(eyecount == 7000){
   digitalWrite(30, HIGH);
   digitalWrite(32, HIGH);
   } else if(eyecount == 7500){
   digitalWrite(31, HIGH);
   }
    
}

void blinkEye2() {
   long currentTime = millis();
   
   for(int i=22;i<41;i++){
      digitalWrite(i, HIGH);
   } 
   //delay(1000);
   if(currentTime - previousTime > 1000){
     previousTime = currentTime;
     
     if(currentTime-previousTime > 750){
       digitalWrite(31, HIGH);
     } else if(currentTime - previousTime > 700) {
       digitalWrite(30, HIGH);
       digitalWrite(32, HIGH);
     } else if(currentTime - previousTime > 650){
       digitalWrite(29, HIGH);
   digitalWrite(38, HIGH);
   digitalWrite(39, HIGH);
   digitalWrite(33, HIGH);
     } else if(currentTime - previousTime > 600){
       digitalWrite(28, HIGH);
   digitalWrite(37, HIGH);
   digitalWrite(40, HIGH);
   digitalWrite(34, HIGH);
   digitalWrite(22, HIGH);
     } else if(currentTime - previousTime > 550){
       digitalWrite(23, HIGH);
   digitalWrite(36, HIGH);
   digitalWrite(35, HIGH);
   digitalWrite(27, HIGH);
     } else if(currentTime - previousTime > 500){
        digitalWrite(24, HIGH);
       digitalWrite(26, HIGH);
     } else if(currentTime - previousTime > 450) {
        digitalWrite(25, HIGH);
     }else if(currentTime - previousTime > 350){
       digitalWrite(25, LOW);
     }else if(currentTime - previousTime > 300){
       digitalWrite(24, LOW);
   digitalWrite(26, LOW);
     }else if(currentTime - previousTime > 250){
       digitalWrite(27, LOW);
   digitalWrite(36, LOW);
   digitalWrite(35, LOW);
   digitalWrite(23, LOW);
     } else if(currentTime - previousTime > 200) {
       digitalWrite(28, LOW);
       digitalWrite(37, LOW);
       digitalWrite(40, LOW);
       digitalWrite(34, LOW);
       digitalWrite(22, LOW);
     } else if(currentTime - previousTime > 150) {
       digitalWrite(29, LOW);
       digitalWrite(38, LOW);
       digitalWrite(39, LOW);
       digitalWrite(33, LOW);
     }else if(currentTime - previousTime > 100){
       digitalWrite(30, LOW);
       digitalWrite(32, LOW);
     } else if(currentTime-previousTime > 50){
       digitalWrite(31, LOW);
     }
     
    /* if(currentTime-previousTime > 50){
       digitalWrite(31, LOW);
     } else if(currentTime - previousTime > 100){
       digitalWrite(30, LOW);
       digitalWrite(32, LOW);
     } else if(currentTime - previousTime > 150) {
       digitalWrite(29, LOW);
       digitalWrite(38, LOW);
       digitalWrite(39, LOW);
       digitalWrite(33, LOW);
     } else if(currentTime - previousTime > 200) {
       digitalWrite(28, LOW);
       digitalWrite(37, LOW);
       digitalWrite(40, LOW);
       digitalWrite(34, LOW);
       digitalWrite(22, LOW);
     } else if(currentTime - previousTime > 250){
       digitalWrite(27, LOW);
   digitalWrite(36, LOW);
   digitalWrite(35, LOW);
   digitalWrite(23, LOW);
     } else if(currentTime - previousTime > 300){
       digitalWrite(24, LOW);
   digitalWrite(26, LOW);
     } else if(currentTime - previousTime > 350){
       digitalWrite(25, LOW);
     } else if(currentTime - previousTime > 450){
       digitalWrite(25, HIGH);
     }
   }
   
   
   //shut
   digitalWrite(31, LOW);
   delay(50);
   digitalWrite(30, LOW);
   digitalWrite(32, LOW);
   delay(50);
   digitalWrite(29, LOW);
   digitalWrite(38, LOW);
   digitalWrite(39, LOW);
   digitalWrite(33, LOW);
   delay(50);
   digitalWrite(28, LOW);
   digitalWrite(37, LOW);
   digitalWrite(40, LOW);
   digitalWrite(34, LOW);
   digitalWrite(22, LOW);
   delay(50);
   digitalWrite(27, LOW);
   digitalWrite(36, LOW);
   digitalWrite(35, LOW);
   digitalWrite(23, LOW);
   delay(50);
   digitalWrite(24, LOW);
   digitalWrite(26, LOW);
   delay(50);
   digitalWrite(25, LOW);
   delay(100);
   // open
   digitalWrite(25, HIGH);
   delay(50);
   digitalWrite(24, HIGH);
   digitalWrite(26, HIGH);
   delay(50);
   digitalWrite(23, HIGH);
   digitalWrite(36, HIGH);
   digitalWrite(35, HIGH);
   digitalWrite(27, HIGH);
   delay(50);
   digitalWrite(28, HIGH);
   digitalWrite(37, HIGH);
   digitalWrite(40, HIGH);
   digitalWrite(34, HIGH);
   digitalWrite(22, HIGH);
   delay(50);
   digitalWrite(29, HIGH);
   digitalWrite(38, HIGH);
   digitalWrite(39, HIGH);
   digitalWrite(33, HIGH);
   delay(50);
   digitalWrite(30, HIGH);
   digitalWrite(32, HIGH);
   delay(50);
   digitalWrite(31, HIGH);
   delay(50);*/
}
}

void blinkEye(){
 digitalWrite(31, LOW);
   delay(50);
   digitalWrite(30, LOW);
   digitalWrite(32, LOW);
   delay(50);
   digitalWrite(29, LOW);
   digitalWrite(38, LOW);
   digitalWrite(39, LOW);
   digitalWrite(33, LOW);
   delay(50);
   digitalWrite(28, LOW);
   digitalWrite(37, LOW);
   digitalWrite(40, LOW);
   digitalWrite(34, LOW);
   digitalWrite(22, LOW);
   delay(50);
   digitalWrite(27, LOW);
   digitalWrite(36, LOW);
   digitalWrite(35, LOW);
   digitalWrite(23, LOW);
   delay(50);
   digitalWrite(24, LOW);
   digitalWrite(26, LOW);
   delay(50);
   digitalWrite(25, LOW);
   delay(100);
   // open
   digitalWrite(25, HIGH);
   delay(50);
   digitalWrite(24, HIGH);
   digitalWrite(26, HIGH);
   delay(50);
   digitalWrite(23, HIGH);
   digitalWrite(36, HIGH);
   digitalWrite(35, HIGH);
   digitalWrite(27, HIGH);
   delay(50);
   digitalWrite(28, HIGH);
   digitalWrite(37, HIGH);
   digitalWrite(40, HIGH);
   digitalWrite(34, HIGH);
   digitalWrite(22, HIGH);
   delay(50);
   digitalWrite(29, HIGH);
   digitalWrite(38, HIGH);
   digitalWrite(39, HIGH);
   digitalWrite(33, HIGH);
   delay(50);
   digitalWrite(30, HIGH);
   digitalWrite(32, HIGH);
   delay(50);
   digitalWrite(31, HIGH);
   delay(50); 
}

