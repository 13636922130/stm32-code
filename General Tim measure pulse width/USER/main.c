#include "stm32f10x.h"
#include "GeneralTim.h"
#include "Usart.h"
int main()
{
	
	uint32_t time;
	GeneralTim_Config();
	USART_Config();
	printf("\nSTM32 ���벶��ʵ��\n");
	printf("\n����K1������K1���µ�ʱ��\n");
	while(1)
	{
		if(TIM_ICUserValueStructure.FinishFlag==1)
		{
			time=TIM_ICUserValueStructure.PeriodValue*0xffff+(TIM_ICUserValueStructure.CCRValue+1);
			printf("\n��øߵ�ƽ����ʱ�䣺%d.%d s\n",time/1000000,time%1000000);
			
			TIM_ICUserValueStructure.FinishFlag=0;
		}
	}
}


