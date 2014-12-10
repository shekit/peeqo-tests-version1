class Button {
   
  float[] corners;
  float[] dimensions;
  color fillColor;
  color hoverColor;
  color strokeColor;
  float fillAlpha = 0;
  String btnText;
  float bottomCornerX;
  float bottomCornerY;
  float topCornerX;
  float topCornerY;
  float textPosX;
  float textPosY;
  
  
  Button(float[] _corners, float[] _dimensions, color _fillColor, color _hoverColor, color _strokeColor, String _btnText) {
     corners = _corners;
     dimensions = _dimensions;
     fillColor = _fillColor;
     hoverColor = _hoverColor;
     strokeColor = _strokeColor;
     btnText = _btnText;
     topCornerX = corners[0] - dimensions[0]/2;
     topCornerY = corners[1] - dimensions[1]/2;
     bottomCornerX = corners[0] + dimensions[0]/2;
     bottomCornerY = corners[1] + dimensions[1]/2;
     textPosX = corners[0] ;
     textPosY = corners[1] ;
  }
  
  void display() {
     pushStyle();
     rectMode(CORNERS);
     stroke(strokeColor);
     strokeWeight(2);
     fill(fillColor,fillAlpha);
     rectMode(CENTER);
     rect(corners[0], corners[1], dimensions[0] , dimensions[1]);
     popStyle();
     
     pushStyle();
     textAlign(CENTER, CENTER);
     textSize(14);
     fill(255);
     text(btnText, textPosX, textPosY - 3);
     popStyle();
     
     hover();
  }
  
  void displaySelected() {
    pushStyle();
     rectMode(CORNERS);
     stroke(strokeColor);
     strokeWeight(2);
     fill(hoverColor,255);
     rectMode(CENTER);
     rect(corners[0], corners[1], dimensions[0] , dimensions[1]);
     popStyle();
     
     pushStyle();
     textAlign(CENTER, CENTER);
     textSize(14);
     fill(255);
     text(btnText, textPosX, textPosY - 3);
     popStyle();
  }
  
  void hover() {
     if(mouseX > topCornerX  && mouseX < bottomCornerX && mouseY > topCornerY && mouseY < bottomCornerY){
         fillColor = hoverColor;
         fillAlpha += 10;
         fillAlpha = constrain(fillAlpha,0,255);
         //cursor(HAND);
     } else {
         fillColor = fillColor;
         fillAlpha -= 10;
         fillAlpha = constrain(fillAlpha,0,255);
         //cursor(ARROW);
     }
  }
  
  void setColor(color c){
     hoverColor = c;
  }
  
  boolean clicked() {
    if(mouseX > topCornerX && mouseX < bottomCornerX && mouseY > topCornerY && mouseY < bottomCornerY){
       return true;
    }
    return false;
  }
  
  void disappear() {
    
  }
  
}
