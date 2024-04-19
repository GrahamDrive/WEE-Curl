#include <stdlib.h>
#include <stdint.h>
#include <esp_wifi.h>
#include <esp_now.h>
#include "WiFi.h"

typedef struct packet_t{
    uint8_t leftSweeperIntensity;
    uint8_t rightSweeperIntensity;
    uint8_t sweeperOnLeft;
    uint8_t sweeperOnRight;
    bool hurryHard;
}Packet;

void wifi_init(void);

uint8_t getLeftSweeperIntensity(void);

uint8_t getRightSweeperIntensity(void);

uint8_t getSweeperOnLeft(void);

uint8_t getSweeperOnRight(void);

bool getHurryHard(void);// check button state