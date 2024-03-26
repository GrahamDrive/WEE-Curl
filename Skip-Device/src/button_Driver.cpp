#include <stdbool.h>

#define DEBOUNCE  250

#define PIN_BUTT  25

static unsigned long cur_time = 0;
static bool isOn = false;
static unsigned long time_butt = 0;

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
