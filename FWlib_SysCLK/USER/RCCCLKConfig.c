#include "RCCCLKConfig.h"

void HSE_SetSysCLK(uint32_t RCC_PLLMul_x)
{
	ErrorStatus HSE_Status;
	RCC_DeInit();
	//����HSEʱ��
	RCC_HSEConfig(RCC_HSE_ON);
	//�ȴ�HSE״̬
	HSE_Status=RCC_WaitForHSEStartUp();
	if(HSE_Status==SUCCESS)
	{
		//ʹ��Ԥȡָ
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		//����PLLCLK=HSE*RCC_PLLMul_x
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_x);
		RCC_PLLCmd(ENABLE);
		//�ȴ�PLL�ȶ�
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);
		
		//����SYSCLK
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		//�ȴ�SYSCLK������
		while(RCC_GetSYSCLKSource()!=0x08);
	}
}

