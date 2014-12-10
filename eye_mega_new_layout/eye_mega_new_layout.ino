void setup(){
  for(int i=22;i<41;i++){
     pinMode(i, OUTPUT); 
  }
}  

void loop(){
  for(int i=22;i<41;i++){
     digitalWrite(i, HIGH); 
  }
  
  delay(500);
  
  for(int i=22;i<41;i++){
     digitalWrite(i, LOW); 
  }
  
  delay(500);
}
