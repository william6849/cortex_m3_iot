/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "var.h"
/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}


void USART1_IRQHandler(void)
{	
		  
   	char *data2 = My_Usart_ReadLine();
			
	
	if(!strcmp(data2, "error")||!strcmp(data2, "FAIL")||!strcmp(data2, "ERROR"))error_flag=1;
  //  if(!strcmp(data2, "busy p..."))Delay(5000);
	if(!strcmp(data2, "Unlink"))unlink=1;
	if(!strcmp(data2, "SEND OK"))send_flag=0;
	if(!strcmp(data2, "OK")||!strcmp(data2, "no change")||!strcmp(data2, "ALREAY CONNECT")||!strcmp(data2, "Linked")){process_flag=0;error_flag=0; }
//	if(!strcmp(data2, "enter error"));	  				  
}

 
void  DMA1_Channel1_IRQHandler(void)
{ 
   if(DMA_GetITStatus(DMA1_IT_TC1)!=RESET){
   

	//USART_printf(USART1, "%d\r\n",adc_data);
	if(data_count<400){	
		itoa(adc_data,int_bu,10);
		point=mystrcat(data_buf, int_bu);
		point=mystrcat(data_buf,"x");
		data_count++;
	}else if(data_count>=400&&data_count<800){	
		itoa(adc_data,int_bu,10);
		point=mystrcat(data_buf2, int_bu);
		point=mystrcat(data_buf2,"x");
		data_count++;
	}else if(data_count>=800&&data_count<=1000){	
		itoa(adc_data,int_bu,10);
		point=mystrcat(data_buf3, int_bu);									
		point=mystrcat(data_buf3,"x");
		data_count++;
		
	} if(data_count>1000){DMA_ITConfig(DMA1_Channel1,DMA_IT_TC, DISABLE);adc_flag=1;}

        DMA_ClearITPendingBit(DMA1_IT_TC1);
  }
	
} 
/******************************************************************************/		 
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
