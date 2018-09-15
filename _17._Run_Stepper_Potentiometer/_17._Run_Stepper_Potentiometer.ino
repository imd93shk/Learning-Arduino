#include<Stepper.h>

const int SPR = 32;
const int SPRO = 32 * 64;
const int POT = 0;
//const int button = 2;

Stepper STEP(SPR, 8, 9, 10, 11);

int Direction;
int val = 0;

void setup() 
{
  Serial.begin(9600);  
}

void loop() 
{
  val = analogRead(POT);
  Serial.println(val);
  Direction = SPR;
  STEP.setSpeed(100);
  STEP.step(Direction);
}
