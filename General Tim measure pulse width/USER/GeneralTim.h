#ifndef __GENERALTIM__H
#define  __GENERALTIM__H

#include "stm32f10x.h"

void GeneralTim_Config(void);

typedef struct
{
	uint8_t StartFlag;
	uint8_t FinishFlag;
	uint16_t CCRValue;
	uint16_t PeriodValue;
}TIM_ICUserValueTypeDef;

extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;


#endif //__GENERALTIM__H


