#include "stm32f10x.h"
#include "LED.h"
#include "RCCCLKConfig.h"
void Delay(uint32_t count)
{
	while(count--);
}
int main()
{
	HSE_SetSysCLK(RCC_PLLMul_9);
	
	LED_GPIO_Config();
	while(1)
	{
		LED(ON);
		Delay(0xFFFFF);
		LED(OFF);
		Delay(0xFFFFF);
	}
}

