#include <Arduino.h>
#include "led_driver.h"
#include "message_handler.h"

#define __TESTING 1
// put function declarations here:
int myFunction(int, int);


void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);



  led_init();

}

void loop() {
  // put your main code here, to run repeatedly:
  #if defined(__TESTING)
  blink_color(RED,3);
  blink_color(GREEN,3);
  blink_color(BLUE,3);
  blink_color(YELLOW,3);
  blink_color(PINK,3);
  blink_color(TEAL,3);
  #endif
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}