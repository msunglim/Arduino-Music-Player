#include "notes.h"
#include "songs.h"
#include "led.h"
int buzzerPin = 2;
int pausePin = 3;



void setup() {
  Serial.begin(9600);
  // setSongList();
  pinMode(buzzerPin, OUTPUT);
  pinMode(pausePin, INPUT);
  setupLED(4, 5);
  setPausePin(pausePin);

  attachInterrupt(digitalPinToInterrupt(pausePin), pause, RISING);
}

void loop() {


  play(buzzerPin);
}