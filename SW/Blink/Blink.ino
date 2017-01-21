void setup() {
  pinMode(5, OUTPUT);

  digitalWrite(5, LOW);
}

void loop() {
  digitalWrite(5, LOW);
  delay(1000);
  digitalWrite(5, HIGH);
  delay(1000);
}

