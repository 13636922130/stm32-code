#include "stm32f10x.h"
#include "DMA.h"
#include "LED.h"
#include "Usart.h"
extern const uint8_t a[BUFFER_SIZE];
void Delay(uint32_t count)
{
	while(count--);
}

int main()
{
	LED_GPIO_Config();
	Usart_Config();
	DMA_Config();
	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
	while(1)
	{
		LED(ON);
		Delay(0xfffff);
		LED(OFF);
		Delay(0xfffff);
	}
}

