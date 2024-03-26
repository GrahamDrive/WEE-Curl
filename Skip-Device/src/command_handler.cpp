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
	parameters->left_assign = 0;
	parameters->right_assign =0;

return parameters;
}

void destroy(param* prm){
free(prm);
}


uint16_t update_payload(param* prm){
uint16_t payload = 0;
//assign payload based on the assign variables

//assign left/right values based on the assign variables

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