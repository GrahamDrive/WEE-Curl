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

    //assert(slider.pin != NULL);

    potValue = analogRead(slider->pin);
    slider->avgSum -= slider->data[slider->index];
    slider->avgSum += potValue;
    slider->data[slider->index] = potValue;
    slider->index++;
    slider->index %= RAWindowSize;

    error:
        return status;
}


uint16_t getAveragePotValue(slider_t *slider){
    return (uint16_t)(slider->avgSum / RAWindowSize);
}

uint8_t getPercentagePotValue(slider_t *slider){
    return (uint8_t)((float)100 * ( (float)slider->avgSum / (float)RAWindowSize)/ (float)4096);
}