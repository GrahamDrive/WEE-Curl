#include <stdlib.h>
#include <stdint.h>
#include <esp_wifi.h>
#include <esp_now.h>
#include "WiFi.h"


void wifi_init(void);
void send_pkt(int left_val,int right_val, int left_assign, int right_assign);