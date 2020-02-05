/*
 * USART.h
 *
 * Created: 12/09/2015 05:48:18 م
 *  Author: User
 */ 


#ifndef USART_H_
#define USART_H_

void USART_vInitSpecific();
void USART_vSendByte(INT8U u8Data);
INT8U USART_u8RecieveByte();
void USART_vSendString(INT8U *StringDisplay);
typedef enum
{
	transmitter=1,
	receiver=2,
	Both=3,

}enumCommunicationMode;
typedef enum 
{
	Asynchronous,
	Synchronous
}enumModeSelect;

typedef enum 
{
	Disabled=0,
	Even=2,
	Odd=3
}enumParityMode;

typedef enum
{
	OneBit,
	TwoBits
}enumStopBit;

typedef enum
{
	FiveBits,
	SixBits,
	SevenBits,
	EightBits,
	NineBits
}enumDataSize;

typedef enum 
{
	IntDiabled,
	IntTransmitter,
	IntReceiver,
	IntBoth
}enumInterrupeEnable; 
typedef enum
{
	U2XDisabled,
	U2XEnabled
}enumU2XMode; 

typedef enum
{
	e2400,
	e4800,
	e9600,
	e14400,
	e19200,
	e28800,
	e38400,
	e57600,
	e76800,
	e115200,
	e230400,
	e250000,
	e500000,
	e1000000,
	e2000000
};
typedef struct 
{
	enumCommunicationMode eCommunicationMode;  //enable transmitter or receiver or both
	enumModeSelect eModeSelect;   //synchronous or not
	enumParityMode eParityMode ;   //odd or even or disabled
	enumStopBit eStopBit;	   //one bit or two
	enumDataSize eDataSize;     //character size	
	INT32U BaudRate;  //to choose Rate
	enumInterrupeEnable eInterrupeEnable;
	enumU2XMode eU2XMode;
}StrUSART_InitT;

void USART_vInit(StrUSART_InitT *StrPtrParam);
#endif /* USART_H_ */