#include<stdint.h>

typedef struct parameter_t param;

//sweeper assignees
#define ASSIGN_NONE 0b0000
#define ASSIGN_LEFT 0b0100
#define ASSIGN_RIGHT 0b1000

//sweeping strength
#define LIGHT_STR 0b0000
#define MED_STR 0b0001
#define HARD_STR 0b0010
#define STOP 0b0011
//special offset can be used to implement more commands
#define SPECIAL 0b1100

uint16_t update_payload(param*);
void update_left_val(param*,int);
void update_right_val(param*,int);
void update_left_assign(param*,int);
viod update_right_assign(param*,int);

param* construct(void);
void destroy(param*);
