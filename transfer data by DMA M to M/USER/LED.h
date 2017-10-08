#ifndef __LED_H
#define __LED_H
#include "stm32f10x.h"
#define ON 0
#define OFF 1
#define LED_Init_Port GPIOB
#define LED_Init_Pin  GPIO_Pin_10
#define LED_Init_CLK  RCC_APB2Periph_GPIOB
#define LED(a) if(a)\
	GPIO_SetBits(LED_Init_Port,LED_Init_Pin);\
else\
	GPIO_ResetBits(LED_Init_Port,LED_Init_Pin);
void LED_GPIO_Config(void);

#endif //__LED_H

			





										