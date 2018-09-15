const int led = 10; // Assigning 10 ad led
int i;
void setup() 
{
  pinMode(led, OUTPUT);
}

void loop() 
{
  for (i=100; i<=1000; i=i+100)
  {
    digitalWrite(led, HIGH);  
    delay(i);
    digitalWrite(led, LOW);
    delay(i);
  }
}
