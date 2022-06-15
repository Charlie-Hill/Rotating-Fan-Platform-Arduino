#include <Servo.h>
#include <IRremote.h>

#define IR_REMOTE_PIN 2
#define FANSERVO_PIN 3

Servo fanServo;
IRrecv irrecv(IR_REMOTE_PIN);
decode_results results;

int pos = 0;

int pauseTime = 1500;
int oscilateSpeed = 35;
bool isOscilating = true;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  fanServo.attach(FANSERVO_PIN);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume();
  }

  if (isOscilating) {
    oscilateServo();
  }
}

void oscilateServo() {
  for (pos = 20; pos <= 100; pos += 1) {
    fanServo.write(pos);
    delay(oscilateSpeed);
  }
  delay(pauseTime);
  for (pos = 100; pos >= 20; pos -= 1) {
    fanServo.write(pos);
    delay(oscilateSpeed);
  }
  delay(pauseTime);
}
