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
#include "button_Driver.h"
#include "wifi_handler.h"
#include "pinouts.h"

// Slider Structs

slider_t leftSlider;
slider_t rightSlider;
Packet packet = {};

// Variables
u_long lastmilis;

void setup() {
  Serial.begin(9600);
  lastmilis = millis();
  leftSlider.pin = leftSliderPin;
  rightSlider.pin = rightSliderPin;

  wifi_init();

  // Initialize packet
  packet.sweeperOnLeft = SWEEPER_ONE;   // This should be changed to where switch is at
  packet.sweeperOnRight = SWEEPER_TWO;  // This should be changed to where switch is at
  packet.leftSweeperIntensity = 0;
  packet.rightSweeperIntensity = 0;
  packet.hurryHard = false;
}

void loop() {
  // main loop

  // Slider polling Section
  // Make sure sliders are constantly polled
  pollSlider(&leftSlider);
  pollSlider(&rightSlider);

  // Every 100ms send packet
  if((millis() - lastmilis) > 100){
    packet.leftSweeperIntensity = getSweeperLevel(&leftSlider);
    packet.rightSweeperIntensity = getSweeperLevel(&rightSlider);

    //sleep
    send_pkt(packet);
    
    lastmilis = millis();
  }
  // End of Slider polling Section
}
