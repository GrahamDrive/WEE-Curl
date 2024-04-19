/**
 * @file slidePotentiometersDriver.cpp
 * @author Graham Driver (driverg@myumanitoba.ca)
 * @brief This script is used in order to poll the sliders of the the WEE Curl Skip Device.
 * @version 0.2
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "slidePotentiometersDriver.h"

SLIDE_POT_StatusTypeDef pollSlider(slider_t *slider){
    SLIDE_POT_StatusTypeDef status = SLIDE_POT_OK;
    float potVoltage;

    //assert(slider.pin != NULL); Some sort of error checking should be used in future.

    potVoltage = getCalibratedADCVoltage(analogRead(slider->pin));
    // Moving Average Code
    slider->avgSum -= slider->data[slider->index]; // Remove oldest value
    slider->avgSum += potVoltage; // Add new value 
    slider->data[slider->index] = potVoltage; // Set position to new value
    slider->index++; // Increase index
    slider->index %= RAWindowSize; // If index larger than window set to 1

    error:
        return status;
}


uint16_t getAveragePotValue(slider_t *slider){
    return (uint16_t)(slider->avgSum / RAWindowSize);
}

uint8_t getPercentagePotValue(slider_t *slider){
    Serial.println(((float)100 * ((float)slider->avgSum / (float)RAWindowSize)/(float)3.3000));
    return (uint8_t)((float)100 * ((float)slider->avgSum / (float)RAWindowSize)/(float)3.3000);
}

uint8_t getSweeperLevel(slider_t *slider){
    uint8_t percentage = getPercentagePotValue(slider);
    uint8_t sweepLevel = 0;
    
    if(percentage <= 1){
        sweepLevel = 0;
    }
    else if(percentage > 1 & percentage <= 15){
        sweepLevel = 1;
    }
    else if(percentage > 15 & percentage <= 29){
        sweepLevel = 2;
    }
    else if(percentage > 29 & percentage <= 43){
        sweepLevel = 3;
    }
    else if(percentage > 43 & percentage <= 57){
        sweepLevel = 4;
    }
    else if(percentage > 57 & percentage <= 71){
        sweepLevel = 5;
    }
    else if(percentage > 71 & percentage <= 85){
        sweepLevel = 6;
    }
    else if(percentage > 85 & percentage <= 99){
        sweepLevel = 7;
    }
    else if(percentage > 99){
        sweepLevel = 8;
    }

    return sweepLevel;
}