#include <Arduino.h>
#include "slidePotentiometersDriver.h"

#define RAWindowSize    50

typedef struct{
  uint8_t index;
  uint8_t data[RAWindowSize];
  uint32_t avgSum;
  float average;
}rollingAverage;

rollingAverage potRAValue;
u_long lastmilis;
uint8_t potValue;



void setup() {
  Serial.begin(9600);
  lastmilis = millis();
  potValue = 0;
}

void loop() {
  // put your main code here, to run repeatedly:


  potValue = getRawADCLeftPotentiometer();
  potRAValue.avgSum -= potRAValue.data[potRAValue.index];
  potRAValue.avgSum += potValue;
  potRAValue.data[potRAValue.index] = potValue;
  potRAValue.index++;
  potRAValue.index %= RAWindowSize;

  if(millis() - lastmilis > 5){
    potRAValue.average = (float)(potRAValue.avgSum/RAWindowSize);
    Serial.println(potRAValue.average);
    lastmilis = millis();
  }
  
}