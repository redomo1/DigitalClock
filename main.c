/*
 * main.c
 *
 *  Created on: Nov 25, 2021
 *      Author: Eng-Rehab Soliman
 */
#include"LIB\LSTD_TYPES.h"
#include"LIB\LBIT_MATH.h"
#include"MCAL\MDIO\MDIO_Interface.h"
#include"HAL\HCLCD\HCLCD_Interface.h"
#include"HAL\HKPD\HKPD_Interface.h"
#include"MCAL\TIMER\TIMER_Interface.h"
#include<util\delay.h>

u32 hr=0;           // hour variable
u32 min=0;          // minute variable
u32 sec=0;         // second variable
u8 Change=0;
u16 check=0;       // variable to count 1 sec delay


void HCLCD_VidClockSet(void)
{
	u8 LOC_u8KeyValue;
	u8 ARR_u8ClockValue[6] ;
	u16 i=0;
	u8 LOC_u8Count =0;
      /*clock appearance format*/
	HCLCD_VidWriteChar_8Bits('0');
	HCLCD_VidWriteChar_8Bits('0');
	HCLCD_VidSetPosition(1,2);
	HCLCD_VidWriteChar_8Bits(':');
	HCLCD_VidWriteChar_8Bits('0');
	HCLCD_VidWriteChar_8Bits('0');
	HCLCD_VidSetPosition(1,5);
	HCLCD_VidWriteChar_8Bits(':');
	HCLCD_VidWriteChar_8Bits('0');
	HCLCD_VidWriteChar_8Bits('0');

	while(1)
	{   /*Get Char from keypad*/
		LOC_u8KeyValue = HKPD_U8GetKeyPressed();
		if(LOC_u8KeyValue!=NOT_PRESSED)
		{
			if(LOC_u8KeyValue=='C')
			{
				LOC_u8Count++;
				if(LOC_u8Count==3)
				{
					break;
				}
				else
				{
					/*Do Nothing*/
				}

			}
			else
			{
				ARR_u8ClockValue[i]=LOC_u8KeyValue;
				i++;
			}
		}
		else
		{
			/* Do Noting */
		}

	}

	/*Get digit Value by subtract ASCII value of number from ASCII value of zero
	 * and then multiply tens number by 10 to become tens digit*/
	/*Get hour Value*/
	hr  = (ARR_u8ClockValue[0]- 48)*10+ARR_u8ClockValue[1]-48;
	/*Get minute Value*/
	min =(ARR_u8ClockValue[2]-48)*10+ARR_u8ClockValue[3]-48;
	/*Get second Value*/
	sec =(ARR_u8ClockValue[4]-48)*10+ARR_u8ClockValue[5]-48;
	/*display the clock*/
	HCLCD_VidDisplayClock();



}

/* TIMER-1 interrupt sub-routine to control the variables of clock*/
void APP_VidTIMER1_ISR(void)
{
	check++;
}


void HCLCD_VidDisplayClock(void)
{


	// HOURS
	if(hr < 10)
	{
		HCLCD_VidSetPosition(1,0);
		HCLCD_VidWriteNumber_8Bits(hr/10);
		HCLCD_VidSetPosition(1,1);
		HCLCD_VidWriteNumber_8Bits(hr%10);

	}
	else
	{
		HCLCD_VidSetPosition(1,0);
		HCLCD_VidWriteNumber_8Bits(hr);

	}

	// MINUTES
	if(min < 10)
	{
		HCLCD_VidSetPosition(1,3);
		HCLCD_VidWriteNumber_8Bits(min/10);
		HCLCD_VidSetPosition(1,4);
		HCLCD_VidWriteNumber_8Bits(min%10);

	}
	else
	{
		HCLCD_VidSetPosition(1,3);
		HCLCD_VidWriteNumber_8Bits(min);

	}

	// SECONDS
	if(sec < 10)
	{
		HCLCD_VidSetPosition(1,6);
		HCLCD_VidWriteNumber_8Bits(sec/10);
		HCLCD_VidSetPosition(1,7);
		HCLCD_VidWriteNumber_8Bits(sec%10);

	}
	else
	{
		HCLCD_VidSetPosition(1,6);
		HCLCD_VidWriteNumber_8Bits(sec);

	}


}


int main(void)
{
	/* CLCD Initialization */
	HCLCD_Vid8Bits_Init();
	/* KPD Initialization */
	HKPD_VidInit();
	/* Send SET THE CLOCK message to ClCD */
	HCLCD_VidWriteString_8Bits("SET THE CLOCK:");
	_delay_ms(1000);
	/* Clear the screen */
	HCLCD_VidWriteCommand_8Bits(DISPLAY_CLEAR);
	/* please enter first hour and then press clear button
	 * next enter minutes and then press clear button
	 * at last  enter seconds and finally press clear button
	 */
	HCLCD_VidClockSet();
	/*Execute interrupt function*/
	TIMER1_VidCTC_SetCallBack(APP_VidTIMER1_ISR);
	/*Timer1 initialization */
	TIMER1_VidInit();
	/*Set The Value of OCR1A----->1000*/
	TIMER1_VidSetCTCValueCHA(0x03E8);

	/*enable GIE Enable*/
	MGIE_VidEnable();


	/* Super Loop*/
	while(1)
	{
		if(check>=1000)
		{
			check=0;
			sec++;
			Change=1;
		}

		if(sec>59)
		{
			sec=0;
			min++;
			Change=1;

		}

		if(min>59)
		{
			min=0;
			hr++;
			Change=1;

		}

		if (hr==24)
		{
			hr=0;
			Change=1;

		}
		/* if any change occur display it on LCD*/
		if(Change)
		{
			Change=0;
			HCLCD_VidDisplayClock();
		}

	}
	return 0;
}
