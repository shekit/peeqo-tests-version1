/////// SAD /////////

void setSad(){
   sadTransitionBoolean = true; 
}

void sadTransition() {
   sadCount++;
   
   if(sadCount == sadInterval*1){
     digitalWrite(31, LOW);
   } else if(sadCount == sadInterval*2){
     digitalWrite(30, LOW);
     digitalWrite(32, LOW);
   } else if(sadCount == sadInterval*3){
     digitalWrite(29, LOW);
     digitalWrite(38, LOW);
     digitalWrite(39, LOW);
     digitalWrite(33, LOW);
   } else if(sadCount == sadInterval*4){
     digitalWrite(28, HIGH);
     digitalWrite(37, LOW);
     digitalWrite(40, LOW);
     digitalWrite(34, LOW);
     digitalWrite(22, HIGH);
   } else if(sadCount==sadInterval*5){
     digitalWrite(27, HIGH);
     digitalWrite(36, LOW);
     digitalWrite(35, LOW);
     digitalWrite(23, HIGH);
   } else if(sadCount == sadInterval*6){
     digitalWrite(24, HIGH);
     digitalWrite(26, HIGH);
   } else if(sadCount == sadInterval*7){
     digitalWrite(25, HIGH);
     sadCount = 0;
     sadTransitionBoolean = false;
   }
}  

/////// HAPPY //////////

void setHappy(){
   happyTransitionBoolean = true; 
}

void happyTransition() {
   happyCount++;
   
   if(happyCount == happyInterval*1){
     digitalWrite(25, LOW);
   } else if(happyCount == happyInterval*2){
     digitalWrite(24, LOW);
     digitalWrite(26, LOW);
   } else if(happyCount == happyInterval*3){
     digitalWrite(23, LOW);
     digitalWrite(36, LOW);
     digitalWrite(35, LOW);
     digitalWrite(27, LOW);
   } else if(happyCount == happyInterval*4){
     digitalWrite(28, HIGH);
     digitalWrite(37, LOW);
     digitalWrite(40, LOW);
     digitalWrite(34, LOW);
     digitalWrite(22, HIGH);
   } else if(happyCount == happyInterval*5){
     digitalWrite(29, HIGH);
     digitalWrite(38, LOW);
     digitalWrite(39, LOW);
     digitalWrite(33, HIGH);
   } else if(happyCount == happyInterval*6){
     digitalWrite(30, HIGH);
     digitalWrite(32, HIGH);
   } else if(happyCount == happyInterval*7){
     digitalWrite(31, HIGH);
     happyCount = 0;
     happyTransitionBoolean = false;
   }
}  

//////// WAKE UP //////////

void wakeUpEyes(){
   long currentMillis = millis();
   
   if(currentMillis - previousWakeUpMillis > wakeUpInterval){
    wakeUpBoolean = !wakeUpBoolean;
    wakeUpCount++;
    previousWakeUpMillis = currentMillis;
  }
  
//  if(wakeUpCount <= 7){
//     if(wakeUpBoolean){
//        fullEye();
//     }
//     
//     if(!wakeUpBoolean){
//        allOff(); 
//     }
//  }
  
  if(wakeUpCount == 7){
     fullEye(); 
     stopBlink = true;
     blinkInterval = 300;
  }
}

//////// SLEEP //////////

void sleepEyes(){
   long currentMillis = millis();
   
   if(currentMillis - previousSleepMillis > sleepInterval){
    sleepBoolean = !sleepBoolean;
    sleepCount++;
    previousSleepMillis = currentMillis;
  }
  
  if(sleepCount <= 6){
     if(sleepBoolean){
        fullEye();
     }
     
     if(!sleepBoolean){
        allOff(); 
     }
  }
  
  if(sleepCount == 6){
     allOff(); 
  }
}
