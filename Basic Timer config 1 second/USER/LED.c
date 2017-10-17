#include "LED.h"
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(LED_Init_CLK,ENABLE);
	GPIO_InitStructure.GPIO_Pin=LED_Init_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(LED_Init_Port,&GPIO_InitStructure);
}
