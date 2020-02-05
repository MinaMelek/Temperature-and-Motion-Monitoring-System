/*
 * KEYPAD_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: mohammed magdy
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
#include "uart.h"
#include "keypad.h"
#include "lcd.h"
#include "adc.h"
uint8 Keypad_get_password(void);
uint8 Keypad_get_threshold(void);

#endif /* KEYPAD_INTERFACE_H_ */
