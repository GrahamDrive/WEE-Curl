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