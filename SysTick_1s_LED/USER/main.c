#include "stm32f10x.h"
#include "LED.h"
#include "SysTick.h"

int main()
{
	LED_GPIO_Config();
	while(1)
	{
		LED(ON);
		Delay_Ms(1000);
		LED(OFF);
		Delay_Ms(1000);
	}
}

