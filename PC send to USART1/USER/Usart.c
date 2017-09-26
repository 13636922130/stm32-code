#include "Usart.h"
void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
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
 	
	//配置Usart
	USART_InitStructure.USART_BaudRate=USART_BRate;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Mode=USART_Parity_No;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USARTx,&USART_InitStructure);
	
//  NVIC_Config();
	USART_ITConfig(USARTx,USART_IT_RXNE,ENABLE);
	USART_Cmd(USARTx,ENABLE);
}
void USART_Send_8bit(USART_TypeDef* USARTy, uint8_t Data)
{
	USART_SendData(USARTy,Data);
	while(USART_GetFlagStatus(USARTy,USART_FLAG_TXE)!=SET);
}

void USART_Send_16bit(USART_TypeDef* USARTy, uint16_t Data)
{
	uint8_t temp_h,temp_l;
	temp_h=(Data&0xff00)>>8;
	temp_l=(Data&0xff);
	USART_SendData(USARTy,temp_h);
	while(USART_GetFlagStatus(USARTy,USART_FLAG_TXE)!=SET);
	USART_SendData(USARTy,temp_l);
	while(USART_GetFlagStatus(USARTy,USART_FLAG_TXE)!=SET);
}
void USART_Send_Array(USART_TypeDef* USARTy, uint8_t *a,uint8_t num)
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		USART_Send_8bit(USARTy,a[i]);
	}while(USART_GetFlagStatus(USARTy,USART_FLAG_TC)!=SET);
}

void USART_Send_String(USART_TypeDef* USARTy, uint8_t *str)
{
	uint8_t i=0;
//	do
//	{
//		USART_Send_8bit(USARTy,*(str+i));
//		i++;
//	}while(*(str+i)!='\0');
	while(str[i]!='\0')
	{
		USART_Send_8bit(USARTy,str[i]);
		i++;
	}
	while(USART_GetFlagStatus(USARTy,USART_FLAG_TC)!=SET);
}
//重定义c库函数printf到串口，重定义后才能使用printf函数
int fputc(int ch,FILE *f)
{
	USART_SendData(USARTx,(uint8_t)ch);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE)==RESET);
	return (ch);
}
int fgetc(FILE *f)
{
	while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)!=SET);
	return (int)USART_ReceiveData(USART1);
}






