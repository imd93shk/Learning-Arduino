const int LED1 = 11;
const int LED2 = 10;
const int LED3 = 9;
const int button = 2;
const int POT = 0;

int j = 0;
boolean cb = LOW;
boolean lb = LOW;
const int dim = 0;
const int bright = 1023;
int value = 0;

void setup() 
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
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
  analogWrite(LED1, value);
  analogWrite(LED2, value);
  analogWrite(LED3, value);
  delay(500);
  analogWrite(LED1, LOW);
  analogWrite(LED2, LOW);
  analogWrite(LED3, LOW);
  delay(500);  
  }

  else if (i == 2)
  {
  analogWrite(LED1, value);
  analogWrite(LED2, LOW);
  analogWrite(LED3, value);
  delay(500);
  analogWrite(LED1, LOW);
  analogWrite(LED2, value);
  analogWrite(LED3, LOW);
  delay(500);  
  }
  else if (i == 3)
  {
  analogWrite(LED1, value);
  analogWrite(LED2, LOW);
  analogWrite(LED3, LOW);
  delay(500);
  analogWrite(LED1, LOW);
  analogWrite(LED2, value);
  analogWrite(LED3, LOW);
  delay(500);
  analogWrite(LED1, LOW);
  analogWrite(LED2, LOW);
  analogWrite(LED3, value);
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
  value = analogRead(POT);
  value = map(value, dim, bright, 0, 255);
  Serial.println(value);
  
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
