#include "stm32f10x.h"
#include "LED.h"
void Delay(uint32_t count)
{
	while(count--);
}
int main()
{
	LED_GPIO_Config();
	//while(1)
	//{
	LED(ON);
	//	Delay(1000000);
	//	LED(OFF);
	//	Delay(1000000);
	//}
}

