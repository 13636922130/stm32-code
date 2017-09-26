#ifndef __USART_H
#define __USART_H
#include "stm32f10x.h"
#include <stdio.h>
#define USART_GPIO_TX_Pin        GPIO_Pin_9
#define USART_GPIO_RX_Pin        GPIO_Pin_10
#define USART_GPIO_CLK           RCC_APB2Periph_GPIOA
#define USART_CLK                RCC_APB2Periph_USART1
#define USART_GPIO_Port          GPIOA
#define USART_BRate              115200
#define USARTx                   USART1
void Usart_Config(void);
void USART_Send_8bit(USART_TypeDef* USARTy, uint8_t Data);
void USART_Send_16bit(USART_TypeDef* USARTy, uint16_t Data);
void USART_Send_Array(USART_TypeDef* USARTy, uint8_t *a,uint8_t num);
void USART_Send_String(USART_TypeDef* USARTy, uint8_t *str);
int fputc(int ch,FILE *f);
#endif //__USART_H


