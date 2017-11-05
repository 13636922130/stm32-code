#include "TIM.h"

void TIM_BASE_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitStructure.NVIC_IRQChannel=TIM_BASE_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
void TIM_BASE_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	
	TIM_BASE_ClockCmd(TIM_BASE_CLK,ENABLE);
	
	TIM_InitStructure.TIM_Period=999;
	TIM_InitStructure.TIM_Prescaler=71;
	TIM_TimeBaseInit(TIMx,&TIM_InitStructure);
	
	TIM_ClearFlag(TIMx,TIM_FLAG_Update);
	TIM_ITConfig(TIMx,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIMx,ENABLE);
	
}


