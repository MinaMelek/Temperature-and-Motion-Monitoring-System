/*
 * STD_TYPES.h
 *
 * Created: 29/08/2015 01:58:31 م
 *  Author: User
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char INT8U;
typedef signed char   INT8S;
typedef unsigned short int INT16U;
typedef unsigned long int  INT32U;
//typedef unsigned char:4 INT4U;
typedef enum{eFalse=0,
             eTrue} BOOLEAN;
			 
typedef struct Port 
{
	char FirstHalf:4;
	char SecondHalf:4;
}STRUCT8U;

typedef struct SetPort 
{
	char P0:1;
	char P1:1;
	char P2:1;
	char P3:1;
	char P4:1;
	char P5:1;
	char P6:1;
	char P7:1;
}STRUCT8USET;





#endif /* STD_TYPES_H_ */