const int SENSOR = 0; // Assigning pin no 0 as TEMP

float value = 0; // Initializing value as 0

void setup() 
{
  Serial.begin(9600); // Opening serial port. Defining Bits per sec
}

void loop() 
{
  value = analogRead(SENSOR); // Read value from the temperature sensor and store in val
  value = value * 5.0 / 10.24;
  Serial.println(value); // Print value of val using Arduino serial print option
  delay(5000);
}
