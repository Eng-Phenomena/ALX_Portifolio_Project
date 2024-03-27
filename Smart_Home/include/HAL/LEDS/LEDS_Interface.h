/*
 * LEDS_Interface.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Hossam Fekry
 */

#ifndef INCLUDE_HAL_LEDS_LEDS_INTERFACE_H_
#define INCLUDE_HAL_LEDS_LEDS_INTERFACE_H_


void TURNON_LIGHTING_LEDS(void);
void TURNOFF_LIGHTING_LEDS(void);
void TOGGLE_LIGHTING_LEDS(void);

void TURNON_FIRING_LEDS(void);
void TURNOFF_FIRING_LEDS(void);
void TOGGLE_FIRING_LEDS(void);

void TURNON_LOCK_LEDS(void);
void TURNOFF_LOCK_LEDS(void);

#endif /* INCLUDE_HAL_LEDS_LEDS_INTERFACE_H_ */
