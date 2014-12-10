class ToDo {
   
  String name;
  boolean done = false;
  Button button;
  PVector position;
  
  ToDo(String _name) {
      name = _name; 
  }
  
  void display() {
    fill(255);
    textSize(14);
    text(name, position.x, position.y);
  }
  
  void done() {
     stroke(0);
     strokeWeight(2);
     line(position.x, position.y, position.x +100, position.y);
  }
  
  
  
}
