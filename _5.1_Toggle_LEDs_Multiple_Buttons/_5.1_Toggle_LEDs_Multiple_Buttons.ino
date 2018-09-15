const int POT = A0;
int POT_min = 0;
int PO_max = 1023;
int value = 0;
int per = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  value = analogRead(POT);
  Serial.print("Analog Reading:");
  Serial.println(value);
  per = map(value, 0, 1023, 0, 100);
  Serial.print("Percentage:");
  Serial.print(per);
  Serial.println("%");
  delay(1000);
   

}
