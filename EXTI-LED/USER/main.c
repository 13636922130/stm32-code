#include "stm32f10x.h"
#include "LED.h"
#include "EXTI.h"

int main()
{
	EXTI_Key_Config();
	LED_GPIO_Config();
	LED(OFF);
	while(1)
	{
	}
}

