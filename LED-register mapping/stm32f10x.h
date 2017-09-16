//Õ‚…Ëµÿ÷∑”≥…‰
#define PERIPH_BASE        (unsigned int) 0x40000000
#define ABP1_BASE                         PERIPH_BASE
#define APB2_BASE                         PERIPH_BASE+0x10000
#define AHB_BASE                          PERIPH_BASE+0x20000
#define RCC_BASE                          AHB_BASE+0x1000
#define RCC_APB2ENR      *(unsigned int*)(RCC_BASE+0x18)
#define GPIOC_BASE                        APB2_BASE+0x1000
#define GPIOC_CRL        *(unsigned int*)(GPIOC_BASE)
#define GPIOC_ODR        *(unsigned int*)(GPIOC_BASE+0x0c)
#define GPIOC_BSRR       *(unsigned int*)(GPIOC_BASE+0x10)
#define GPIOC_BRR        *(unsigned int*)(GPIOC_BASE+0x14)




