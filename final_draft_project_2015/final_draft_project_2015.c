/*
 * final_main.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: mohammed magdy
 */

#include "uart.h"
#include "keypad.h"
#include "LCD_UART_show_func.h"
#include "GUI_interface.h"
#include "KEYPAD_interface.h"
#include "LCD_UART_show_func.h"
#include "timer_delay.h"
 uint8 method;
 uint8 buzzer_on;
 uint8 led_on;
 uint8 fan_on;
extern uint8 flage;
extern uint8 future;


int main()
{
	    
		uint8 pass_from_pc=0;	//to detect from witch pass was entered//
        uint8 loop_index;
        uint8 pass_correct=1;
		uint8 threshold_temp;
		uint32 temp;
		uint8 counter;
		uint8 saved_pass[]={4,4,4,4};
		uint8 j;
		uint8 password[4];
		uint8 enter_num=0;
		uint8  button;
//*****************************************************************************************
		Micro_init();
//****************************************************************************************** 

while( pass_correct)
{
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"pass:");
	_delay_ms(500);

while(1)
{
//******************************************************************************************************************	
	UART_recieveAch();
	if((flage==1) && (future==5+'0' ))//1
	{
		pass_from_pc=1;
		flage=0;
		LCD_displayStringRowColumn(0,0,"PC entered pass");
		break;
	}//end of 1 
//******************************************************************************************************************	
	 
	 button=KeyPad_getPressedKey1();
	 if ( button >= 0 && button <= 9)//2
	 {
		
			password[enter_num]= button;
			 LCD_goToRowColumn(0,5+enter_num);
			 LCD_intgerToString(password[enter_num]);
			 enter_num++;
			 _delay_ms(400);  	
	 }//end of 2 
//*********************************************************************************************************************	 
	 if ( button == '#')//3
	 {
	 	if(enter_num !=4)//4
	 	{
		 	
		 	LCD_clearScreen();
		 	LCD_displayStringRowColumn(0,4,"wrong pass");
		 	_delay_ms(500); /* Press time */
		 	enter_num=0;
		 	break;
	 	}////end of 4 

	 	else if(enter_num ==4 )//5
	 	{
		 	for(j=0;j<4;j++){if(password[j] !=saved_pass[j])break;}
		 	if(j!=4)//6
		 	{
			 	LCD_clearScreen();
			 	LCD_displayStringRowColumn(0,4,"wrong pass");
			 	_delay_ms(500); /* Press time */
			 	enter_num=0;
			 	break;
		 	}////end of 6
		 	
		 	else//7
		 	{
			 	LCD_clearScreen();
			 	LCD_displayStringRowColumn(0,0,"pass is correct");
			 	_delay_ms(500); /* Press time */
				 pass_from_pc=2;
				 break;
		 	}////end of 7
			 }////end of 5
		 }//end of 3
	  	 
			 }//end of while(1)
if(pass_from_pc)break;
	}//end of while( pass_correct)

//***********************************************************************************************************************
	 

		 if(pass_from_pc==1)//8
		 {
			threshold_temp=Receive_threshold_from_GUI();
			_delay_ms(500);
			LCD_clearScreen();
			LCD_displayString("Threshold is ");
			LCD_intgerToString(threshold_temp);
			_delay_ms(1500);
			method=1;
			
		 }//end of 8
		 else if(pass_from_pc==2)//9
		 {
			threshold_temp=Keypad_get_threshold();
			LCD_clearScreen();
			LCD_intgerToString(threshold_temp);
			_delay_ms(500);
//***********************************************************************************************************************************************			
			UART_sendString("pc will be offline.");
			UART_recieveAch();  //if flage=1 then method 1 else method 2
			    	      if((flage==1) && (future==6+'0' ))//10
			    	      {
			    	    	  method=3;
			    	      }//end of 10
			    	      else//11
			    	          	    {
			    	    	  method=2;
			    	    	  for(loop_index=0;loop_index<11;loop_index++)//for1
			    	    	      	    	    {
			    	    	      	    	    	
												   LCD_clearScreen();
												   LCD_displayStringRowColumn(0,0,"num of tries:");
												   LCD_intgerToString(loop_index);
												   _delay_ms(1200); /* Press time */
												   UART_sendString("pc will be offline.");
													  _delay_us(9000);
			    	    	      	    	    	  UART_recieveAch();
												        if((flage==1)&& (future==6+'0'))
												        {
													        method=3;//pc+LCD
													        break;
												        }
											}//end of for 1

			    	    	      	    }//end of 11
			    	    	  	 }//end of 9
						  
			    	    	  	  
