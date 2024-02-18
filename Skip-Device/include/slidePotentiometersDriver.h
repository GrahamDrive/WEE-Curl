/**
 * @file slidePotentiometersDriver.h
 * @author Graham Driver (drivergraham1@gmail.com)
 * @brief This script contains functions to initialize and control the slide potentiometers connected to the WEE Curl Skip Device.
 * @version 0.1
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <Arduino.h>
#include <stdint.h>

#define leftSlidePin    A0
#define rightSlidePin   A99

uint8_t getRawADCLeftPotentiometer();