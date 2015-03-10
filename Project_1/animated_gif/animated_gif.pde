ArrayList<Slice> bottomSlices = new ArrayList<Slice>();
ArrayList<Slice> middleSlices = new ArrayList<Slice>();
ArrayList<Slice> topSlices = new ArrayList<Slice>();

Slice slice0, slice1, slice2, slice3, slice4, slice5, slice6,
slice7, slice8, slice9, slice10, slice11, slice12, slice13;


class Slice{
 
 int Y;
 int hue;
 
 int position; 
 
 Slice(int Y){
   this.Y = Y;
 }  
  
 void drawSelf(){
    int y = this.Y;
    int hue =  this.hue;
    noStroke();
    smooth();
    
    fill(hue, 280, 355);
    beginShape();
    vertex(width/3, y);
    vertex(width/3, y+(height/18));
    vertex(width/2, y+(height/9));
    vertex(width/2, y+(height/18));
    endShape();
    
    fill(hue, 280, 260);
    beginShape();
    vertex(2*width/3, y);
    vertex(2*width/3, y+(height/18));
    vertex(width/2, y+(height/9));
    vertex(width/2, y+(height/18));
    endShape();
    
    fill(hue, 280, 310);
    beginShape();
    vertex(width/3, y);
    vertex(width/2, y+(height/18));
    vertex(2*width/3, y);
    vertex(width/2, y-(height/18));
    endShape();
  }
  
  void bottomReset(){
    this.Y = (19*height/18);
  }
  
  void topReset(){
    this.Y = (8*height/18);
  }
  
  void move(){
    this.Y--;
  }
}


void setup(){
  frameRate(60);
  size(500, 500);
  colorMode(HSB, 360);
  
  // Bottom Slices
  slice0 = new Slice(19*height/18);
  slice1 = new Slice(17*height/18);
  slice2 = new Slice(15*height/18);
  slice3 = new Slice(13*height/18);
  slice4 = new Slice(11*height/18);
  
  bottomSlices.add(slice0);
  bottomSlices.add(slice1);
  bottomSlices.add(slice2);
  bottomSlices.add(slice3);
  bottomSlices.add(slice4);
  
  // Middle Slices
  slice5 = new Slice(11*height/18);
  slice6 = new Slice(10*height/18);
  slice7 = new Slice(9*height/18);
  slice8 = new Slice(8*height/18);
  
  middleSlices.add(slice5);
  middleSlices.add(slice6);
  middleSlices.add(slice7);
  middleSlices.add(slice8);
  
  // Top Slices
  slice9 = new Slice(7*height/18);
  slice10 = new Slice(5*height/18);
  slice11 = new Slice(3*height/18);
  slice12 = new Slice(1*height/18);
  slice13 = new Slice(-height/18);
  
  topSlices.add(slice9);
  topSlices.add(slice10);
  topSlices.add(slice11);
  topSlices.add(slice12);
  topSlices.add(slice13);
}

void draw(){
  background(229, 220, 70);
  drawBottom();  
  drawMiddle();
  drawTop(); 
}

void drawBottom(){
  int toRemove = -1;
  for (int i=0; i < bottomSlices.size(); i++){
    Slice thisSlice = bottomSlices.get(i);
    thisSlice.move(); 
    int hue = int(map(thisSlice.Y, height, height/2, 240, 70));   
    thisSlice.hue = hue;
    thisSlice.drawSelf();
    if (thisSlice.Y < 11*height/18){
      thisSlice.bottomReset();
      toRemove = i;
    }
  }
  if (toRemove != -1){
    bottomSlices.remove(toRemove);
    Slice newSlice = new Slice(19*height/18);
    ArrayList<Slice> temp = new ArrayList<Slice>();
    temp.add(newSlice);
    for (int i = 0; i < bottomSlices.size(); i++){
      temp.add(bottomSlices.get(i));
    }
    bottomSlices = temp;
  }
}

void drawMiddle(){

  for (int i=0; i < middleSlices.size(); i++){
    Slice thisSlice = middleSlices.get(i);
    thisSlice.hue = 110;
    thisSlice.drawSelf();
  }
  fill(110, 280, 355);
  beginShape();
  vertex(width/3, 8*height/18);
  vertex(width/2, 9*height/18);
  vertex(width/2,12*height/18);
  vertex(width/3, 12*height/18);
  endShape();
  
  fill(110, 280, 260);
  beginShape();
  vertex(width/2, 9*height/18);
  vertex(2*width/3, 8*height/18);
  vertex(2*width/3,12*height/18);
  vertex(width/2, 12*height/18);
  endShape();
}

void drawTop(){
  int toRemove = -1;
  for (int i=0; i < topSlices.size(); i++){
    Slice thisSlice = topSlices.get(i);
    thisSlice.move();    
    int hue = int(map(thisSlice.Y, 0, height/2, 30, 120));
    thisSlice.hue = hue;
    thisSlice.drawSelf();
    if (thisSlice.Y < -(2*height/18)){
      thisSlice.topReset();
      toRemove = i;
    }
   
  }
  if (toRemove != -1){
    topSlices.remove(toRemove);
    Slice newSlice = new Slice(8*height/18);
    ArrayList<Slice> temp = new ArrayList<Slice>();
    temp.add(newSlice);
    for (int i = 0; i < topSlices.size(); i++){
      temp.add(topSlices.get(i));
    }
    topSlices = temp;
  }
}



