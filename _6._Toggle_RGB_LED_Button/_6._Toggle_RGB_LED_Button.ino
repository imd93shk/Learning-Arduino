const int RLed = 9;
const int GLed = 10;
const int BLed = 11;
const int button = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup() 
{
  pinMode(RLed, OUTPUT);
  pinMode(GLed, OUTPUT);
  pinMode(BLed, OUTPUT);
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
  // RED
  if (mode == 1)
  {
    digitalWrite(RLed, HIGH);
    digitalWrite(GLed, LOW);
    digitalWrite(BLed, LOW);
  }
  // GREEN
  else if (mode == 2)
  {
    digitalWrite(RLed, LOW);
    digitalWrite(GLed, HIGH);
    digitalWrite(BLed, LOW);
  }
  // BLUE
  else if (mode == 3)
  {
    digitalWrite(RLed, LOW);
    digitalWrite(GLed, LOW);
    digitalWrite(BLed, HIGH);
  }
  // PURPLE
  else if (mode == 4)
  {
    analogWrite(RLed, 127);
    analogWrite(GLed, 0);
    analogWrite(BLed, 127);
  }
  // TEAL
  else if (mode == 5)
  {
    analogWrite(RLed, 0);
    analogWrite(GLed, 127);
    analogWrite(BLed, 127);
  }
  // ORANGE
  else if (mode == 6)
  {
    analogWrite(RLed, 127);
    analogWrite(GLed, 7);
    analogWrite(BLed, 0);
  }
  // WHITE
  else if (mode == 7)
  {
    analogWrite(RLed, 85);
    analogWrite(GLed, 85);
    analogWrite(BLed, 85);
  }
  // OFF
  else
  {
    digitalWrite(RLed, LOW);
    digitalWrite(GLed, LOW);
    digitalWrite(BLed, LOW);
  }
}

void loop() 
{
 currentButton = debounce(lastButton);
 if (lastButton == LOW && currentButton == HIGH)
 {
   ledMode++;
 }
 lastButton = currentButton;
 if (ledMode == 8) ledMode = 0;
 setMode(ledMode);
}
