#include "led_driver.h"
#include "stdint.h"

#define DEVICE_ID 0
#define SLEEP_PACKETS 180000 //num of dupe packets before turning off LEDs



void init(void);

void packetHandler(uint8_t leftSweeperIntensity, uint8_t rightSweeperIntensity, uint8_t sweeperOnLeft, uint8_t sweeperOnRight, bool hurryHard);
uint32_t is_idle();//checks if the device should be idle based on how many packets it receives