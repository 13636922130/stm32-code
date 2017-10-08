#include "DMA.h"
const uint32_t a[BUFFER_SIZE]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
                               0x09,0x10,0x11,0x12,0x13,0x14,0x15,0x16,
                               0x17,0x18,0x19,0x20,0x21,0x22,0x23,0x24,
	                             0x25,0x26,0x27,0x28,0x29,0x30,0x31,0x32};
uint32_t b[BUFFER_SIZE];

void DMA_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	DMA_InitStructure.DMA_PeripheralBaseAddr=(uint32_t)b;//a,b可以随意放在Peripheral和Memory 只要修改dir即可
	DMA_InitStructure.DMA_MemoryBaseAddr=(uint32_t)a;
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralDST;
	DMA_InitStructure.DMA_BufferSize=BUFFER_SIZE;
	DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Enable;
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Word;
	DMA_InitStructure.DMA_MemoryDataSize=DMA_MemoryDataSize_Word;
	DMA_InitStructure.DMA_Mode=DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority=DMA_Priority_VeryHigh;
	DMA_InitStructure.DMA_M2M=DMA_M2M_Enable;
	
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);
	DMA_Cmd(DMA1_Channel1,ENABLE);
}


