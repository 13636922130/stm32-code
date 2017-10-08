#include "stm32f10x.h"
#include "DMA.h"
#include "LED.h"
extern const uint32_t a[BUFFER_SIZE];
extern uint32_t b[BUFFER_SIZE];
void Delay(uint32_t count)
{
	while(count--);
}
uint8_t cmp()
{
	int i;
	for(i=0;i<BUFFER_SIZE;i++)
	{
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}
int main()
{
	int i;
	uint8_t status;
	LED_GPIO_Config();
	DMA_Config();
	for(i=0;i<7;i++)
	{
		LED(ON);
		Delay(0xfffff);
		LED(OFF);
		Delay(0xfffff);
	}
	status=cmp();
	if(status==1)
	{
		LED(ON);
	}
	else
	{
		LED(OFF);
	}
}

