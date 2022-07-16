/*
 * MADC_Private.h
 *
 *  Created on: Nov 22, 2021
 *      Author: gerges
 */

#ifndef MCAL_MADC_MADC_PRIVATE_H_
#define MCAL_MADC_MADC_PRIVATE_H_

#define ADMUX      *((volatile u8*)0x27)
#define ADCSRA     *((volatile u8*)0x26)
#define ADC        *((volatile u16*)0x24)
#define SFIOR      *((volatile u16*)0x50)

#define  MADC_AVCC_REFERENCEVOLATGE      1
#define  MADC_2.56V_REFERENCEVOLATGE     2

#define MADC_BIT_MASKING_PRESCALER     	0xF8
#define MADC_BIT_MASKING_CHANNEL       	0x07
#define MADC_BIT_MASKING_REG_CHANNEL   	0xE0
#define MADC_BIT_MASKING_TRIGGER_SOURCE	0x1F

#define MADC_2_PRESCALER     1
#define MADC_4_PRESCALER     2
#define MADC_8_PRESCALER     3
#define MADC_16_PRESCALER    4
#define MADC_32_PRESCALER    5
#define MADC_64_PRESCALER    6
#define MADC_128_PRESCALER   7

#define MADC_RIGHT_ADJUST    0
#define MADC_LEFT_ADJUST     1


#define MADC_FREE_RUNING_TRIGGER_SOURCE					0x00
#define MADC_ANALOG_COMPARATOR_TRIGGER_SOURCE			0x20
#define MADC_EXTI_TRIGGER_SOURCE						0x40
#define MADC_TIMER0_COMRARE_MATCH_TRIGGER_SOURCE		0x60
#define MADC_TIMER0_OVERFLOW_TRIGGER_SOURCE				0x80
#define MADC_TIMER0_COMRARE_MATCH_B_TRIGGER_SOURCE		0xA0
#define MADC_TIMER1_OVERFLOW_TRIGGER_SOURCE				0xC0
#define MADC_TIMER1_CAPTURE_EVENT_TRIGGER_SOURCE		0xE0

#endif /* MCAL_MADC_MADC_PRIVATE_H_ */