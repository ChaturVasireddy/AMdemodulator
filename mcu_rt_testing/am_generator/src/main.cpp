#include <Arduino.h>
#include <stdlib.h>
#include <math.h>

// put function declarations here:
#define N 1024
#define FS 1000.0 
#define PI 3.14159265358979323846

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
}

void loop() {
  for (int i = 0; i < N; i++)
  {
    float t = i / FS;
    float message = sin(2 * PI * 5.0 * t);
    float am_signal = (1 + message) * cos(2 * PI * 100.0 * t);
    Serial.println(am_signal);
  }
  Serial.println("___________________DONE___________________");
  Serial.println("___________________DONE___________________");
  Serial.println("___________________DONE___________________");
  Serial.println("___________________DONE___________________");
  Serial.println("___________________DONE___________________");
  delay(1000);
}