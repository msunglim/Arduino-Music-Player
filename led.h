#ifndef LED_H
#define LED_H

extern int LED1Pin;
extern int LED2Pin;
void setupLED(int led1, int led2);
void controlLED(int index);

#endif 