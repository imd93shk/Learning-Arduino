#include "pitches.h"

const int buzzer = 3;
const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 10;
const int LED4 = 11;
const int POT = 1;

int value = 0;

void setup() 
{
  pinMode(buzzer, OUTPUT);
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  value = analogRead(POT);
  Serial.println(value);
  delay(100);
  if (0 < value && value < 342)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    
    
  }
  else if(341 < value && value < 512)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    
  }
  else if(511 < value && value < 682)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    tone(buzzer, NOTE_D8, 100);
    delay(250);
    
  }
  else if(681 < value && value < 1024)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    tone(buzzer, NOTE_C8, 100);
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    
  }

}
