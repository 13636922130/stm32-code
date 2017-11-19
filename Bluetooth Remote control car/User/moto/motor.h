#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f10x.h"

#define MOTOR_Q_PORT      GPIOB
#define MOTOR_Q_ENA_PIN   GPIO_Pin_8
#define MOTOR_Q_IN1_PIN   GPIO_Pin_9
#define MOTOR_Q_IN2_PIN   GPIO_Pin_10
#define MOTOR_Q_ENR_PIN   GPIO_Pin_12
#define MOTOR_Q_IN3_PIN   GPIO_Pin_13
#define MOTOR_Q_IN4_PIN   GPIO_Pin_14

#define MOTOR_H_PORT      GPIOA
#define MOTOR_H_ENA_PIN   GPIO_Pin_0
#define MOTOR_H_IN1_PIN   GPIO_Pin_1
#define MOTOR_H_IN2_PIN   GPIO_Pin_2
#define MOTOR_H_ENR_PIN   GPIO_Pin_5
#define MOTOR_H_IN3_PIN   GPIO_Pin_4
#define MOTOR_H_IN4_PIN   GPIO_Pin_7
void Motor_GPIO_Config(void);
#endif



