#include "command_handler.h"

struct parameter_t{
	int left_val;
	int right_val;
	int left_assign;
	int right_assign;
};

param* construct(){
	param* parameters = (param*)malloc(sizeof(param));
	parameters->left_val = 0;
	paramaters->right_val = 0;
	//parameters->left_assign = 0;
	//parameters->right_assign =0;
	parameters->left_assign = 1;
	parameters->right_assign = 2;
return parameters;
}

void destroy(param* prm){
free(prm);
}


uint16_t update_payload(param* prm){
uint16_t payload = 0;
uint8_t assigned = 0;

if(prm->left_val < 10)	assigned |= 0bSTOP0000;
else if(prm->left_val < 30) assigned |= 0bLIGHT_STR0000;
else if(prm->left_val < 75) assigned |= 0bMED_STR0000;
else if(prm->left_val <= 100) assigned |= 0bHARD_STR0000;

if(prm->right_val < 10) assigned |= 0b0000STOP;
else if(prm->right_val < 30) assigned |= 0b0000LIGHT_STR;
else if(prm->left_val < 75) assigned |= 0b0000MED_STR;
else if(prm->left_val <= 100) assigned |= 0b0000HARD_STR;

//assign payload based on the assign variables

payload |= (ASSIGN_LEFT|(assigned&0b11110000))>>(prm->left_assign*4);
payload |= (ASSIGN_RIGHT|((assigned<<4)&0b11110000))>>(prm->right_assign*4);

//Serial.println("Payload is %b",payload);

return payload;
}

void update_left_val(param* prm,int new_val){
prm->left_val = new_val;
}

void update_right_val(param* prm,int new_val){
prm->right_val = new_val;
}

void update_left_assign(param* prm,int new_val){
prm->left_assign = new_val;
}

void update_right_assign(param* prm,int new_val){
prm->right_assign = new_val;
}