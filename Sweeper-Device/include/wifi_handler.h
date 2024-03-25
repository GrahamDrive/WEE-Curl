#include <stdlib.h>
#include <stdint.h>
#include <esp_wifi.h>
#include <esp_now.h>
#include "WiFi.h"

typedef struct message_struct Packet;

void wifi_init(void);
uint16_t get_grid_coord(Packet*);