void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long startTime = micros();

  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    sum += i
  }

  unsigned long endTime = micros();
  Serial.print("Execution time: ");
  Serial.print(endTime - startTime);
  Serial.println(" µs");

  delay(1000)
}
