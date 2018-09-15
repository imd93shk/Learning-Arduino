const int led = 9;
const int button = 2;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledON = false;

void setup() 
{
  pinMode(led, OUTPUT);
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

void loop() 
{
 currentButton = debounce(lastButton);
 if (lastButton == LOW && currentButton == HIGH)
 {
   ledON = !ledON;
 }
 lastButton = currentButton;

 digitalWrite(led, ledON);
}
