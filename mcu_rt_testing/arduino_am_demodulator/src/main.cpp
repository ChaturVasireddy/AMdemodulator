#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A5) - 326);
  delay(1);
}
