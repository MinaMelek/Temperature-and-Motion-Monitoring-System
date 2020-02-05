/*
 * Keypad.h
 *
 * Created: 4/3/2014 3:02:56 PM
 *  Author: Mohamed Tarek
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#define N_col 4
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTB
#define KEYPAD_PORT_IN  PINB
#define KEYPAD_PORT_DIR DDRB

uint8 KeyPad_getPressedKey(void);
uint8 KeyPad_getPressedKey1(void);
uint8 KeyPad_ABCD_adjustKeyNumber(uint8 ,uint8 );





#endif /* KEYPAD_H_ */
