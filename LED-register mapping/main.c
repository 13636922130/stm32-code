#include "stm32f10x.h"

int main(void)
{
	RCC_APB2ENR|=(1<<4);
	
	(GPIOC_CRL)|=((1)<<(0));
	
	GPIOC_ODR&=~(1<<0);
}
void SystemInit()
{
}
	
