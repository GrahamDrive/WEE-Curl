#include <stdbool.h>
#include <Arduino.h>
#include "pinouts.h"

#define SWITCHDEBOUNCE  100

typedef struct{
    uint16_t pinOne = INT16_MAX;
    uint16_t pinTwo = INT16_MAX;
    uint16_t pinThree = INT16_MAX;
    uint8_t switchState = false;
    uint16_t pullUpOrDown = INPUT_PULLUP;
    uint32_t cur_time = 0;
    uint32_t time_switch = 0;
} switchStruct;


/**
 * @brief 
 * 
 */
void initSwitch(switchStruct inputSwitch);


/**
 * @brief 
 * 
 * @return int 
 */
void pollSwitch(switchStruct* inputSwitch);

/**
 * @brief 
 * 
 * @param inputSwitch 
 * @return uint8_t 
 */
uint8_t checkSwitchState(switchStruct* inputSwitch);