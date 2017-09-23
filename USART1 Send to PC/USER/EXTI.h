#ifndef __EXTI_H
#define __EXTI_H
#include "stm32f10x.h"
#define EXTI_Key_Init_Port GPIOA
#define EXTI_Key_Init_Pin  GPIO_Pin_0
#define EXTI_Key_Init_CLK  RCC_APB2Periph_GPIOA
void EXTI_Key_Config(void);

#endif //__EXTI_H

