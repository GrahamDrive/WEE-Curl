#include <stdbool.h>
#include <Arduino.h>
#include "pinouts.h"

#define DEBOUNCE  250

typedef struct{
    uint16_t pin = INT16_MAX;
    bool buttonState = false;
    uint16_t pullUpOrDown = INPUT_PULLDOWN;
    unsigned long cur_time = 0;
    unsigned long time_butt = 0;
} buttonStruct;


/**
 * @brief 
 * 
 */
void init_button(buttonStruct button);


/**
 * @brief 
 * 
 * @return int 
 */
void pollButton(buttonStruct* button);
