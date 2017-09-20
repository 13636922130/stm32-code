#include "SysTick.h"

void Delay_Ms(uint32_t Ms)
{
	int i;
	SysTick_Config(72000);
	for(i=0;i<Ms;i++)
		while((SysTick->CTRL & (1<<16))==0);
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk);
}


