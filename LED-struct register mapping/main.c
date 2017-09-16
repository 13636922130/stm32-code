#include "stm32f10x.h"

int main(void)
{
	//开启GPIOC时钟使能
	RCC->APB2ENR&=(0<<4);
	RCC->APB2ENR|=(1<<4);
	//配置GPIOC_Pin_3模式
	GPIOC->CRL&=(0<<0);
	(GPIOC->CRL)|=((1)<<(0));
	//输出低电平
//(GPIOC->ODR) |= (1<<0);//灭
	GPIOC->ODR&=~(1<<0);//亮
}
void SystemInit()
{
}
	
