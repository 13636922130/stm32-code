#ifndef __LED_H
#define __LED_H
#include "stm32f10x.h"
#define ON 0
#define OFF 1
#define LED(a) if(a)\
	GPIO_SetBits(GPIOB,GPIO_Pin_10);\
else\
	GPIO_ResetBits(GPIOB,GPIO_Pin_10);
void LED_GPIO_Config(void);
#endif //__LED_H

			




										