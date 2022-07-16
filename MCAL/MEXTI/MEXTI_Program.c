/*
 * MEXTI_Program.c
 *
 *  Created on: Nov 15, 2021
 *      Author: gerges
 */

#include"..\..\LIB\LSTD_TYPES.h"
#include"..\..\LIB\LBIT_MATH.h"

#include"MEXTI_Private.h"
#include"MEXTI_Config.h"
#include"MEXTI_Interface.h"

void (*CallBackFunction)(void);

/* EXTI0 Initialization*/
void MEXTI0_VidInit(void)
{
	/*Select Sense Control*/
#if MEXTI_SET_SENSE_CONTROL==MEXTI_LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif MEXTI_SET_SENSE_CONTROL==MEXTI_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif MEXTI_SET_SENSE_CONTROL==MEXTI_FALLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif MEXTI_SET_SENSE_CONTROL==MEXTI_RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#else
	#error"Sense Control Option is not valid"
#endif
	/*Enable to EXTI0*/
	SET_BIT(GICR,6);
}
/* EXTI1 Initialization*/
void MEXTI1_VidInit(void)
{
	/*Select Sense Control*/
#if MEXTI_SET_SENSE_CONTROL==MEXTI_LOW_LEVEL
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif MEXTI_SET_SENSE_CONTROL==MEXTI_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif MEXTI_SET_SENSE_CONTROL==MEXTI_FALLING_EDGE
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#elif MEXTI_SET_SENSE_CONTROL==MEXTI_RISING_EDGE
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#else
	#error"Sense Control Option is not valid"
#endif
	/*Enable to EXTI1*/
	SET_BIT(GICR,7);
}
/* EXTI2 Initialization*/
void MEXTI2_VidInit(void)
{
	/*Select Sense Control*/

#if MEXTI_SET_SENSE_CONTROL==MEXTI_FALLING_EDGE
	CLR_BIT(MCUCSR,6);
#elif MEXTI_SET_SENSE_CONTROL==MEXTI_RISING_EDGE
	SET_BIT(MCUCSR,6);
#else
	#error"Sense Control Option is not valid"
#endif
	/*Enable to EXTI2*/
	SET_BIT(GICR,5);
}
/*select sense control Function*/
void MEXTI_VidSenseControl(u8 Copy_u8EXTI_ID,u8 Copy_u8SenseControl)
{
	switch(Copy_u8EXTI_ID)
	{
	case EXTI0:
		if(Copy_u8SenseControl==MEXTI_LOW_LEVEL)
		{
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		else if(Copy_u8SenseControl==MEXTI_ANY_LOGICAL_CHANGE)
		{
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		else if(Copy_u8SenseControl==MEXTI_FALLING_EDGE)
		{
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(Copy_u8SenseControl==MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case EXTI1:
		if(Copy_u8SenseControl==MEXTI_LOW_LEVEL)
		{
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		else if(Copy_u8SenseControl==MEXTI_ANY_LOGICAL_CHANGE)
		{
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		else if(Copy_u8SenseControl==MEXTI_FALLING_EDGE)
		{
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(Copy_u8SenseControl==MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case EXTI2:
		if(Copy_u8SenseControl==MEXTI_FALLING_EDGE)
		{
			CLR_BIT(MCUCSR,6);
		}
		else if(Copy_u8SenseControl==MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCSR,6);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	}
}

void EXTI0_Set_CallBackFunction(void (*Copy_CallBackFunction)(void))
{
	CallBackFunction=Copy_CallBackFunction;
}
void __vector_1(void)       __attribute__((signal));
void __vector_1(void)
{
	CallBackFunction();
	//HLED_VidLed_Toggle(&LED1);
}
