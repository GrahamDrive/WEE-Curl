#include <Arduino.h>
#include "message_handler.h"
#include "wifi_handler.h"



// put function declarations here:

#define DELAY 10 //wanted delay in ms

unsigned long cur = 0;
unsigned long next = 0;



void setup() {
  // put your setup code here, to run once:

  init();
	wifi_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //esp_now should keep the parameters updated whenever there is a new packet received
  cur = millis();
  if(cur > next){//only updates the lights every so ofter
    next = cur + DELAY;
    read_code(get_code(0),get_code(1),get_code(2),get_code(3),get_but());
  }
}

// put function definitions here: