int melody[] = {
  100, 200,100, 368, 734,0, 845, 234};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };
  
int ledPin = 7;

long prevMillis = 0;
int interval = 200;
int ledState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // no need to repeat the melody.
  long currMillis = millis();
  Serial.println(currMillis);
  Serial.println(prevMillis);
  
  if(currMillis - prevMillis > interval){
     prevMillis = currMillis;
     if(ledState == LOW){
        ledState = HIGH;
     } else {
        ledState = LOW; 
     }
     
     digitalWrite(ledPin,ledState);
  }
 // mel();
}

void mel(){
// iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
