/*
 * app.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Hossam Fekry
 */


//Basic Includes
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <avr/delay.h>
#include <stdlib.h>


//MCAL Includes
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/UART/UART_Interface.h"


//HAL includes
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/STEP_UP_MOTOR/STEPMOTOR_Interface.h"
#include "../include/HAL/LEDS/LEDS_Interface.h"
#include "../include/HAL/STEP_UP_MOTOR/STEPMOTOR_Cfg.h"


#define F_CPU  8000000UL
#define USERS_NUMBER  10
u8 USERS_PASSWORDS[USERS_NUMBER] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
u8 *USERS_NAMES[USERS_NUMBER] = {"AHMED", "SALEH", "SALAH", "RAGAB", "HOSAM", "SOBHY", "NADIN", "YUSEF", "OMNIA", "AMIRA"};



typedef struct user {
    u8 *name;
    u8 password;
}USERS_s;

USERS_s *USERS_ARRAY[USERS_NUMBER];
int main(void)
{
	MDIO_voidInit();
	MUART_voidInit();
	HLCD_voidInit();

	u8 user_index, keypad_value;
	for(user_index = 0; user_index < USERS_NUMBER; user_index++)
	{
		USERS_s *user = malloc(sizeof(USERS_s));
		user->name = malloc(sizeof(u8) * 5);
		user->name = USERS_NAMES[user_index];
		user->password = USERS_PASSWORDS[user_index];
		USERS_ARRAY[user_index] = user;
	}
	u8 User_Index = 255;
	u8 tmp = 0, trial = 0;
	HLCD_voidClearDisplay();
	MUART_voidSendStringSyncNonBlocking("Enter Appartment Number\r\n");
	LCD_VOID_WRITE_MESSAGE("Please Enter", ROW1, COL1);
	_delay_ms(2000);
	LCD_VOID_WRITE_MESSAGE("House Number", ROW2, COL1);
	_delay_ms(2000);
	HLCD_voidClearDisplay();
	while (User_Index < '0' || User_Index > '9')
	{
		User_Index = MUART_u8ReadByteSyncBlocking();
		MUART_voidSendByteSyncBlocking(User_Index);
		MUART_voidSendByteSyncBlocking('\n');
	}
	MUART_voidSendStringSyncNonBlocking("\r\nEnter Password\r\n");
	User_Index -= '0';

	while(1)
	{
		u8 mul = 100, pass = 0;
		LCD_VOID_WRITE_MESSAGE("Enter Password: ", ROW1, COL1);
		HLCD_voidGoToPos(ROW2, COL1);
		for(u8 i = 0; i < 3; i++)
		{
			tmp = MUART_u8ReadByteSyncBlocking();
			MUART_voidSendByteSyncBlocking(tmp);
			HLCD_voidSendData(tmp);
			pass += mul * (tmp - '0');
			mul /= 10;
		}
		MUART_voidSendStringSyncNonBlocking("\r\n");
		if (pass == USERS_ARRAY[User_Index]->password)
		{
			LCD_VOID_WRITE_MESSAGE("House Number: ", ROW1, COL1);
			HLCD_voidSendData(User_Index + '0');
			_delay_ms(2000);
			LCD_VOID_WRITE_MESSAGE("WELCOME ", ROW1, COL1);
			_delay_ms(1000);
			LCD_VOID_WRITE_MESSAGE(USERS_ARRAY[User_Index]->name, ROW2, COL1);
			_delay_ms(1000);
			break;
		}
		else
		{
			if (trial == 2)
			{
				TURNON_FIRING_LEDS();
				LCD_VOID_WRITE_MESSAGE("Access Denied", ROW1, COL1);
				_delay_ms(2000);
				LCD_VOID_WRITE_MESSAGE("QUITING System", ROW1, COL1);
				_delay_ms(1000);
				return (0);
			}
			LCD_VOID_WRITE_MESSAGE("Incorrect", ROW1, COL1);
			trial++;
			_delay_ms(2000);
			continue;
		}
	}
	TURNON_LOCK_LEDS();
	LCD_VOID_WRITE_MESSAGE("Opening Door", ROW1, COL1);
	STEPPER_Set_Angle(90, CW);
	_delay_ms(4000);
	LCD_VOID_WRITE_MESSAGE("Closing Door", ROW1, COL1);
	TURNOFF_LOCK_LEDS();
	STEPPER_Set_Angle(90, ACW);
	TURNON_LIGHTING_LEDS();
	HLCD_voidClearDisplay();
	return (0);
}



