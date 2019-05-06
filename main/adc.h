#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"
#include "var.h"
void ADC1_Init(void);
static void ADC1_Mode_Config(void);
static void ADC1_GPIO_Config(void);
void TIM2_Configuration(void);
#endif
