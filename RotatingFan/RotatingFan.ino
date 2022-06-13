#include <Servo.h>

Servo fanServo;
#define FANSERVO_PIN 3

int pos = 0;

void setup() {
  fanServo.attach(FANSERVO_PIN);
}

void loop() {
  for (pos = 20; pos <= 100; pos += 1) {
    fanServo.write(pos);
    delay(35);
  }
  delay(1500);
  for (pos = 100; pos >= 20; pos -= 1) {
    fanServo.write(pos);
    delay(35);
  }
  delay(1500);
}
