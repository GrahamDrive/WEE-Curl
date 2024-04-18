#include "wifi_handler.h"

uint8_t broadcastAddress[] = {};



esp_now_peer_info_t peerInfo;
Packet ourPacket;

void recievePacket(const uint8_t * mac, const uint8_t *incomingData, int len){
    memcpy(&ourPacket, incomingData, sizeof(Packet));
}

void wifi_init(){
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

uint8_t get_code(int level){
  const int code = level;
  switch(code){
    case 0:
      return ourPacket.leftSweeperIntensity;
    case 1:
      return ourPacket.rightSweeperIntensity;
    case 2:
      return ourPacket.sweeperOnLeft;
    case 3:
      return ourPacket.sweeperOnRight;
  }
  return 0;
}

bool get_but(){
  return ourPacket.hurryHard;
}
// uint8_t get_grid_coord(const int level){
//   switch(level){
//     case 0:
//       return ourPacket.leftSweeperIntensity;
//     case 1:
//       return ourPacket.rightSweeperIntensity;
//     case 2:
//       return ourPacket.sweeperOnLeft;
//     case 3:
//       return ourPacket.sweeperOnRight;
//     default:
//       return NULL;

//   }
// }