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
#include "command_handler.h"
// Slider Structs
slider_t leftSlider;
slider_t rightSlider;

// Variables
u_long lastmilis;
//uint16_t leftAverage;
//uint16_t rightAverage;
//uint8_t leftPercentage;
//uint8_t rightPercentage;
param* prm;//slider parameters

void setup() {
  Serial.begin(115200);
  lastmilis = millis();
  leftSlider.pin = leftSliderPin;
  rightSlider.pin = rightSliderPin;

	prm = construct();
}

void loop() {
  // main loop


  // Slider polling Section
  // Make sure sliders are constantly polled
  pollSlider(&leftSlider);
  pollSlider(&rightSlider);

  // Every 100ms get the value of the pots
  if((millis() - lastmilis) > 100){
		pollSlider(&leftSlider);
		pollSlider(&rightSlider);
		//poll button and switches
		poll_switch();//left slide switch
		poll_switch();//right slide switch
		poll_button();//poll hurry hard button
		
		//if(!hurry_hard)
		update_left_val(getPercentagePotValue(prm,&leftSlider));
		update_right_val(getPercentagePotValue(prm,&rightSlider));
		//else
		//update_left_val(100);
		//update_right_val(100);
		//update assign switches...
		

		update_payload(prm);

		//send out packet


		//sleep



    //leftAverage = getAveragePotValue(&leftSlider);
    //rightAverage = getAveragePotValue(&rightSlider);
    //leftPercentage = getPercentagePotValue(&leftSlider);
    //rightPercentage = getPercentagePotValue(&rightSlider);
    //Serial.printf("Left Pot Value: %d, Left Pot Percentage: %d, Right Pot Value: %d, Right Pot Percentage: %d", leftAverage, leftPercentage, rightAverage, rightPercentage);
    lastmilis = millis();
  }
  // End of Slider polling Section
}