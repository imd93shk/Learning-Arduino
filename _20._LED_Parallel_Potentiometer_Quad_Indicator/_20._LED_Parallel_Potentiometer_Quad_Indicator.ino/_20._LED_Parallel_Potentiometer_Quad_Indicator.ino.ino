const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 10;
const int LED4 = 11;
const int POT = 0;

int value = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void mode(int LED)
{
 if (0 < LED && LED <64)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW); 
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW);  
  }
  else if (63 < LED && LED <128)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH); 
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW);  
  }
  else if (127 < LED && LED <192)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH); 
    digitalWrite(LED3, HIGH); 
    digitalWrite(LED4, LOW); 
  }
  else if (191 < LED && LED <256)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH); 
    digitalWrite(LED3, HIGH); 
    digitalWrite(LED4, HIGH);  
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW); 
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW);
  }
}

void loop() 
{
  value = analogRead(POT);
  value = map(value, 0, 1023, 0, 255);
  Serial.println(value);
  mode(value);
  delay(50);
}
