/*
 * LEDS_Program.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Hossam Fekry
 */


//Basic Includes
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <avr/delay.h>


//MCAL Includes
#include "../Include/MCAL/DIO/DIO_Interface.h"


//HAL includes
#include "../Include/HAL/LCD/LCD_interface.h"


//LED includes
#include "../Include/HAL/LEDS/LEDS_Interface.h"
#include "../Include/HAL/LEDS/LEDS_Private.h"
#include "../Include/HAL/LEDS/LEDS_CFG.h"


//Lighting LEDS

void TURNON_LIGHTING_LEDS(void)
{
	MDIO_voidSetPinValue(LEDS_PORT, YELLOW_LEDS, DIO_SET);
}

void TURNOFF_LIGHTING_LEDS(void)
{
	MDIO_voidSetPinValue(LEDS_PORT, YELLOW_LEDS, DIO_RESET);
}



void TOGGLE_LIGHTING_LEDS(void)
{
	MDIO_voidTogglePinValue(LEDS_PORT, YELLOW_LEDS);
}



//Firing leds

void TURNON_FIRING_LEDS(void)
{
	MDIO_voidSetPinValue(LEDS_PORT,RED_LEDS, DIO_SET);

}

void TURNOFF_FIRING_LEDS(void)
{
	MDIO_voidSetPinValue(LEDS_PORT,RED_LEDS, DIO_RESET);
}

void TOGGLE_FIRING_LEDS(void)
{
	MDIO_voidTogglePinValue(LEDS_PORT, RED_LEDS);
}



//Lock leds

void TURNON_LOCK_LEDS(void)
{
	MDIO_voidSetPinValue(LEDS_PORT,GREEN_LEDS, DIO_SET);

}

void TURNOFF_LOCK_LEDS(void)
{
	MDIO_voidSetPinValue(LEDS_PORT,GREEN_LEDS, DIO_RESET);
}




