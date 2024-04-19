#include <Arduino.h>
#include "message_handler.h"
#include "wifi_handler.h"
#include "stdint.h"



// put function declarations here:

#define DELAY 100 //wanted delay in ms

uint32_t cur = 0;
uint32_t next = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led_init();
	wifi_init();
}

void loop() {
  //esp_now should keep the parameters updated whenever there is a new packet received
  cur = millis();
  if(cur > next){//only updates the lights every so ofter
    next = cur + DELAY;
    packetHandler(getLeftSweeperIntensity() , getRightSweeperIntensity(), getSweeperOnLeft(), getSweeperOnRight(), getHurryHard());
  }
}
