/*
 * KEYPAD_interface.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mohammed magdy
 */
#include"KEYPAD_interface.h"



uint8 Keypad_get_threshold(void)
{
	uint8 loop_index;
	uint8 temp_th;
	uint8 threshold[2];
	LCD_clearScreen();
			  	     LCD_displayStringRowColumn(0,0,"threshold:");
			  	     _delay_ms(500); /* Press time */
			  	     for(loop_index=0;loop_index<2;loop_index++)
			  	         {
			  	         		threshold[loop_index]=KeyPad_getPressedKey();
			  	         		LCD_intgerToString(threshold[loop_index]);
			  	         	       _delay_ms(500);
			  	         }


			  	     temp_th=10*threshold[0]+threshold[1];
			  	     return temp_th;
}
