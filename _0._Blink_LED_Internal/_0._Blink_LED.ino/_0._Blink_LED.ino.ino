int led = 13; // Assigning 13 as LED

void setup() {
  pinMode(led, OUTPUT); // Assigning Pin 13 (led) as the OUTPUT
}

void loop() {
  digitalWrite(led, HIGH); // Turn LED ON
  delay(1000); // Wait for 1000ms
  digitalWrite(led, LOW); // Turn LED OFF
  delay(1000); // Wait for 1000ms
}
