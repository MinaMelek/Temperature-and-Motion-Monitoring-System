/*
 * GUI_interface.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mohammed magdy
 */
#include "GUI_interface.h"

uint8 Receive_threshold_from_GUI(void)
{
	uint8  threashould[2];
	uint8 temp_th;
	uint8 loop_index;
	 //UART_sendByte(13);
			 for(loop_index=0;loop_index<2;loop_index++)
				{
			     threashould[loop_index]=UART_recieveByte();
			     	//_delay_ms(100);
					 LCD_clearScreen();
					 LCD_displayCharacter(threashould[loop_index]);
					 _delay_ms(100);
			    }
			 temp_th=10*threashould[0]+threashould[1]-16;

			 return temp_th;
}
