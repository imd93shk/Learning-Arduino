const int SENSOR = 0; // Assigning pin no 0 as TEMP
const int RLed = 9; // Assigning pin no 9 to Red LED
//const int GLed = 10; // Assigning pin no 10 to Green LED
//const int BLed = 11; // Assigning pin no 11 to Blue LED

float value = 0; // Initializing value as 0

void setup() 
{
  Serial.begin(9600); // Opening serial port. Defining Bits per sec
  pinMode(RLed, OUTPUT);
  //pinMode(GLed, OUTPUT);
  //pinMode(BLed, OUTPUT);
}

void loop() 
{
  value = analogRead(SENSOR); // Read value from the temperature sensor and store in val
  
  Serial.println(value); // Print value of val using Arduino serial print option
  delay(1000);
}

/*  if (value < 20.5)
  {
    digitalWrite(RLed, LOW);
    digitalWrite(GLed, LOW);
    digitalWrite(BLed, HIGH);
  }
  else if (value > 22.0)
  {
    digitalWrite(RLed, HIGH);
    digitalWrite(GLed, LOW);
    digitalWrite(BLed, LOW);
  }
  else
  {
    digitalWrite(RLed, LOW);
    digitalWrite(GLed, HIGH);
    digitalWrite(BLed, LOW);
  }
  */
 
