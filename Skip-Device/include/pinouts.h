/**
 * @file pinouts.h
 * @author Graham Driver (driverg@myumanitoba.ca)
 * @brief Definitions of every used pin for the skip controller
 * @version 0.1
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <Arduino.h>

// Sliders
#define leftSliderPin   A3
#define rightSliderPin  A0

// LEDs
#define indicatorLEDPin    A14

// Switches
#define rightSwitchPinOnePin   A15
#define rightSwitchPinTwoPin   A16
#define rightSwitchPinThreePin A17
#define leftSwitchPinOnePin    A28
#define leftSwitchPinTwoPin    A29
#define leftSwitchPinThreePin  A27

// Buttons
#define hurryHardButtonPin     A16
 