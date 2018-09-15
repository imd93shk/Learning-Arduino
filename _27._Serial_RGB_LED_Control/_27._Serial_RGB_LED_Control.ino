const int Red_LED = 11;
const int Green_LED = 10;
const int Blue_LED = 9;

int Rval = 0;
int Gval = 0;
int Bval = 0;

void setup() 
{
  pinMode(Red_LED,OUTPUT);
  pinMode(Green_LED,OUTPUT);
  pinMode(Blue_LED,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  while (Serial.available() > 0)
  {
    Rval = Serial.parseInt();
    Gval = Serial.parseInt();
    Bval = Serial.parseInt();
    if (Serial.read() == '\n')
    {
        analogWrite(Red_LED, Rval);
        analogWrite(Green_LED, Gval);
        analogWrite(Blue_LED, Bval);
    }
  }
}
