#include "motor.h"

void Motor_GPIO_Config(void)
{
	GPIO_InitTypeDef                GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
/*¡¾Ç°ÓÒÂÖ¡¿*/
	GPIO_InitStructure.GPIO_Mode       = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin        = MOTOR_Q_ENA_PIN;
	GPIO_InitStructure.GPIO_Speed      = GPIO_Speed_50MHz;
	GPIO_Init                        (MOTOR_Q_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode       = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin        = MOTOR_Q_IN1_PIN;
	GPIO_InitStructure.GPIO_Speed      = GPIO_Speed_50MHz;
	GPIO_Init                        (MOTOR_Q_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode      = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin       = MOTOR_Q_IN2_PIN;
	GPIO_InitStructure.GPIO_Speed     = GPIO_Speed_50MHz;
	GPIO_Init                        (MOTOR_Q_PORT, &GPIO_InitStructure);
	
/*¡¾Ç°×óÂÖ¡¿*/	
	GPIO_InitStructure.GPIO_Mode       = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin        = MOTOR_Q_ENR_PIN;
	GPIO_InitStructure.GPIO_Speed      = GPIO_Speed_50MHz;
	GPIO_Init                        (MOTOR_Q_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin        = MOTOR_Q_IN3_PIN;
	GPIO_Init                        (MOTOR_Q_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin        = MOTOR_Q_IN4_PIN;
	GPIO_Init                        (MOTOR_Q_PORT, &GPIO_InitStructure);
/*¡¾ºóÓÒÂÖ¡¿*/
	GPIO_InitStructure.GPIO_Mode       = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin        = MOTOR_H_ENA_PIN;
	GPIO_InitStructure.GPIO_Speed      = GPIO_Speed_50MHz;
	GPIO_Init                         (MOTOR_H_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin        = MOTOR_H_IN1_PIN;
	GPIO_Init                         (MOTOR_H_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin       = MOTOR_H_IN2_PIN;
	GPIO_Init                        (MOTOR_H_PORT, &GPIO_InitStructure);
	
/*¡¾ºó×óÂÖ¡¿*/	
	GPIO_InitStructure.GPIO_Mode       = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin        = MOTOR_H_ENR_PIN;
	GPIO_InitStructure.GPIO_Speed      = GPIO_Speed_50MHz;
	GPIO_Init                        (MOTOR_H_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin        = MOTOR_H_IN3_PIN;
	GPIO_Init                        (MOTOR_H_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin        = MOTOR_H_IN4_PIN;
	GPIO_Init                        (MOTOR_H_PORT, &GPIO_InitStructure);
	
}



