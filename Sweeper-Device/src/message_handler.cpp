#include "message_handler.h"

/*
This module is intended to handle any packets coming from esp32 wifi module
*/

/*
functions call led driver based on packet.

tracks what device we are, and assigned by packet

turns off LEDs after some time
*/


static int last_code = 0;

static unsigned int sleep_count = 0;


//read packet code and call led bar
void read_code(uint8_t leftSweeperIntensity, uint8_t rightSweeperIntensity,
    uint8_t sweeperOnLeft, uint8_t sweeperOnRight, bool hurryHard){
    
    int temp = -1;
    if(sweeperOnLeft == DEVICE_ID){
        temp = leftSweeperIntensity;
    }
    else if(sweeperOnRight == DEVICE_ID){
        temp = rightSweeperIntensity;
    }
    //check if hurry hard
    if(temp != -1 && hurryHard){
        temp = 100;
    }

    const int code = temp;
    
    //check for idle skip
    /*IDLE if:
    low intensity(0) for n packets
    not assigned to sweep

    result - turn off leds
    */

    if(code == 0){
        sleep_count ++;
    }
    else if(DEVICE_ID != sweeperOnRight && DEVICE_ID != sweeperOnLeft){
        sleep_count = SLEEP_PACKETS;
        return;//dont do anything if not assigned a value
    }
    else{
        sleep_count = 0;//reset counter
    }

    
    //switch cases
    switch(code){
        case 0:
            //stop
            blink_color(RED,3);
            static_color(RED);
        case 1:
            //
            static_color(BLUE);
        case 2:
            blink_color(BLUE,3);
            static_color(BLUE);
        case 3:
            static_color(GREEN);
        case 4:
            blink_color(GREEN,3);
            static_color(GREEN);
        case 5:
            static_color(YELLOW);
        case 6:
            blink_color(YELLOW,3);
            static_color(YELLOW);
        case 7:
            static_color(ORANGE);
        case 8:
            blink_color(ORANGE,3);
            static_color(ORANGE);
        
        case 100:
            //blink red
            blink_color(PURPLE,5);

    }
 
}

int is_idle(){
    return sleep_count;
}

