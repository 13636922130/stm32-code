#include "stm32f10x.h"
#include "Usart.h"
#include "LED.h"
int main()
{
	uint8_t ch;
	Usart_Config();
	LED_GPIO_Config();
	LED(ON);
	printf("Send 1 to control LED on, 0 to off\n");
	while(1)
	{
		ch=getchar();
		switch(ch)
		{
			case '1':
				LED(ON);
			break;
			case '0':
				LED(OFF);
			break;
		}
	}
}

