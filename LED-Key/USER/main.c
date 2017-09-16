#include "stm32f10x.h"
#include "LED.h"
#include "KEY.h"
int main()
{
	LED_GPIO_Config();
	Key_GPIO_Config();
	LED(OFF);
	while(1)
	{
		if(Key_Scan(GPIOE,GPIO_Pin_4)==KEY_ON)
		{
			GPIOE->ODR ^= GPIO_Pin_6;
		}
	}
}

