#include "Usart.h"
void Usart_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//打开时钟
	RCC_APB2PeriphClockCmd(USART_GPIO_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(USART_CLK,ENABLE);
	
	//配置Usart所用的GPIO  TX
	GPIO_InitStructure.GPIO_Pin=USART_GPIO_TX_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(USART_GPIO_Port,&GPIO_InitStructure);
	//RX
	GPIO_InitStructure.GPIO_Pin=USART_GPIO_RX_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART_GPIO_Port,&GPIO_InitStructure);
	
	//配置Usart
	USART_InitStructure.USART_BaudRate=USART_BRate;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Mode=USART_Parity_No;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USARTx,&USART_InitStructure);
	USART_Cmd(USARTx,ENABLE);
}
void USART_Send(USART_TypeDef* USARTy, uint8_t Data)
{
	USART_SendData(USARTy,Data);
	while(USART_GetFlagStatus(USARTy,USART_FLAG_TXE)!=SET);
}

