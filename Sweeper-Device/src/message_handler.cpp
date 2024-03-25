#include "message_handler.h"
//#include "esp32wifi"  holder for when the esp32 wifi is implemented

/*
This module is intended to handle any packets coming from esp32 wifi module
*/

//parse packet into message
int parse_packet(Packet* pkt){
    int out = get_code(pkt);

    return out;
}

//read message code
void read_code(int input){
    const int code = input;
    //switch cases
    if(code < 0){
        //error catch here
    } else if (code>= 0 && code <25){
        static_color(GREEN);
    }else if(code >= 25 && code < 50){
        static_color(YELLOW);
    }else if(code >= 50 && code < 75){
        static_color(ORANGE);
    }else if(code >= 75 && code < 99){
        static_color(RED);
    }else if(code == 100){
        //hurry hard
        blink_color(RED,3);
    }
    else{}
    
}

