#include "stm32f10x.h"

int main(void)
{
	*(unsigned int *)0x40021018 |=(1<<3);
	*(unsigned int *)0x40010C00 |=(1<<0);
	*(unsigned int *)0x40010C0C &=~(1<<0);
}
void SystemInit()
{
}
	
