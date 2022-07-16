/*
 * TIMER_Interface.h
 *
 *  Created on: Nov 18, 2021
 *      Author: gerges
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

/*Timer0 Initialization*/
void TIMER0_VidInit(void);
/*Set Preload Function*/
void TIMER0_VidSetPreload(u8 Copy_u8Preload);
/*Set CTC Value Function*/
void TIMER0_VidSetCTCValue(u8 Copy_u8CTCValue);

void TIMER0_VidOVF_SetCallBack(void(*Copy_VidCallBack)(void));
void TIMER0_VidCTC_SetCallBack(void(*Copy_VidCallBack)(void));
void TIMER1_VidInit(void);
void TIMER1_VidSetTopValue(u16 Copy_u16TopValue);
void TIMER1_VidSetCTCValueCHA(u16 Copy_u16CTCValue);
void TIMER1_VidSetCTCValueCHB(u16 Copy_u16CTCValue);
void TIMER1_VidSetPreload(u16 Copy_u16Preload);
void TIMER1_VidCompute_Freq_And_Duty(u32 *Copy_u32Freq,u8 *Copy_u8DutyCycle);
void TIMER1_VidOVF_SetCallBack(void(*Copy_VidCallBack)(void));
void TIMER1_VidCTC_SetCallBack(void(*Copy_VidCallBack)(void));
void TIMER2_VidInit(void);
/*Set Preload Function*/
void TIMER2_VidSetPreload(u8 Copy_u8Preload);
/*Set CTC Value Function*/
void TIMER2_VidSetCTCValue(u8 Copy_u8CTCValue);
void TIMER2_VidOVF_SetCallBack(void(*Copy_VidCallBack)(void));

void TIMER2_VidCTC_SetCallBack(void(*Copy_VidCallBack)(void));

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
