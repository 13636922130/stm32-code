#include "stm32f10x.h"
#include "GeneralTim.h"
#include "Usart.h"
int main()
{
	
	uint32_t time;
	GeneralTim_Config();
	USART_Config();
	printf("\nSTM32 输入捕获实验\n");
	printf("\n按下K1，测试K1按下的时间\n");
	while(1)
	{
		if(TIM_ICUserValueStructure.FinishFlag==1)
		{
			time=TIM_ICUserValueStructure.PeriodValue*0xffff+(TIM_ICUserValueStructure.CCRValue+1);
			printf("\n测得高电平脉宽时间：%d.%d s\n",time/1000000,time%1000000);
			
			TIM_ICUserValueStructure.FinishFlag=0;
		}
	}
}


