#include "message_handler.h"

/*
This module is intended to handle any packets coming from esp32 wifi module
*/

/*
functions call led driver based on packet.

tracks what device we are, and assigned by packet

turns off LEDs after some time
*/


static uint32_t last_code = 0;

static uint32_t sleep_count = 0;


//read packet code and call led bar
void packetHandler(uint8_t leftSweeperIntensity, uint8_t rightSweeperIntensity,
    uint8_t sweeperOnLeft, uint8_t sweeperOnRight, bool hurryHard){
    
    static uint8_t code;
    uint8_t temp = -1;
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
    
    code = temp;
    Serial.print("Sweep Intensity: ");
    Serial.print(code);
    Serial.print(" Sweeper on Right: ");
    Serial.print(sweeperOnRight);
    Serial.print(" Sweeper on Left: ");
    Serial.print(sweeperOnLeft);
    Serial.print(" Pass Check?: ");
    Serial.println(DEVICE_ID != sweeperOnRight && DEVICE_ID != sweeperOnLeft);
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
        turnOffLEDs();
        return;//dont do anything if not assigned a value
    }
    else{
        sleep_count = 0;//reset counter
    }

    
    //switch cases
    switch(code){
        case 0:
            //stop
            static_color(RED);
            break;
        case 1:
            //
            static_color(ORANGE);
            break;
        case 2:
            static_color(ORANGE);
            break;
        case 3:
            static_color(YELLOW);
            break;
        case 4:
            static_color(YELLOW);
            break;
        case 5:
            static_color(L_GREEN);
            break;
        case 6:
            static_color(L_GREEN);
            break;
        case 7:
            static_color(GREEN);
            break;
        case 8:
            static_color(GREEN);
            break;
        case 100:
            //blink red
            blink_color(PURPLE, 1);
            break;
    }
 
}

uint32_t is_idle(){
    return sleep_count;
}

