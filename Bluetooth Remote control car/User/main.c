	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "motor.h"
void delay(uint32_t i)
{
	while(i--);
}
uint8_t ch;
int main(void)
{	
	//结束添加
	Motor_GPIO_Config();
	USART_Config();
	
	printf( "【和谐号发车啦！！！】" );
 
	while (1)
	{
		ch = getchar();
		
	//  printf( "ch=%c\n",ch );
		
		switch(ch)
   {
		 
			case '1':
				//printf( "↑" );

	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_ENA_PIN);
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_IN1_PIN);
	      GPIO_ResetBits   (MOTOR_Q_PORT, MOTOR_Q_IN2_PIN);
			
		    GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_ENR_PIN);
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_IN3_PIN);
	      GPIO_ResetBits   (MOTOR_Q_PORT, MOTOR_Q_IN4_PIN);
			  delay(500000);
	      GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_ENA_PIN);
	      GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_IN1_PIN);
	      GPIO_ResetBits   (MOTOR_H_PORT, MOTOR_H_IN2_PIN);
			  delay(500000);
		    GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_ENR_PIN);
	      GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_IN3_PIN);
	      GPIO_ResetBits   (MOTOR_H_PORT, MOTOR_H_IN4_PIN);
				break;
		 
			case '2':
				//printf( "↓" );
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_ENA_PIN);
	      GPIO_ResetBits   (MOTOR_Q_PORT, MOTOR_Q_IN1_PIN);
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_IN2_PIN);
			
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_ENR_PIN);
	      GPIO_ResetBits   (MOTOR_Q_PORT, MOTOR_Q_IN3_PIN);
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_IN4_PIN);
			  delay(500000);
	      GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_ENA_PIN);
	      GPIO_ResetBits   (MOTOR_H_PORT, MOTOR_H_IN1_PIN);
	      GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_IN2_PIN);
			  delay(500000);
		    GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_ENR_PIN);
	      GPIO_ResetBits   (MOTOR_H_PORT, MOTOR_H_IN3_PIN);
	      GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_IN4_PIN);
			  break;
		 
			case '3':// printf( "←" );
				GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_ENA_PIN);
	      GPIO_ResetBits     (MOTOR_Q_PORT, MOTOR_Q_IN1_PIN);
	      GPIO_SetBits   (MOTOR_Q_PORT, MOTOR_Q_IN2_PIN);
			
		    GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_ENR_PIN);
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_IN3_PIN);
	      GPIO_ResetBits   (MOTOR_Q_PORT, MOTOR_Q_IN4_PIN);
				delay(500000);
			
			
					GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_ENA_PIN);
					GPIO_ResetBits   (MOTOR_H_PORT, MOTOR_H_IN1_PIN);
					GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_IN2_PIN);
					delay(500000);
					GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_ENR_PIN);
					GPIO_SetBits   (MOTOR_H_PORT, MOTOR_H_IN3_PIN);
					GPIO_ResetBits     (MOTOR_H_PORT, MOTOR_H_IN4_PIN);
			  break;
		 
			case '4': //printf( "→" );
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_ENA_PIN);
	      GPIO_SetBits   (MOTOR_Q_PORT, MOTOR_Q_IN1_PIN);
	      GPIO_ResetBits     (MOTOR_Q_PORT, MOTOR_Q_IN2_PIN);
			
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_ENR_PIN);
	      GPIO_ResetBits   (MOTOR_Q_PORT, MOTOR_Q_IN3_PIN);
	      GPIO_SetBits     (MOTOR_Q_PORT, MOTOR_Q_IN4_PIN);
			  delay(500000);
			
			
	      GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_ENA_PIN);
	      GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_IN1_PIN);
	      GPIO_ResetBits   (MOTOR_H_PORT, MOTOR_H_IN2_PIN);
			  delay(500000);
		    GPIO_SetBits     (MOTOR_H_PORT, MOTOR_H_ENR_PIN);
	      GPIO_ResetBits     (MOTOR_H_PORT, MOTOR_H_IN3_PIN);
	      GPIO_SetBits   (MOTOR_H_PORT, MOTOR_H_IN4_PIN);
			  break;	
		 
		 case '0': 
			  //printf( "停！\n" );
	      GPIO_ResetBits    (MOTOR_Q_PORT, MOTOR_Q_ENA_PIN);

		 
		    GPIO_ResetBits    (MOTOR_Q_PORT, MOTOR_Q_ENR_PIN);

		 
		 	  GPIO_ResetBits    (MOTOR_H_PORT, MOTOR_H_ENA_PIN);

			
		    GPIO_ResetBits    (MOTOR_H_PORT, MOTOR_H_ENR_PIN);


			  break;
		 
			default:
		    break;
	 }
	}
}
/*********************************************END OF FILE**********************/












