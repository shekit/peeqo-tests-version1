#include <Wire.h>
#include "Adafruit_MPR121.h"

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of t
//he last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

uint16_t last4touched = 0;
uint16_t curr4touched = 0;

int touchCount0 = 0;
int touchCount4 = 0;

void setup() {
  Serial.begin(9600);
  //Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
}

void loop() {
  // Get the currently touched pads
  currtouched = cap.touched();
  curr4touched = cap.touched();
  

  if(cap.touched() & (1 << 0)){
     //Serial.println("touched the foil");
     if ((currtouched & _BV(0)) && !(lasttouched & _BV(0)) ) {
       //Serial.print(0);
       Serial.println(" You pet me");
       touchCount0 ++;
     } 
  }
  
  if(!(cap.touched() & (1 << 0))){
     //Serial.println("released the foil"); 
     if (!(currtouched & _BV(0)) && (lasttouched & _BV(0)) ) {
       //Serial.print(0); 
       Serial.println(" Yay");
       Serial.println(touchCount0);
    }
  }
  
  if(cap.touched() & (1 << 4)){
     //Serial.println("touched the foil");
     if ((curr4touched & _BV(4)) && !(last4touched & _BV(4)) ) {
       //Serial.print(4); 
       Serial.println("HIGH FIVE");
       touchCount4++;
     } 
  }
  
  if(!(cap.touched() & (1 << 4))){
     //Serial.println("released the foil"); 
     if (!(curr4touched & _BV(4)) && (last4touched & _BV(4)) ) {
       //Serial.print("4"); 
       Serial.println("WooHoo");
       Serial.println(touchCount4);
    }
  }
  

  // reset our state
  lasttouched = currtouched;
  last4touched = curr4touched;
}
