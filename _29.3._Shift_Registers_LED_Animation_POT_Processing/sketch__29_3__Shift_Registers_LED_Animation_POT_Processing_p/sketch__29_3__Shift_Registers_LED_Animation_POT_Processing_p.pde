import processing.serial.*;
Serial port;

float data;
String value = "";
float conv;
PFont font;

void setup()
{
  size(600,600);
  port = new Serial(this, "COM3", 9600);
  port.bufferUntil('\n');
  font = loadFont("AgencyFB-Bold-200.vlw");
  textFont(font, 200);
}

void draw() 
{   
  background(0,0,0);   
  fill(46, 209, 2);  
  text(value, 70, 175);   
  fill(0, 102, 153);   
  text(data, 70, 370); 
}

void serialEvent (Serial port)
{
  value = (port.readStringUntil('\n')); 
  float con = float(value);
  data = map(con, 0.0, 8.0, 0.0, 1023.0);
}