//*********************************************************************************************
if(method==3)//LLCD+pc
	LCD_PC_show();
else if(method==2)//LCD only
	LCD_show();
else if (method==1)
	LCD_PC_show();
//*************************************************************************************************
SREG  |= (1<<7);
//timer0_init_normal_mode();
while(1)
{
	           button=0;
			   button=KeyPad_getPressedKey1();// if key=50 then no button is pressed else a button pressed
	           if(button == '#')break;
	           temp = ADC_read(4); /* read channel two where the temp sensor is connect */
	           temp = (temp*150*5)/(1023*1.5); /* calculate the temp from the ADC value*/
	           if(temp>threshold_temp) fan_on=1;else fan_on=0;
	           if(BIT_IS_SET(PIND,PD7)) buzzer_on=1; else buzzer_on=0;
	           if(BIT_IS_SET(PINC,PC6)) led_on=1; else led_on=0;
               //Timer0_init(temp);
			   //************************************************************************************************************************
	if(method==3 || method==1)
	    	   {
	    		   LCD_goToRowColumn(0,7);
	    		   LCD_intgerToString(temp);
	    		   LCD_goToRowColumn(0,14);
	    		   UART_sendByte(13);
				   UART_sendString("TEMP=");
	    		   Uart_intgerToString(temp);
				   _delay_ms(100);
	    		   if(fan_on)
	    		   { LCD_displayString("ON");SET_BIT(PORTA,PA7);
	    		   UART_sendByte(13);UART_sendString("fan ON");_delay_ms(100);}
	    		   else
	    		   {LCD_displayString("FF");CLEAR_BIT(PORTA,PA7);
	    		    UART_sendByte(13); UART_sendString("fan OFF");_delay_ms(100);}
	    	   }
	 else if(method==2)
	    		      {
	    		       		LCD_goToRowColumn(0,7);LCD_intgerToString(temp);LCD_goToRowColumn(0,14);
	    		     if(fan_on) {LCD_displayString("ON");SET_BIT(PORTA,PA7);}else {LCD_displayString("FF");CLEAR_BIT(PORTA,PA7);}
	    		       }
    /*else
	    		   {
	    			   UART_sendByte(13);
	    			   UART_sendString("TEMP=");
	    			   Uart_intgerToString(temp);
					    _delay_ms(50);
	    			   if(fan_on) {UART_sendByte(13);UART_sendString("fan ON"); _delay_ms(50);SET_BIT(PORTA,PA7);}else {UART_sendByte(13);UART_sendString("fan OFF"); _delay_ms(50);CLEAR_BIT(PORTA,PA7);}
	    		   }*/
//****************************************************************************************************************************
if(buzzer_on)
{
	
	SET_BIT(PORTD,PD2);
	if(method==2){LCD_goToRowColumn(1,7);LCD_displayString("ON");}
	else{LCD_goToRowColumn(1,7);LCD_displayString("ON");UART_sendByte(13);UART_sendString("alarm ON");_delay_ms(100);}
	  	
}
else
{
	CLEAR_BIT(PORTD,PD2);
	if(method==2)
	{LCD_goToRowColumn(1,7);LCD_displayString("FF");}
	else { LCD_goToRowColumn(1,7);LCD_displayString("FF"); UART_sendByte(13);UART_sendString("alarm OFF");_delay_ms(100);}
}
//**************************************************************************************************************************
if(led_on)
{
	SET_BIT(PORTD,PD3);
	if(method==2)
	{LCD_goToRowColumn(1,14);LCD_displayString("ON");}
		
	else {LCD_goToRowColumn(1,14);LCD_displayString("ON"); UART_sendByte(13);UART_sendString("box ON.");_delay_ms(100);}
}
else
{
	CLEAR_BIT(PORTD,PD3);
	if(method==2)
	{LCD_goToRowColumn(1,14);LCD_displayString("FF");}
		
	else 
		{LCD_goToRowColumn(1,14);LCD_displayString("FF");UART_sendByte(13);UART_sendString("box OFF.");_delay_ms(100);}
		_delay_ms(500);

}
	}
SREG  &= ~(1<<7);
LCD_clearScreen();
LCD_displayStringRowColumn(1,0,"system disabled");
_delay_ms(500); /* Press time */


}



