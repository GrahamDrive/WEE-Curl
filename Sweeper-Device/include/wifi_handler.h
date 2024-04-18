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

uint8_t get_code(int);///get codes for the different parameters of the packet
bool get_but(void);// check button state