#include "buttonDriver.h"


void init_button(buttonStruct button) {
  pinMode(button.pin, button.pullUpOrDown);
}


void pollButton(buttonStruct* button) {
  button->cur_time = millis();//current time
  
  if(button->cur_time >= (button->time_butt+DEBOUNCE)){
    if(digitalRead(button->pin) == LOW){
        button->time_butt = millis();
        button->buttonState = !(button->buttonState);
    }
  }
}


