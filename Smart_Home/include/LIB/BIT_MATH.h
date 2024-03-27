

/************************************************/
/* guard of file will call one time in .c      **/
/************************************************/

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(Reg, bitnum)       (Reg |=1<<bitnum)
#define CLR_BIT(Reg, bitnum)       (Reg &=~(1<<bitnum))
#define GET_BIT(Reg, bitnum)       ((Reg>>bitnum)& 0x01)
#define TOGGLE_BIT(Reg, bitnum)    (Reg ^=(1<<bitnum))
#define SET_BYTE(Reg,value)              ( Reg = value )
#define ASSIGN_BIT(Reg, bitnum, value) do{\
									if(value == 0)\
									CLR_BIT(Reg, bitnum);\
									else\
									SET_BIT(Reg, bitnum);\
									while(0)


#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0




#endif
