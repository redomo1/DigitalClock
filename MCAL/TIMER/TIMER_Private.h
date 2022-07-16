/*
 * TIMER_Private.h
 *
 *  Created on: Nov 18, 2021
 *      Author: gerges
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR0           *((volatile u8*)0x53)
#define TIMSK           *((volatile u8*)0x59)
#define TCNT0           *((volatile u8*)0x52)
#define OCR0            *((volatile u8*)0x5C)

#define TCCR1A          *((volatile u8*)0x4F)
#define TCCR1B          *((volatile u8*)0x4E)
#define ICR1            *((volatile u16*)0x46)
#define OCR1A           *((volatile u16*)0x4A)
#define OCR1B           *((volatile u16*)0x48)
#define TCNT1           *((volatile u16*)0x4C)

#define TCCR2           *((volatile u8*)0x45)
#define TCNT2           *((volatile u8*)0x44)
#define OCR2            *((volatile u8*)0x43)

#define TIMER_STOPPED         0
#define TIMER_NO_PRESCALER    1
#define TIMER_8_PRESCALER     2
#define TIMER_64_PRESCALER    3
#define TIMER_256_PRESCALER   4
#define TIMER_1024_PRESCALER  5
#define TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE  6
#define TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE   7


#define TIMER0_NORMAL_MODE             1
#define TIMER0_CTC_MODE                2
#define TIMER0_PHASECORRECT_PWM_MODE   3
#define TIMER0_FAST_PWM_MODE           4

#define TIMER0_CTC_INTERRUPT_ENABLED      0
#define TIMER0_CTC_INTERRUPT_DISABLED     1


#define TIMER0_OC0_PIN_DISCONNECTED     0
#define TIMER0_OC0_PIN_TOGGLE           1
#define TIMER0_OC0_PIN_SET              2
#define TIMER0_OC0_PIN_CLR              3

/*Set Timer0 PWM Mode*/
#define TIMER0_NUN_INVERTING_PWM        1
#define TIMER0_INVERTING_PWM            2

/*Select Timer1 Modes options*/
#define TIMER1_NORMAL_MODE                                           0
#define TIMER1_PHASECORRECT_PWM_MODE_8BITS                           1
#define TIMER1_PHASECORRECT_PWM_MODE_9BITS                           2
#define TIMER1_PHASECORRECT_PWM_MODE_10BITS                          3
#define TIMER1_CTC_MODE_WITH_OCR1A                                   4
#define TIMER1_FAST_PWM_MODE_8BITS                                   5
#define TIMER1_FAST_PWM_MODE_9BITS                                   6
#define TIMER1_FAST_PWM_MODE_10BITS                                  7
#define TIMER1_PWM_PHASE_AND_FREQUANCY_CORRECT_WITH_ICR1             8
 #define TIMER1_PWM_PHASE_AND_FREQUANCY_CORRECT_WITH_OCR1A           9
#define TIMER1_PHASECORRECT_PWM_MODE_WITH_ICR1                       10
#define TIMER1_PHASECORRECT_PWM_MODE_WITH_OCR1A                      11
#define TIMER1_CTC_MODE_WITH_ICR1                                    12
#define TIMER1_FAST_PWM_MODE_WITH_ICR1                               13
#define  TIMER1_FAST_PWM_MODE_WITH_OCR1A                             14

/*Timer1  set   normal or  CTC mode OC1A \ OC1B PIN Options:*/
#define TIMER1_OC1A_OR_OC1B_PIN_DISCONNECTED      0
#define  TIMER1_OC1A_OR_OC1B_PIN_TOGGLE           1
#define  TIMER1_OC1A_OR_OC1B_PIN_CLR              2
#define  TIMER1_OC1A_OR_OC1B_PIN_SET              3

/*timer1 channel options:*/
#define CHANNELA     0
#define CHANNELB     1

/*Select ICU Edge*/
#define RISING_EDGE      1
#define FALLING_EDGE     2

#define TIMER1_CTC_INTERRUPT_ENABLED      0
#define TIMER1_CTC_INTERRUPT_DISABLED     1

#define TIMER2_NORMAL_MODE             1
#define TIMER2_CTC_MODE                2
#define TIMER2_PHASECORRECT_PWM_MODE   3
#define TIMER2_FAST_PWM_MODE           4

#define TIMER2_CTC_INTERRUPT_ENABLED      0
#define TIMER2_CTC_INTERRUPT_DISABLED     1


#define TIMER2_OC2_PIN_DISCONNECTED     0
#define TIMER2_OC2_PIN_TOGGLE           1
#define TIMER2_OC2_PIN_SET              2
#define TIMER2_OC2_PIN_CLR              3

/*Set Timer0 PWM Mode*/
#define TIMER2_NUN_INVERTING_PWM        1
#define TIMER2_INVERTING_PWM            2

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
