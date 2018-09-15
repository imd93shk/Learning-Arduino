const int SENSOR = 0; // Assigning pin no 0 as TEMP
const int RLed = 9; // Assigning pin no 9 to Red LED
const int GLed = 10; // Assigning pin no 10 to Green LED
const int BLed = 11; // Assigning pin no 11 to Blue LED
const int Button = 2;

int value = 0; // Initializing value as 0
const int Max_Light = 950;
const int Min_Light = 200;
boolean lastButton = LOW;
boolean currentButton = LOW;

void setup() 
{
  Serial.begin(9600); // Opening serial port. Defining Bits per sec
  pinMode(RLed, OUTPUT);
  pinMode(GLed, OUTPUT);
  pinMode(BLed, OUTPUT);
  pinMode(Button, INPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(Button);
  if(last != current)
  {
    delay(5); 
    current = digitalRead(Button); 
  }
  return current;
}

void loop() 
{
// if (digitalRead(Button) == HIGH)  
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
  value = analogRead(SENSOR); // Read value from the temperature sensor and store in val
  value = map(value, Min_Light, Max_Light, 0, 255);
  value = constrain(value, 0, 255);
/*  if (value > 200)
  { */
    analogWrite(RLed, value);
    analogWrite(GLed, 0);
    analogWrite(BLed, 0);
    lastButton = currentButton;
/*  }
  else if (value < 50)
  {
    analogWrite(RLed, HIGH);
    analogWrite(GLed, LOW);
    analogWrite(BLed, LOW);
  }
  else
  {
    analogWrite(RLed, LOW);
    analogWrite(GLed, HIGH);
    analogWrite(BLed, LOW);
  } */
  Serial.println(value); // Print value of val using Arduino serial print option
  delay(10000);
}
else
{
  digitalWrite(RLed, LOW);
}
}

