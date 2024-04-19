#include "wifi_handler.h"

uint8_t broadcastAddress[] = {};



esp_now_peer_info_t peerInfo;
Packet ourPacket;

void recievePacket(const uint8_t * mac, const uint8_t *incomingData, int len){
    memcpy(&ourPacket, incomingData, sizeof(Packet));
    /*
    Serial.print("Left Intensity: ");
    Serial.print(ourPacket.leftSweeperIntensity);
    Serial.print(" Right Intensity: ");
    Serial.print(ourPacket.rightSweeperIntensity);
    Serial.print(" Right Sweeper: ");
    Serial.print(ourPacket.sweeperOnRight);
    Serial.print(" Left Sweeper: ");
    Serial.print(ourPacket.sweeperOnLeft);
    Serial.print(" hurryHard: ");
    Serial.println(ourPacket.hurryHard);
    */
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

uint8_t getLeftSweeperIntensity(void){
  return ourPacket.leftSweeperIntensity;
}

uint8_t getRightSweeperIntensity(void){
  return ourPacket.rightSweeperIntensity;
}

uint8_t getSweeperOnLeft(void){
  return ourPacket.sweeperOnLeft;
}

uint8_t getSweeperOnRight(void){
  return ourPacket.sweeperOnRight;
}


bool getHurryHard(){
  return ourPacket.hurryHard;
}