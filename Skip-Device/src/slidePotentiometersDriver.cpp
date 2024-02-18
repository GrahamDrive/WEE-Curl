/**
 * @file slidePotentiometersDriver.cpp
 * @author Graham Driver (drivergraham1@gmail.com)
 * @brief This script contains functions to initialize and control the slide potentiometers connected to the WEE Curl Skip Device.
 * @version 0.1
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "slidePotentiometersDriver.h"



uint8_t getRawADCLeftPotentiometer(void){
    uint8_t analogValue;

    analogValue = analogRead(leftSlidePin);
    return analogValue;
}