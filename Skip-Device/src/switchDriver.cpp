#include "switchDriver.h"


void initSwitch(switchStruct inputSwitch) {
  pinMode(inputSwitch.pinOne, inputSwitch.pullUpOrDown);
  pinMode(inputSwitch.pinTwo, inputSwitch.pullUpOrDown);
  pinMode(inputSwitch.pinThree, inputSwitch.pullUpOrDown);
}


void pollSwitch(switchStruct* inputSwitch) {
  inputSwitch->cur_time = millis();//current time
  
  // We switched states
  if(inputSwitch->switchState != checkSwitchState(inputSwitch)){
    if(inputSwitch->cur_time > (inputSwitch->time_switch + SWITCHDEBOUNCE)){
        inputSwitch->time_switch = millis();
        inputSwitch->switchState = checkSwitchState(inputSwitch);
    }
  }
}

uint8_t checkSwitchState(switchStruct* inputSwitch){
    if(digitalRead(inputSwitch->pinOne) == LOW){
        return 1;
    }
    else if(digitalRead(inputSwitch->pinTwo) == LOW){
        return 2;
    }
    else if(digitalRead(inputSwitch->pinThree) == LOW){
        return 3;
    }
    return 0;
}