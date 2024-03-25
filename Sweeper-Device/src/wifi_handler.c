#include "wifi_handler.h"

uint8_t broadcastAddress[] = {};

struct message_struct{
  uint16_t grid_coord;
};

TaskHandle_t mainHandle;
esp_now_peer_info_t peerInfo;
Packet ourPacket;

void recievePacket(const uint8_t * mac, const uint8_t *incomingData, int len){
    memcpy(&ourPacket, incomingData, sizeof(Packet));
}

void wifi_init(){
  //gives range 0-4095
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    return;
  }
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    return;
  }

  
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Transmitted packet
  esp_now_register_recv_cb(recievePacket);
}

uint16_t get_grid_coord(Packet* pkt){

return pkt->gridCoord;
}