const int SER   = 8;    //Serial output to shift register 
const int LATCH = 9;    //Shift register latch pin 
const int CLK   = 10;   //Shift register clock pin 
const int POT = 0; //POT

int value;
int val[9] = {0, 1, 3, 7, 15, 31, 63, 127, 255};

void setup()   
{
  //Set pins as outputs   
  pinMode(SER, OUTPUT);   
  pinMode(LATCH, OUTPUT);   
  pinMode(CLK, OUTPUT);   
}

void loop()
{   
  value = analogRead(POT);
  value = map (value, 0, 1023, 0, 8); 
  value = constrain(value, 0, 8);
  digitalWrite(LATCH, LOW);                //Latch low   
  shiftOut(SER, CLK, MSBFIRST, val[value]); //Shift most sig. bit first   
  digitalWrite(LATCH, HIGH);               //Latch high - show pattern 
  delay(1);  
}

