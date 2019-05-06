#include "stm32f10x.h"
#include "usart.h"
#include "led.h"
#include "esp_connect.h"
#include "var.h"
#include "adc.h"

void Delay(short int nCount);
void Delay2(short int nCount);
char *itoa(int value, char *string, int radix);


int main(){
   	int i;

	char* dat;
	SystemInit();
	USART1_Config();
	LED_GPIO_Config();
//	LED2(ON);
	dat=data_buf;
 	if(esp_init()){LED1(ON);return 1;}


	memset(data_buf,0,2048);
	memset(data_buf2,0,2048);
	memset(data_buf3,0,2048);
    	ADC1_Init();


	//if(esp_send("1")){LED1(ON);return 1;}
	//Delay(5000);
 /*
	while(1){
   


if(data_count>400){
//data_count=0;
while(*dat!='\0'){
 dat++;
}
*--dat='\0';

USART_printf(USART1, "%s\r\n\r\n\r\n",data_buf);
//DMA_ITConfig(DMA1_Channel1,DMA_IT_TC, ENABLE);
USART_printf(USART1, "\r\n\r\n\r\n");
  return 0;
}
 */
//	esp_send("k");}	

	
/*
while(1){
	for(data_count=0;data_count<400;data_count++){
	itoa(adc_data,int_bu,10);
	dat=mystrcat(dat, int_bu);
	dat=mystrcat(dat,"x");Delay2(5);}


	dat=data_buf2;
	for(data_count=0;data_count<400;data_count++){
	itoa(adc_data,int_bu,10);
	dat=mystrcat(dat, int_bu);
	dat=mystrcat(dat,"x");}
	
	dat=data_buf3;
	for(data_count=0;data_count<400;data_count++){
	itoa(adc_data,int_bu,10);
	dat=mystrcat(dat, int_bu);
	dat=mystrcat(dat,"x");}

	*/

	while(1){
											  
	if(data_count>1000&&adc_flag==1){
		dat= data_buf3;
		while(*dat!='\0')dat++;
		*--dat='\0';

		LED2(ON);
		esp_send();
	 
		data_count=0;
		DMA_ITConfig(DMA1_Channel1,DMA_IT_TC, ENABLE);
		esp_tcp_connect();
		adc_flag=0;
		LED2(OFF);
	}
	}
	
	

	
	
	


}
	
		 







void Delay(short int nCount)
{
__IO u32 Count = 0x1C20*nCount;
  for(; Count != 0; Count--);
} 
void Delay2(short int nCount)
{
__IO u32 Count = 0x48*nCount;
  for(; Count != 0; Count--);
}

char *itoa(int value, char *string, int radix)
{
    int     i, d;
    int     flag = 0;
    char    *ptr = string;

    /* This implementation only works for decimal numbers. */
    if (radix != 10)
    {
        *ptr = 0;
        return string;
    }

    if (!value)
    {
        *ptr++ = 0x30;
        *ptr = 0;
        return string;
    }

    /* if this is a negative value insert the minus sign. */
    if (value < 0)
    {
        *ptr++ = '-';

        /* Make the value positive. */
        value *= -1;
    }

    for (i = 10000; i > 0; i /= 10)
    {
        d = value / i;

        if (d || flag)
        {
            *ptr++ = (char)(d + 0x30);
            value -= (d * i);
            flag = 1;
        }
    }

    /* Null terminate the string. */
    *ptr = 0;

    return string;

}