#include "wifi_handler.h"

typedef struct packet_t{
    int left_val;
    int right_val;
    int left_assign;
    int right_assign;
}Packet;

void send_pkt(int left_v,int right_v, int left_a, int right_a){
    Packet pkt;

    pkt.left_val = left_v;
    pkt.right_val = right_v;
    pkt.left_assign = left_a;
    pkt.right_assign = right_a;

    esp_err_t result = esp_now_send(0, (const uint8_t *)"A", strlen("A"));

    if (result == ESP_OK)
    {
        Serial.println("Broadcasted");
    }
    else
    {
        Serial.println("Err IDK");
    }
}

void OnDataRecv(const uint8_t* mac, const uint8_t *incomingData, int len){
  Serial.print("Packet Received\n");
  Serial.print("Data is:");
  Serial.println(*incomingData);

}

void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status){
  Serial.print("Last Packet Sent Stat: \n");
  Serial.println(status == ESP_NOW_SEND_SUCCESS);
}


void wifi_init(){
    WiFi.mode(WIFI_STA);
    Serial.print("Init ESP-NOW");
    while(esp_now_init() != ESP_OK){
        Serial.println("Error intialzing");
        return;
    }    
    Serial.print("MAC Add:");
    Serial.print(WiFi.macAddress());

    esp_now_register_recv_cb(OnDataRecv);
    esp_now_register_send_cb(OnDataSent);
    
    //add stuff to peer list
    uint8_t broadAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    esp_now_peer_info_t peerInfo = {};
    memcpy(&peerInfo.peer_addr, broadAddress, 6);
}