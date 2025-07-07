#include <Arduino.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

float t = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float message = sin(2 * PI * 1.0 * t);
  float am_signal = (1 + message) * cos(2 * PI * 20.0 * t);
  t += 0.001;
  Serial.println(am_signal);
  dacWrite(25, am_signal * 63.75 + 127.5);
}