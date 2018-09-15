const int POT = 0; // Assigning pin no 0 as POT
const int RLed = 9;
// const int GLed = 10;
// const int BLed = 11;

int val = 0; // Initializing Val as 0
const int dim = 0;
const int bright = 1023; 

void setup() 
{
  Serial.begin(9600); // Opening serial port. Defining Bits per sec 
  pinMode(RLed, OUTPUT);
  pinMode(POT, INPUT);
  //pinMode(GLed, OUTPUT);
  //pinMode(BLed, OUTPUT);
}

void loop() 
{
  val = analogRead(POT); // Read value from the Potentiometer and store in val
  val = map(val, dim, bright, 0, 255);
  analogWrite(RLed, val);
  /* RED
  if (val < 341)
  {
    digitalWrite(RLed, HIGH);
    digitalWrite(GLed, LOW);
    digitalWrite(BLed, LOW);
  }
  // BLUE
  else if (val > 679)
  {
    digitalWrite(RLed, LOW);
    digitalWrite(GLed, LOW);
    digitalWrite(BLed, HIGH);
  }
  // GREEN
  else
  {
    digitalWrite(RLed, LOW);
    digitalWrite(GLed, HIGH);
    digitalWrite(BLed, LOW);
  }*/
  Serial.println(val); // Print value of val using Arduino serial print option
  delay(5);
}
