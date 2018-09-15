const int POT = 0; // Assigning pin no 0 as POT
const int RLed = 9;
const int GLed = 10;
const int BLed = 11;
const int button = 2;

int value = 0; // Initializing Val as 0
const int dim = 0;
const int bright = 1023; 
boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup() 
{
  Serial.begin(9600); // Opening serial port. Defining Bits per sec 
  pinMode(RLed, OUTPUT);
  pinMode(GLed, OUTPUT);
  pinMode(BLed, OUTPUT);
  pinMode(POT, INPUT);
  pinMode(button, INPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(button);
  if(last != current)
  {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}

void setMode(int mode)
{
if (mode == 1)
  { 
    analogWrite(RLed, value);
    analogWrite(GLed, 0);
    analogWrite(BLed, 0);
  }
  else if (mode == 2)
  {
    analogWrite(RLed, 0);
    analogWrite(GLed, 0);
    analogWrite(BLed, value);
  }
  else if (mode == 3)
  {
    analogWrite(RLed, 0);
    analogWrite(GLed,value);
    analogWrite(BLed, 0);
  } 
  else if (mode == 4)
  {
    analogWrite(RLed, value);
    analogWrite(GLed,value);
    analogWrite(BLed, value);
  }
    else
  {
    analogWrite(RLed, 0);
    analogWrite(GLed, 0);
    analogWrite(BLed, 0);
  }  
}  

void loop() 
{
  value = analogRead(POT); // Read value from the Potentiometer and store in val
  value = map(value, dim, bright, 0, 255);
  Serial.println(value); // Print value of val using Arduino serial print option
 
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledMode++;
  }
  lastButton = currentButton;
  if (ledMode == 5) ledMode = 0;
  setMode(ledMode);
   
}
