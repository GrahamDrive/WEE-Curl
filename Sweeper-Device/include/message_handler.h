#include "led_driver.h"

#define DEVICE_ID 0
#define SLEEP_PACKETS 180000 //num of dupe packets before turning off LEDs



void init(void);

void read_code(uint8_t,uint8_t,uint8_t,uint8_t,bool);
int is_idle(void);//checks if the device should be idle based on how many packets it receives