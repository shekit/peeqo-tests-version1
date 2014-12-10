int pitch = 1000;
int tone1Counter = 0;
void setup(){
  
}

void loop(){
  //tone(8, pitch, 20);
  playTone1();
}

void playTone1() {
   tone1Counter++;
  
   if(tone1Counter==10){
      tone(8, 500, 40);
      //noTone(8);
   } else if(tone1Counter == 5000){
     noTone(8);
     tone(8, 1000, 40); 
   }
   
   
  
}
