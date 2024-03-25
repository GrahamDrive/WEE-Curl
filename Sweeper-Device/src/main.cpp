#include <Arduino.h>
#include "led_driver.h"
#include "message_handler.h"
#include "wifi_handler.h"

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);



  led_init();
	wifi_init();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here: