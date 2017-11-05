#ifndef __TIM_H
#define  __TIM_H

#include "stm32f10x.h"
#include "stm32f10x_tim.h"

#define TIM_BASE_IRQn          TIM6_IRQn
#define TIMx                   TIM6
#define Prescaler              71
#define Period                 999
#define TIM_BASE_CLK           RCC_APB1Periph_TIM6
#define TIM_BASE_ClockCmd      RCC_APB1PeriphClockCmd

void TIM_BASE_NVIC_Config(void);
void TIM_BASE_Config(void);

#endif //__TIM_H



