#include "led.h"
#include <Arduino.h>
int LED1Pin;
int LED2Pin;
void setupLED(int led1, int led2) {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  LED1Pin = led1;
  LED2Pin = led2;
}
void controlLED(int index) {
  // Serial.println(index);
  if (index == 0) {
    digitalWrite(LED1Pin, HIGH);
    digitalWrite(LED2Pin, LOW);
  } else if (index == 1) {
    digitalWrite(LED1Pin, LOW);
    digitalWrite(LED2Pin, HIGH);
  } else {
    digitalWrite(LED1Pin, HIGH);
    digitalWrite(LED2Pin, HIGH);
  }
}