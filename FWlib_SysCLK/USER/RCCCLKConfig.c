#include "RCCCLKConfig.h"

void HSE_SetSysCLK(uint32_t RCC_PLLMul_x)
{
	ErrorStatus HSE_Status;
	RCC_DeInit();
	//开启HSE时钟
	RCC_HSEConfig(RCC_HSE_ON);
	//等待HSE状态
	HSE_Status=RCC_WaitForHSEStartUp();
	if(HSE_Status==SUCCESS)
	{
		//使能预取指
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		//配置PLLCLK=HSE*RCC_PLLMul_x
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_x);
		RCC_PLLCmd(ENABLE);
		//等待PLL稳定
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);
		
		//配置SYSCLK
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		//等待SYSCLK的配置
		while(RCC_GetSYSCLKSource()!=0x08);
	}
}

