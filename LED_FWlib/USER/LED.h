#ifndef __LED_H
#define __LED_H
#include "stm32f10x.h"
#define ON 0
#define OFF 1
void LED_GPIO_Config(void);
#define LED(a) if(a) \
                    GPIO_SetBits(GPIOC,GPIO_Pin_1);\
                    else  \
                    GPIO_ResetBits(GPIOC,GPIO_Pin_1);

#endif //__LED_H

			



										