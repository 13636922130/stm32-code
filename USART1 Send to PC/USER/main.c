#include "stm32f10x.h"
#include "Usart.h"

int main()
{
	Usart_Config();
	USART_Send(USARTx,'6');
	while(1)
	{
	}
}

