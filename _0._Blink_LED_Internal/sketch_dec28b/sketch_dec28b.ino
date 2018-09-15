const int trigPin = 13;
const int echoPin = 12;

long duration;
float distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);  
}

void loop()
{
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.0314/2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm \n");
  delay(500);
}
