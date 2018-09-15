const int LED = 9;

char data;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() 
{
  if (Serial.available() > 0)
  {
    data = Serial.read();
    if(data == '1')
    {
      digitalWrite(LED, HIGH);
      Serial.print("LED is now ON! \n");
    }
    else if (data == '0')
    {
      digitalWrite(LED, LOW);
      Serial.print("LED is now OFF! \n");
    }
  } 
}
