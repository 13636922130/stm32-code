#include "stm32f10x.h"
#include "TIM.h"
#include "LED.h"
uint32_t time=0;

int main()
{
	LED_GPIO_Config();
	TIM_BASE_NVIC_Config();
	TIM_BASE_Config();
	LED(ON);
	while(1)
	{
	if(time==1000)
	{
		LED_TOGGLE;
		time=0;
	}
}
}

