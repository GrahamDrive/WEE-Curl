/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @author Graham Driver (driverg@myumanitoba.ca)
 * @brief The main file of the skip device for the WEE Curl Skip Device.
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <Arduino.h>
#include "slidePotentiometersDriver.h"

u_long lastmilis;
slider_t leftSlider;
slider_t rightSlider;
uint16_t leftAverage;
uint16_t rightAverage;
uint8_t leftPercentage;
uint8_t rightPercentage;

void setup() {
  Serial.begin(115200);
  lastmilis = millis();
  leftSlider.pin = leftSliderPin;
  rightSlider.pin = rightSliderPin;
}

void loop() {
  //polling loop
  pollSlider(&leftSlider);
  pollSlider(&rightSlider);
  if((millis() - lastmilis) > 100){
    leftAverage = getAveragePotValue(&leftSlider);
    rightAverage = getAveragePotValue(&rightSlider);
    leftPercentage = getPercentagePotValue(&leftSlider);
    rightPercentage = getPercentagePotValue(&rightSlider);
    Serial.printf("Left Pot Value: %d, Left Pot Percentage: %d, Right Pot Value: %d, Right Pot Percentage: %d", leftAverage, leftPercentage, rightAverage, rightPercentage);
    lastmilis = millis();
  }
  
}