/*
 * LCD_UART_show_func.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: mohammed magdy
 */
#include "LCD_UART_show_func.h"
void Micro_init(void)
{
	    UART_init(); // initialize UART driver
	    LCD_init(); // initialize LCD driver
	    ADC_init(); /* initialize ADC driver */
	    SET_BIT(DDRD,PD2);/*BUZZER PIN */
	    SET_BIT(DDRD,PD3);/*LED PIN */
	    SET_BIT(DDRA,PA7);/*FAN PIN */
	    CLEAR_BIT(DDRC,PC6);/*LDR sensor pin*/
	    CLEAR_BIT(DDRD,PD7);/*proximity sensor pin */
	    CLEAR_BIT(PORTD,PD2);/*BUZZER IS OFF intially */
	    CLEAR_BIT(PORTD,PD3);/*LED IS OFF intially */
	    CLEAR_BIT(PORTA,PA7);/*FAN IS OFF intially */
}
void LCD_PC_show(void)
{
	         UART_sendByte(13);
			 LCD_clearScreen();
			 LCD_displayString("Temp = ");
			 LCD_goToRowColumn(0,10);
			 LCD_displayCharacter('C');
			 LCD_goToRowColumn(0,11);
			 LCD_displayString("fan");
			 LCD_goToRowColumn(1,0);
			 LCD_displayString("alarm: ");
			 LCD_goToRowColumn(1,10);
			 LCD_displayString("box:");
}
void LCD_show(void)
{
	             LCD_clearScreen();
				 LCD_displayString("Temp = ");
				 LCD_goToRowColumn(0,10);
				 LCD_displayCharacter('C');
				 LCD_goToRowColumn(0,11);
				 LCD_displayString("fan");
				 LCD_goToRowColumn(1,0);
				 LCD_displayString("alarm: ");
				 LCD_goToRowColumn(1,10);
				 LCD_displayString("box:");
}

