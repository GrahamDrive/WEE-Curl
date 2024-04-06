#include <stdlib.h>
#include <stdint.h>
#include "esp_now.h"
#include "WiFi.h"

#define SWEEPER_ONE     0
#define SWEEPER_TWO     1
#define SWEEPER_THREE   3


typedef struct packet_t{
    uint8_t leftSweeperIntensity;
    uint8_t rightSweeperIntensity;
    uint8_t sweeperOnLeft;
    uint8_t sweeperOnRight;
    bool hurryHard;
}Packet;

uint8_t sweeperOneMac[] = {0x0C, 0xB8, 0x15, 0x77, 0xD4, 0x54};
uint8_t sweeperTwoMac[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};     // Change to actual MACs
uint8_t sweeperThreeMac[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};   // Change to actual MACs


/**
 * @brief Initialize the WIFI communication
 * 
 */
void wifi_init(void);


/**
 * @brief Send a packet
 * 
 * @param outBoundPacket 
 */
void send_pkt(Packet outBoundPacket);