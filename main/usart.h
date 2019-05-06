#ifndef __USART_H
#define	__USART_H

#include "stm32f10x.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "var.h"

void USART1_Config(void);
void USART_printf(USART_TypeDef* USARTx, uint8_t *Data,...);
char * My_Usart_ReadLine(void);

#endif	 
