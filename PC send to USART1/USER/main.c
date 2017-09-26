#include "stm32f10x.h"
#include "Usart.h"

int main()
{
//	uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};
	uint8_t ch;
	Usart_Config();
//	USART_Send_8bit(USARTx,0xff);
//	USART_Send_16bit(USARTx,0xff11);
//	USART_Send_Array(USARTx,a,10);
 // USART_Send_String(USARTx,"Good job!\n");
//	printf("Good job\n");
//	putchar('p');
	while(1)
	{
		ch=getchar();
		printf("ch=%c",ch);
	}
}

