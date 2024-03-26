#include <stdbool.h>
#include "button_Driver.h"
#include <Arduino.h>

#define DEBOUNCE  250

#define PIN_BUTT  25

unsigned long cur_time = 0;
bool isOn = false;
unsigned long time_butt = 0;

void init_button() {
  pinMode(PIN_BUTT,INPUT_PULLDOWN);
}

int poll_button() {
  cur_time = millis();//current time
  
  if(cur_time >= (time_butt+DEBOUNCE)){
    if(digitalRead(PIN_BUTT) == HIGH){
        time_butt = millis();
        isOn = !isOn;
    }
  }
  return isOn;
}
