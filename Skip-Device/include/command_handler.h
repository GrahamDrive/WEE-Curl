#include<stdint.h>

typedef struct parameter_t param;

//sweeper assignees
#define ASSIGN_NONE 0b00
#define ASSIGN_LEFT 0b01
#define ASSIGN_RIGHT 0b10

//sweeping strength
#define LIGHT_STR 0b00
#define MED_STR 0b01
#define HARD_STR 0b10
#define STOP 0b11
//special offset can be used to implement more commands
#define SPECIAL 0b11

uint16_t update_payload(param*);
void update_left_val(int);
void update_right_val(int);
void update_left_assign(int);
viod update_right_assign(int);

param* construct(void);
void destroy(param*);
