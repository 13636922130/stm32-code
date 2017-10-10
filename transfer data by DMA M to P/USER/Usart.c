#include "Usart.h"

void Usart_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//��ʱ��
	RCC_APB2PeriphClockCmd(USART_GPIO_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(USART_CLK,ENABLE);
	
	//����Usart���õ�GPIO  TX
	GPIO_InitStructure.GPIO_Pin=USART_GPIO_TX_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(USART_GPIO_Port,&GPIO_InitStructure);
	//RX
	GPIO_InitStructure.GPIO_Pin=USART_GPIO_RX_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
 	
	//����Usart
	USART_InitStructure.USART_BaudRate=USART_BRate;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USARTx,&USART_InitStructure);
	
//  NVIC_Config();
	USART_Cmd(USARTx,ENABLE);
}








