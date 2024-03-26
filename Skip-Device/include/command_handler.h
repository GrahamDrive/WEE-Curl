#include<stdint.h>

typedef struct parameter_t param;

//sweeper assignees
#define ASSIGN_NONE 0b00000000
#define ASSIGN_LEFT 0b01000000
#define ASSIGN_RIGHT 0b10000000

//sweeping strength
#define LIGHT_STR 00000000
#define MED_STR 00010000
#define HARD_STR 00100000
#define STOP 00110000
//special offset can be used to implement more commands
#define SPECIAL 0b11000000

uint16_t update_payload(param*);
void update_left_val(param*,int);
void update_right_val(param*,int);
void update_left_assign(param*,int);
viod update_right_assign(param*,int);

param* construct(void);
void destroy(param*);
