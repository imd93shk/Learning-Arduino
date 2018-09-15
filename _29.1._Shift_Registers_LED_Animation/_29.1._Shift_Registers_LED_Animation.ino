const int SER   =8;    //Serial output to shift register 
const int LATCH =9;    //Shift register latch pin 
const int CLK   =10;   //Shift register clock pin 

int seq[14] = {1, 2, 4, 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2};

void setup()   
{
  //Set pins as outputs   
  pinMode(SER, OUTPUT);   
  pinMode(LATCH, OUTPUT);   
  pinMode(CLK, OUTPUT);   
}

void loop()
{   
  for(int i = 0; i < 14; i++)
  {
    digitalWrite(LATCH, LOW);                //Latch low   
    shiftOut(SER, CLK, MSBFIRST, seq[i]); //Shift most sig. bit first   
    digitalWrite(LATCH, HIGH);               //Latch high - show pattern 
    delay(100);  
  }
}

