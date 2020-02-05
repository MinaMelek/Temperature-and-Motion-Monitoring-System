

#include "keypad.h"

uint8 key_is_pressed=0;
static uint8 Keys[4][4]=
{
	{'A',1,2,3}, /*This weird but this is how the hardware connection made !,may fault*/
	{4,5,6,'B'},
	{7,8,9,'C'},
	{'*',0,'#','D'}
};

//**************************************************************************************************************************
uint8 KeyPad_getPressedKey1(void)
{
	uint8 col,row;
	
		for(col=0;col<N_col;col++) /* loop for columns */
		{
			/*
			 * each time only one of the column pins will be output and
			 * the rest will be input pins include the row pins
			 */
			KEYPAD_PORT_DIR = (0b00010000<<col);

			/*
			 * clear the output pin column in this trace and enable the internal
			 * pull up resistors for the rows pins
			 */
			KEYPAD_PORT_OUT = (~(0b00010000<<col));
			for(row=0;row<N_row;row++) /* loop for rows */
			{
				if(BIT_IS_CLEAR(KEYPAD_PORT_IN,row)) /* if the switch is press in this row */
				{
                     return KeyPad_ABCD_adjustKeyNumber(row,col);
					/* return KeyPad_4x4_adjustKeyNumber((row*N_col)+col+1);*/
				}
				

			}
			

		}

return 100;
// 	KEYPAD_PORT_DIR = (0b10000000);
// 	KEYPAD_PORT_OUT = (~(0b10000000));
}

//***************************************************************************************************************************

uint8 KeyPad_getPressedKey(void){
	uint8 col,row;
	while(1)
	{
		for(col=0;col<N_col;col++) /* loop for columns */
		{
			/* 
			 * each time only one of the column pins will be output and 
			 * the rest will be input pins include the row pins 
			 */ 
			KEYPAD_PORT_DIR = (0b00010000<<col); 
			
			/* 
			 * clear the output pin column in this trace and enable the internal 
			 * pull up resistors for the rows pins
			 */ 
			KEYPAD_PORT_OUT = (~(0b00010000<<col)); 
			for(row=0;row<N_row;row++) /* loop for rows */
			{
				if(BIT_IS_CLEAR(KEYPAD_PORT_IN,row)) /* if the switch is press in this row */ 
				 return KeyPad_ABCD_adjustKeyNumber(row,col);
			}
		}
	}	
}
//************************************************************************************************************************
uint8 KeyPad_ABCD_adjustKeyNumber(uint8 a_row,uint8 a_col)
{
	return Keys[a_row][a_col];
}
//*************************************************************************************************************************

// uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
// {
// 	switch(button_number)
// 	{
// 		case 1: return 1;
// 				break;
// 		case 2: return 2;
// 				break;
// 		case 3: return 3;
// 				break;
// 		case 4: return 'A'; // ASCII Code of %
// 				break;
// 		case 5: return 4;
// 				break;
// 		case 6: return 5;
// 				break;
// 		case 7: return 6;
// 				break;
// 		case 8: return 'B'; /* ASCII Code of '*' */
// 				break;
// 		case 9: return 7;
// 				break;
// 		case 10: return 8;
// 				break;
// 		case 11: return 9;
// 				break;
// 		case 12: return 'C'; /* ASCII Code of '-' */
// 				break;
// 		case 13: return '*';  /* ASCII of Enter */
// 				break;
// 		case 14: return 0;
// 				break;
// 		case 15: return '#'; /* ASCII Code of '=' */
// 				break;
// 		case 16: return 'D'; /* ASCII Code of '+' */
// 				break;
// 		default: return button_number;
// 	}
// }
//**********************************************************************************************************************
