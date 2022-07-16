#ifndef  HLED_INTERFACE_H_
#define  HLED_INTERFACE_H_

typedef struct{
	u8 Copy_u8Port;
	u8 Copy_u8Pin;
}LED_t;

void HLED_VidInit(LED_t *Copy_Led);
void HLED_VidLed_On(LED_t *Copy_Led);
void HLED_VidLed_Off(LED_t *Copy_Led);
void HLED_VidLed_Toggle(LED_t *Copy_Led);

#endif