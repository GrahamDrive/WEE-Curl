#include "wifi_handler.h"

uint8_t sweeperOneMac[] = {0x0C, 0xB8, 0x15, 0x77, 0xD4, 0x54};
uint8_t sweeperTwoMac[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};     // Change to actual MACs
uint8_t sweeperThreeMac[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};   // Change to actual MACs

void send_pkt(Packet outBoundPacket){

    
    esp_err_t result = esp_now_send(NULL, (uint8_t *) &outBoundPacket, sizeof(outBoundPacket));

    if (result == ESP_OK)
    {
        Serial.println("Broadcasted");
    }
    else
    {
        Serial.print("Error Code: ");
        Serial.println(result, HEX);
    }
}


void OnDataRecv(const uint8_t* mac, const uint8_t *incomingData, int len){
  Serial.print("Packet Received\n");
  Serial.print("Data is:");
  Serial.println(*incomingData);

}


void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status){
  Serial.print("Delivered Successfully\n");
}


void wifi_init(){
    esp_now_peer_info_t peerInfo = {};
    
    WiFi.mode(WIFI_STA);
    Serial.println("Init ESP-NOW");

    while(esp_now_init() != ESP_OK){
        Serial.println("Error intialzing");
        return;
    }    

    Serial.print("MAC Add:");
    Serial.println(WiFi.macAddress());
    
    //add stuff to peer list
    memcpy(peerInfo.peer_addr, sweeperOneMac, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    if(esp_now_add_peer(&peerInfo) != ESP_OK){
        Serial.println("Failed to add peer");
    }
    else{
        Serial.println("Added Peer");
    }

    esp_now_register_recv_cb(OnDataRecv);
    esp_now_register_send_cb(OnDataSent);
    
}