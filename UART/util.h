
#ifndef util_h
#define util_h
#define SET_BIT(variable ,bit_position) variable = variable | (1<<bit_position)
#define CLEAR_BIT(variable ,bit_position) variable = variable & ~(1<<bit_position)
#define TOGGLE_BIT(variable ,bit_position) variable = variable ^ (1<<bit_position)
#define GET_BIT(variable ,bit_position) (variable>>bit_position)&(1)
#define SET_REGISTER_BITS(variable) variable=0xff
#define CLEAR_REGISTER_BITS(variable) variable=0x00
#define TOGGLE_REGISTER_BITS(var) var=var^0xff
#define WRITE_REGISTER(var,value) var=value
#define GET_REGISTER(var) var
#endif

