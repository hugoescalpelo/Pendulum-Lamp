#include <Servo.h>

Servo pendulum;

void setup() {
  // put your setup code here, to run once:
  pendulum.attach (3);
  pinMode (9, OUTPUT);
  digitalWrite (9, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  pendulum.write (10);
  delay (random (800, 1100));
  pendulum.write (170);
  delay (random (700, 100));
}
