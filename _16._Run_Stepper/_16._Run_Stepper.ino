#include<Stepper.h>

const int SPR = 32;
const int SPRO = 32 * 64;

Stepper STEP(SPR, 8, 9, 10, 11);

int Direction;

void setup() 
{
  
}

void loop() 
{
  Direction = SPR;
  STEP.setSpeed(500);
  STEP.step(Direction);
}
