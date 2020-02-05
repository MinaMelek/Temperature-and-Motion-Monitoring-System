/*
 * UART_GUI_Project.c
 *
 * Created: 14/10/2015 10:01:01 ص
 *  Author: w
 */ 
#include "STD_TYPES.h"
#include <avr/io.h>
#include "USART.h"
#include <avr/delay.h>
int main(void)
{
	USART_vInitSpecific();
    while(1)
    {
        USART_vSendString("ALY MOHAMED");
		_delay_ms(1000); 
    }
}