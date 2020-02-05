/*
 * USART.c
 *
 * Created: 12/09/2015 05:47:55 م
 *  Author: User
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "USART.h"
//Initialization for specific
void USART_vInitSpecific()
{
	//UCSRA|=(1<<TXC);
	UCSRB=(1<<RXEN)|(1<<TXEN);       //enable the transmitter and reciever
	UCSRC |=(1<<UCSZ0)|(1<<UCSZ1);  //choose 8 bit mode
	UBRRL=51;          //to choose baud rate
	UBRRH=0;
}
/*
void USART_vInit(StrUSART_InitT *StrPtrParam)
{
	UCSRB|=(((StrPtrParam->eCommunicationMode)&0x03)<<TXEN);
	UCSRC|=((StrPtrParam->eModeSelect)<<UMSEL);
	UCSRC|=(((StrPtrParam->eParityMode)&0x03)<<UPM0);
	UCSRC|=((StrPtrParam->eStopBit)<<USBS);
	UCSRC|=(((StrPtrParam->eDataSize)&0x03)<<UCSZ0);
	UCSRB|=(((StrPtrParam->eDataSize)&0x04)<<UCSZ2);
	UCSRB|=(((StrPtrParam->eInterrupeEnable)&0x03)<<TXCIE);
	UCSRA|=((StrPtrParam->eU2XMode)<<U2X);
	//UBRRL=(INT8U)(StrPtrParam->BaudRate);
	//UBRRH=((StrPtrParam->BaudRate)>>8);
	//baud Rate for freq 8 MHZ
	switch((StrPtrParam->BaudRate))
	{
		case 2400:
			UBRRL=207;
			UBRRH=0;
			break;		
		case 4800:
			UBRRL=103;
			UBRRH=0;
			break;
		case 9600:
			UBRRL=51;
			UBRRH=0;
			break;
		case 14400:
			UBRRL=34;
			UBRRH=0;
			break;
		case 19200:
			UBRRL=25;
			UBRRH=0;
			break;
		case 28800:
			UBRRL=16;
			UBRRH=0;
			break;
		case 38400:
			UBRRL=12;
			UBRRH=0;
			break;
		case 57600:
			UBRRL=8;
			UBRRH=0;
			break;
		case 76800:
			UBRRL=6;
			UBRRH=0;
			break;
		case 115200:
			UBRRL=3;
			UBRRH=0;
			break;
		case 230400:
			UBRRL=1;
			UBRRH=0;
			break;
		case 250000:
			UBRRL=1;
			UBRRH=0;
			break;
		case 500000:
			UBRRL=0;
			UBRRH=0;
			break;
	}
}
*/
void USART_vSendByte(INT8U u8Data)
{	
	if(u8Data!=0x00)         //عشان ابعت اللى بيتداس على ال كيبورد 
	{
	while((UCSRA&(1<<UDRE))==0);
	UDR=u8Data;
	}	
}

INT8U USART_u8RecieveByte()
{
	while((UCSRA&(1<<RXC))==0);
	return UDR;
}

void USART_vSendString(INT8U *StringDisplay)
{
	INT8U i;
	for(i=0;StringDisplay!=0;i++)
	{
		USART_vSendByte(StringDisplay[i]);
	}
}
//for main *******************************************************
/*
StrUSART_InitT param;
param.eCommunicationMode=Both;
param.eModeSelect=Asynchronous;
param.eParityMode=Disabled;
param.eStopBit=OneBit;
param.eU2XMode=Disabled;
param.eDataSize=EightBits;
param.eInterrupeEnable=IntDiabled;
param.BaudRate=9600;
USART_vInit(&param);
*/