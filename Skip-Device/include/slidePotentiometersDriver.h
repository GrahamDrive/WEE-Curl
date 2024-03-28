/**
 * @file slidePotentiometersDriver.h
 * @author Graham Driver (driverg@myumanitoba.ca)
 * @brief header file for the slider drivers.
 * @version 0.2
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <Arduino.h>
#include <stdlib.h>

#define RAWindowSize    100

typedef struct{
    uint8_t index = 0;            // Index of the moving average
    uint16_t data[RAWindowSize];  // Data from rolling average
    uint32_t avgSum = 0;          // Sum of values in data
    uint16_t pin = INT16_MAX;     // Pin of the slider
}slider_t;

typedef enum
{
  // Status Types (Optional to use)
  SLIDE_POT_OK       = 0x00,  
  SLIDE_POT_ERROR    = 0x01,
  SLIDE_POT_BUSY     = 0x02,
  SLIDE_POT_TIMEOUT  = 0x03
} SLIDE_POT_StatusTypeDef;


/**
 * @brief This function can be called to poll the analog signal from the given slider.
 * Should be passed slider_t type that will keep moving average of signal.
 * 
 * @param slider A slider struct pointer.
 * @return SLIDE_POT_StatusTypeDef 
 */
SLIDE_POT_StatusTypeDef pollSlider(slider_t *slider);


/**
 * @brief Get the Average Pot Value
 * 
 * @param slider A slider struct pointer.
 * @return uint16_t 
 */
uint16_t getAveragePotValue(slider_t *slider);

/**
 * @brief Get the Percentage Pot Value
 * 
 * @param slider A slider struct pointer.
 * @return uint8_t
 */
uint8_t getPercentagePotValue(slider_t *slider);