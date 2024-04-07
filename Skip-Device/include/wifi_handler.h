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