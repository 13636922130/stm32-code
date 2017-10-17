#include "KEY.h"
void Delay(uint32_t count)
{
	while(count--);
}
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}
uint8_t Key_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
	{
		Delay(10000);
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
		{
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);
		return KEY_ON;
		}
		return KEY_OFF;
	}
	else return KEY_OFF;
}


