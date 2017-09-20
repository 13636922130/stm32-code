#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
#define KEY_ON 0
#define KEY_OFF 1
//#define Key_GPIO_Port GPIOC
//#define Key_GPIO_Pin GPIO_Pin_13
void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
#endif //KEY_H

