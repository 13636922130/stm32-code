#include "stm32f10x.h"

int main(void)
{
	//����GPIOCʱ��ʹ��
	RCC->APB2ENR&=(0<<4);
	RCC->APB2ENR|=(1<<4);
	//����GPIOC_Pin_3ģʽ
	GPIOC->CRL&=(0<<0);
	(GPIOC->CRL)|=((1)<<(0));
	//����͵�ƽ
//(GPIOC->ODR) |= (1<<0);//��
	GPIOC->ODR&=~(1<<0);//��
}
void SystemInit()
{
}
	
