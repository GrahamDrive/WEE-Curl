#include<stdint.h>
#include<Arduino.h>
typedef struct parameter_t{
	int left_val;
	int right_val;
	int left_assign;
	int right_assign;
}struct_cmd_hndlr;

//sweeper assignees
#define ASSIGN_NONE 0b00000000
#define ASSIGN_LEFT 0b01000000
#define ASSIGN_RIGHT 0b10000000

//sweeping strength
#define LIGHT_STR 0b00000000
#define MED_STR 0b00010000
#define HARD_STR 0b00100000
#define STOP 0b00110000
//special offset can be used to implement more commands
#define SPECIAL 0b11000000

uint16_t update_payload(struct_cmd_hndlr*);
void update_left_val(struct_cmd_hndlr*,uint8_t);
void update_right_val(struct_cmd_hndlr*,uint8_t);
void update_left_assign(struct_cmd_hndlr*,uint8_t);
void update_right_assign(struct_cmd_hndlr*,uint8_t);

void construct(struct_cmd_hndlr*);
void destroy(struct_cmd_hndlr*);
