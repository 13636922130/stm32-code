#include "GeneralTim.h"


TIM_ICUserValueTypeDef TIM_ICUserValueStructure = {0,0,0,0};


void GeneralTim_NVIC_Config(void)
{
	NVIC_InitTypeDef TIM_NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIM_NVIC_InitStructure.NVIC_IRQChannel=TIM5_IRQn;
	TIM_NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	TIM_NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	TIM_NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&TIM_NVIC_InitStructure);
}
void GeneralTim_GPIO_Config(void)
{
	//°´¼üPA0  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

void GeneralTim_Mode_Config(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_Base_InitStructure;
	TIM_Base_InitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_Base_InitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_Base_InitStructure.TIM_Period=0xffff;
	TIM_Base_InitStructure.TIM_Prescaler=(72-1);
	TIM_Base_InitStructure.TIM_RepetitionCounter=0;
	
	TIM_TimeBaseInit(TIM5,&TIM_Base_InitStructure);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter=0;
	TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_Rising;
	TIM_ICInitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
	
	TIM_ICInit(TIM5,&TIM_ICInitStructure);
	
	TIM_ClearFlag(TIM5,TIM_FLAG_Update|TIM_FLAG_CC1);
	TIM_ITConfig(TIM5,TIM_FLAG_Update|TIM_FLAG_CC1,ENABLE);
	TIM_Cmd(TIM5,ENABLE);
}

void GeneralTim_Config(void)
{
	GeneralTim_NVIC_Config();
	GeneralTim_GPIO_Config();
	GeneralTim_Mode_Config();
}






