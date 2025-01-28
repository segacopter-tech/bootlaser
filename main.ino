const int finLED = 13;
const int testPin = A0;

void setup() {
  Serial.begin(9000);
  Serial.println("readying bootlaser...");

  pinMode(finLED, OUTPUT);
  digitalWrite(finLED, LOW);

  delay(1000);
  Serial.println("running...");

  if (runSelfTests()) {
    Serial.println("complete.");
    digitalWrite(finLED, HIGH);
  } else {
    Serial.println("something went wrong. check your hardware.");
    while (true) {
      digitalWrite(finLED, HIGH);
      delay(500);
      digitalWrite(finLED, LOW);
      delay(500);
  }
 }
}

void loop() {
  Serial.println("booted. your arduino is running.");
  delay(1000);
}

bool runSelfTests() {
  int sensorValue = analogRead(testPin);
  if (sensorValue > 0 && sensorValue < 1024) {
    return true;
  }
  return false;
}
