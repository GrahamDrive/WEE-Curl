#include "command_handler.h"



void construct(struct_cmd_hndlr* parameters){
	
	parameters->left_assign = 0;
	parameters->right_val = 0;
	//parameters->left_assign = 0;
	//parameters->right_assign =0;
	parameters->left_assign = 1;
	parameters->right_assign = 2;
}

void destroy(struct_cmd_hndlr* prm){
free(prm);
}


uint16_t update_payload(struct_cmd_hndlr* prm){
uint16_t payload = 0;
uint8_t assigned = 0b010010000;

if(prm->left_val < 10)	assigned |= STOP;
else if(prm->left_val < 30) assigned |= LIGHT_STR;
else if(prm->left_val < 75) assigned |= MED_STR;
else if(prm->left_val <= 100) assigned |= HARD_STR;

if(prm->right_val < 10) assigned |= STOP >> 4;
else if(prm->right_val < 30) assigned |= LIGHT_STR >> 4;
else if(prm->left_val < 75) assigned |= MED_STR >> 4;
else if(prm->left_val <= 100) assigned |= HARD_STR >> 4;
Serial.println(STOP);
Serial.println(assigned);
//assign payload based on the assign variables

payload |= ((uint16_t)(assigned&0b11110000))>>(prm->left_assign*4);
payload |= ((uint16_t)((assigned&0b00001111)<<4))>>(prm->right_assign*4);

Serial.println(payload);

return payload;
}

void update_left_val(struct_cmd_hndlr* prm,uint8_t new_val){
prm->left_val = new_val;
}

void update_right_val(struct_cmd_hndlr* prm,uint8_t new_val){
prm->right_val = new_val;
}

void update_left_assign(struct_cmd_hndlr* prm,uint8_t new_val){
prm->left_assign = new_val;
}

void update_right_assign(struct_cmd_hndlr* prm,uint8_t new_val){
prm->right_assign = new_val;
}