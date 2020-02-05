// /*
//  * timer_delay.c
//  *
//  *  Created on: ??þ/??þ/????
//  *      Author: mohammed magdy
//  */
// #include "timer_delay.h"
// uint32 temp2;
// uint8 buzzer_on;
// uint8 led_on;
// uint8 method;
// uint8 fan_on;
// uint32 threshold_temp;
// uint8 delay_ms=0;
// void timer0_init_normal_mode(void)
// {
// 	TCNT0 = 0; //timer initial value
// 	TIMSK &= ~(1<<TOIE0); //enable overflow interrupt
// 	/* Configure the timer control register
// 	 * 1. Non PWM mode FOC0=1
// 	 * 2. Normal Mode WGM01=0 & WGM00=0
// 	 * 3. Normal Mode COM00=0 & COM01=0
// 	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
// 	 */
// 	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
// }
// ISR(TIMER0_OVF_vect)
// {
// 	delay_ms++;
// 	if(delay_ms!=12){
// 	//************************************************************************************************************************
// 	if(method==3)
// 	    	   {
// 	    		   LCD_goToRowColumn(0,7);
// 	    		   LCD_intgerToString(temp2);
// 	    		   LCD_goToRowColumn(0,14);
// 	    		   UART_sendByte(13);
// 				   UART_sendString("TEMP=");
// 	    		   Uart_intgerToString(temp2);
// 				   _delay_ms(500);
// 	    		   if(fan_on)
// 	    		   { LCD_displayString("ON");SET_BIT(PORTA,PA7);
// 	    		   UART_sendByte(13);UART_sendString("fan ON");_delay_ms(500);}
// 	    		   else
// 	    		   {LCD_displayString("FF");CLEAR_BIT(PORTA,PA7);
// 	    		    UART_sendByte(13); UART_sendString("fan OFF");_delay_ms(500);}
// 	    	   }
// 	 else if(method==2)
// 	    		      {
// 	    		       		LCD_goToRowColumn(0,7);LCD_intgerToString(temp2);LCD_goToRowColumn(0,14);
// 	    		     if(fan_on) {LCD_displayString("ON");SET_BIT(PORTA,PA7);}else {LCD_displayString("FF");CLEAR_BIT(PORTA,PA7);}
// 	    		       }
//     else
// 	    		   {
// 	    			   UART_sendByte(13);
// 	    			   UART_sendString("TEMP=");
// 	    			   Uart_intgerToString(temp2);
// 					    _delay_ms(100);
// 	    			   if(fan_on) {UART_sendByte(13);UART_sendString("fan ON"); _delay_ms(100);SET_BIT(PORTA,PA7);}else {UART_sendByte(13);UART_sendString("fan OFF"); _delay_ms(100);CLEAR_BIT(PORTA,PA7);}
// 	    		   }
// //****************************************************************************************************************************
// if(buzzer_on)
// {
// 	SET_BIT(PORTD,PD2);
// 	    		   if(method!=1)
// 	    		   {LCD_goToRowColumn(1,7);LCD_displayString("ON");
// 	    		   if(method==3){UART_sendByte(13);UART_sendString("alarm ON");_delay_ms(500);}
// 	    		   }
// 	    		   else {UART_sendByte(13);UART_sendString("alarm ON");_delay_ms(100);}
// 	    		   }
// else
// {CLEAR_BIT(PORTD,PD2);
// if(method!=1)
// 	    		   {LCD_goToRowColumn(1,7);LCD_displayString("FF");
// 	    		   if(method==3){UART_sendByte(13);UART_sendString("alarm OFF");_delay_ms(500);}
// 	    		   }
// 	    		   else {UART_sendByte(13);UART_sendString("alarm OFF");_delay_ms(100);}
// 	    		   }
// //**************************************************************************************************************************
// if(led_on)
// {
// 	SET_BIT(PORTD,PD3);
// 	    		   if(method!=1)
// 	    		   {LCD_goToRowColumn(1,14);LCD_displayString("ON");
// 	    		   if(method==3){UART_sendByte(13);UART_sendString("box ON.");_delay_ms(500);}
// 	    		   }
// 	    		   else {UART_sendByte(13);UART_sendString("box ON.");_delay_ms(100);}
// 	    		   }
// else
// {CLEAR_BIT(PORTD,PD3);
// if(method!=1)
// 	    		   {LCD_goToRowColumn(1,14);LCD_displayString("FF");
// 	    		   if(method==3){UART_sendByte(13);UART_sendString("box OFF.");_delay_ms(500);}
// 	    		   }
// 	    		   else {UART_sendByte(13);UART_sendString("box OFF.");_delay_ms(100);}
// 	    		   }
// 	}
// TIMSK &= ~(1<<OCIE1A); //disable module interrupt
// }
// //*****************************************************************************************************************************
// void Timer0_init(uint32 temp1)
// {
// 	TIMSK |= (1<<TOIE0); //enable overflow interrupt
// 	temp2=temp1;
// }
// 
