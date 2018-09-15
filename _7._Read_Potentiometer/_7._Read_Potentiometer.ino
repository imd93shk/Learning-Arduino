const int POT = 0; // Assigning pin no 0 as POT
int val = 0; // Initializing Val as 0

void setup() 
{
  Serial.begin(9600); // Opening serial port. Defining Bits per sec 
}

void loop() 
{
  val = analogRead(POT); // Read value from the Potentiometer and store in val
  Serial.println(val); // Print value of val using Arduino serial print option
  delay(500);
}
