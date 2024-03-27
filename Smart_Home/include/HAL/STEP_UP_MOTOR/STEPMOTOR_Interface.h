

#ifndef STPR_INTERFACE_H_
#define STPR_INTERFACE_H_



void STEPPER_Rotate_CW_Full_Step(void);
void STEPPER_Rotate_ACW_Full_Step(void);
void STEPPER_Rotate_CW_Half_Step(void);
void STEPPER_Rotate_ACW_Half_Step(void);
void STEPPER_Set_Angle(u32 angle , u8 direction);



#endif /* STPR_INTERFACE_H_ */
