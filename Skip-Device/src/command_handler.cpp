#include "command_handler.h"

struct parameter_t{
	int left_val;
	int right_val;
	int left_assign;
	int right_assign;
};

uint16_t update_payload(){
uint16_t payload = 0;
//assign payload based on the assign variables

//assign left/right values based on the assign variables

return payload;
}

void update_left_val(int new_val){
param->left_val = new_val;
}

void update_right_val(int new_val){
param->right_val = new_val;
}

void update_left_assign(int new_val){
param->left_assign = new_val;
}

void update_right_assign(int new_val){
param->right_assign = new_val;
}