int val = 0;
int knockSensor = A0;
void setup() {


 Serial.begin(9600);

}



void loop() {

  val = analogRead(knockSensor);     


//tone(9,900, 500);
   // Serial.println(val);
if(val > 50){
  //Serial.print("Knock: ");
  Serial.println("WHOS THAT");
}

 // delay(100);  // we have to make a delay to avoid overloading the serial port

}
