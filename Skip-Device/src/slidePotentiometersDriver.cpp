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
    uint16_t potValue;

    //assert(slider.pin != NULL); Some sort of error checking should be used in future.

    potValue = analogRead(slider->pin);

    // Moving Average Code
    slider->avgSum -= slider->data[slider->index]; // Remove oldest value
    slider->avgSum += potValue; // Add new value 
    slider->data[slider->index] = potValue; // Set position to new value
    slider->index++; // Increase index
    slider->index %= RAWindowSize; // If index larger than window set to 1

    error:
        return status;
}


uint16_t getAveragePotValue(slider_t *slider){
    return (uint16_t)(slider->avgSum / RAWindowSize);
}

uint8_t getPercentagePotValue(slider_t *slider){
    return (uint8_t)((float)100 * ( (float)slider->avgSum / (float)RAWindowSize)/ (float)4096);
}

uint8_t getSweeperLevel(slider_t *slider){
    uint8_t percentage = getPercentagePotValue(slider);
    uint8_t sweepLevel = 0;

    if(percentage <= 3){
        sweepLevel = 0;
    }
    else if(percentage > 3 & percentage <= 12){
        sweepLevel = 1;
    }
    else if(percentage > 12 & percentage <= 24){
        sweepLevel = 2;
    }
    else if(percentage > 24 & percentage <= 36){
        sweepLevel = 3;
    }
    else if(percentage > 36 & percentage <= 48){
        sweepLevel = 4;
    }
    else if(percentage > 48 & percentage <= 60){
        sweepLevel = 5;
    }
    else if(percentage > 60 & percentage <= 72){
        sweepLevel = 6;
    }
    else if(percentage > 72 & percentage <= 84){
        sweepLevel = 7;
    }
    else if(percentage > 84){
        sweepLevel = 8;
    }

    return sweepLevel;
}