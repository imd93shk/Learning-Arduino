const int led = 10;
const int button = 2;
int i;

void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() 
{
  if (digitalRead(button) == LOW)
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
}
