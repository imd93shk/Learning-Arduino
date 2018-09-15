const int LED1 = 11;
const int LED2 = 10;
const int LED3 = 9;
const int button = 2;

int j = 0;
boolean cb = LOW;
boolean lb = LOW;

void setup() 
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
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

void mode(int i) 
{
  if (i == 1)
  {  
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);  
  }

  else if (i == 2)
  {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delay(500);
  }
  else if (i == 3)
  {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(500);
  }
  else
  {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);
  }
}

void loop()
{
  cb = debounce(button);
  if (lb == LOW && cb == HIGH)
  {
    j++;
  }
  cb = lb;
  if (j == 4)
  j = 0;
  mode(j);
}
