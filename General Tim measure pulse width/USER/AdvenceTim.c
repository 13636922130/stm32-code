#include "AdvenceTim.h"

void AdvenceTim_GPIO_Config(void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
//	/***********以下试用***************/
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
//	GPIO_Init(GPIOB,&GPIO_InitStructure);
//	
//	
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	GPIO_SetBits(GPIOA,GPIO_Pin_12);
//	
//	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
//	/***********以上试用***************/
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}
void AdvenceTim_Mode_Config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeStructure;
  TIM_TimeStructure.TIM_Prescaler=(9-1);
	TIM_TimeStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeStructure.TIM_Period=(8-1);//ARR
	TIM_TimeStructure.TIM_ClockDivision=TIM_CKD_DIV1;//t(TDS)
	TIM_TimeStructure.TIM_RepetitionCounter=1;
	TIM_TimeBaseInit(TIM1,&TIM_TimeStructure);
	
	TIM_OCInitTypeDef Tim_OCInitStructure;
	Tim_OCInitStructure.TIM_OCIdleState=TIM_OCIdleState_Set;//刹车后的电平
	Tim_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	Tim_OCInitStructure.TIM_OCNIdleState=TIM_OCNIdleState_Set;//
	Tim_OCInitStructure.TIM_OCNPolarity=TIM_OCPolarity_High;//有效位时的电平
	Tim_OCInitStructure.TIM_OCPolarity=TIM_OCNPolarity_High;//
	Tim_OCInitStructure.TIM_OutputNState=TIM_OutputNState_Enable;
	Tim_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	Tim_OCInitStructure.TIM_Pulse=(8);//Pulse/Period的占空比
	
	TIM_OC1Init(TIM1,&Tim_OCInitStructure);
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);//配置自动重装载
	
	TIM_BDTRInitTypeDef TIM_BDTInitStructure;
	TIM_BDTInitStructure.TIM_AutomaticOutput=TIM_AutomaticOutput_Enable;
  TIM_BDTInitStructure.TIM_Break=TIM_Break_Enable;
  TIM_BDTInitStructure.TIM_BreakPolarity=TIM_BreakPolarity_High;//刹车输入极性
	TIM_BDTInitStructure.TIM_DeadTime=11;//11*(1/72MHz)(周期) 0.152us=152ns
	TIM_BDTInitStructure.TIM_LOCKLevel=TIM_LOCKLevel_1;
	TIM_BDTInitStructure.TIM_OSSIState=TIM_OSSIState_Enable;
	TIM_BDTInitStructure.TIM_OSSRState=TIM_OSSIState_Enable;
	
	TIM_BDTRConfig(TIM1,&TIM_BDTInitStructure);
	TIM_Cmd(TIM1,ENABLE);
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
}

void Advence_Tim_Init(void)
{
	AdvenceTim_GPIO_Config();
	AdvenceTim_Mode_Config();
}
