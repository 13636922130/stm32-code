#ifndef __USART_H
#define __USART_H
#include "stm32f10x.h"
#define USART_GPIO_TX_Pin        GPIO_Pin_9
#define USART_GPIO_RX_Pin        GPIO_Pin_10
#define USART_GPIO_CLK           RCC_APB2Periph_GPIOA
#define USART_CLK                RCC_APB2Periph_USART1
#define USART_GPIO_Port          GPIOA
#define USART_BRate              115200
#define USARTx                   USART1
void Usart_Config(void);
void USART_Send(USART_TypeDef* USARTy, uint8_t Data);
#endif //__USART_H


