#include"adc.h"


__IO unsigned short int adc_data;

void ADC1_Init(void)
{
	TIM2_Configuration();
	ADC1_GPIO_Config();
	ADC1_Mode_Config();
}



static void ADC1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  	GPIO_Init(GPIOA, &GPIO_InitStructure);
}


static void ADC1_Mode_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	/* DMA channel1 configuration */
  DMA_DeInit(DMA1_Channel1);
  DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)0x4001244C;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&adc_data;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_BufferSize = 1;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel1, &DMA_InitStructure);
  DMA_ITConfig(DMA1_Channel1,DMA_IT_TC, ENABLE);
  /* Enable DMA channel1 */
  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  NVIC_InitStructure.NVIC_IRQChannel =DMA1_Channel1_IRQn;  
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
    
  /* ADC1 configuration */
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T2_CC2;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = 1;
  ADC_Init(ADC1, &ADC_InitStructure);

  /* ADC3 regular channel11 configuration */ 
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_55Cycles5);
   ADC_ExternalTrigConvCmd(ADC1, ENABLE); 
  /* Enable ADC3 DMA */
  ADC_DMACmd(ADC1, ENABLE);
  
  /* Enable ADC3 */
  ADC_Cmd(ADC1, ENABLE);

  /* Enable ADC3 reset calibaration register */   
  ADC_ResetCalibration(ADC1);
  /* Check the end of ADC3 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADC1));

  /* Start ADC3 calibaration */
  ADC_StartCalibration(ADC1);
  /* Check the end of ADC3 calibration */
  while(ADC_GetCalibrationStatus(ADC1));
   TIM_Cmd(TIM2, ENABLE);
   DMA_Cmd(DMA1_Channel1, ENABLE);	  
  /* Start ADC3 Software Conversion */ 
  //ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}


void TIM2_Configuration(void)
{ 
 TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; 
 TIM_OCInitTypeDef TIM_OCInitStructure; 
 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE); 
 TIM_TimeBaseStructure.TIM_Period = 2000;//?置2ms一次TIM2比?的周期
 TIM_TimeBaseStructure.TIM_Prescaler = 71;//系?主?72M，?里分?71，相?于1000K的定?器2?? 
 TIM_TimeBaseStructure.TIM_ClockDivision = 0x0; 
 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
 TIM_TimeBaseInit(TIM2, & TIM_TimeBaseStructure);
    
 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//下面???明 
 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//TIM_OutputState_Disable; 
 TIM_OCInitStructure.TIM_Pulse = 1000; 
 TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;//如果是PWM1要?Low，PWM2??High 
 TIM_OC2Init(TIM2, & TIM_OCInitStructure);   
 TIM_InternalClockConfig(TIM2);
// TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable); 
// TIM_UpdateDisableConfig(TIM2, DISABLE);
}