#include "esp_connect.h"

int timeout;

int esp_init(void){
	
	if(esp_reset())return 1;
	if(esp_cwmode())return 1;
	if(esp_ap_connect())return 1;
	if(esp_tcp_connect())return 1;

	return 0;
}


int esp_cwmode(void){
  
	do{
	USART_printf(USART1, " AT+CWMODE=1\r\n");
	if(esp_wait(15))return 1;
	}while(error_flag==1);
	return 0;
}

int esp_ap_connect(void){

	do{
	USART_printf(USART1, "AT+CWJAP=\"C8763\",\"xxxxxxxx\"\r\n");
	if(esp_wait(20)==1)return 1;
	//USART_printf(USART1, "AT+CWJAP=\"HTC Portable Hotspot A42F\",\"12345678\"\r\n");
	//if(esp_wait(20)==1)return 1;
	}while(error_flag==1);
	ap_connection_flag = 1;
	return 0;
}

int esp_tcp_connect(void){
	do{
	USART_printf(USART1, "AT+CIPSTART=\"TCP\",\"iidx.2fh.co\",80\r\n");
 
	if(esp_wait(15)==1)return 1;
	}while(error_flag==1);
	tcp_connection_flag = 1;
	return 0;
}

int esp_reset(void){
	do{
	USART_printf(USART1, " AT+RST\r\n");
	if(esp_wait(15))return 1;
	}while(error_flag==1);
 	Delay(7000);
	return 0;
}


int esp_send(){
	char* datp;

	data_count=0;
	USART_printf(USART1, "AT+CIPSEND=306\r\n");
	error_flag=0;
	while(usart_char!='>'){
		if(error_flag==1)break;
	}
	USART_printf(USART1, "POST /upload.php HTTP/1.1\r\nAccept-Encoding: \r\nCache-Control: no-cache\r\nConnection: close\r\nHost: iidx.2fh.co\r\nUser-Agent: Mozilla/5.0 (Macintosh; U; Intel Mac OS X; de-de) AppleWebKit/523.10.3 (KHTML, like Gecko) Version/3.0.4 Safari/523.10\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: ");
	send_flag=1;
	while(send_flag==1);
	if((strlen(data_buf))>=1000){
	USART_printf(USART1, "AT+CIPSEND=%d\r\n",18);}else{USART_printf(USART1, "AT+CIPSEND=%d\r\n",16);}
	error_flag=0;
	while(usart_char!='>'){
		if(error_flag==1)break;
	}
   
	USART_printf(USART1, "%d\r\n\r\nid=1&data=",strlen(data_buf)+strlen(data_buf2)+strlen(data_buf3)+10);
	send_flag=1;
	while(send_flag==1);
	
	USART_printf(USART1, "AT+CIPSEND=%d\r\n",strlen(data_buf));
	error_flag=0;
	while(usart_char!='>'){
		if(error_flag==1)break;
	}
	USART_printf(USART1, data_buf);

	//send_flag=1;
	
	send_flag=1;
	while(send_flag==1);
	Delay(1500);
	data_buf[0]='\0';
	
	USART_printf(USART1, "AT+CIPSEND=%d\r\n",strlen(data_buf2));
	error_flag=0;
	while(usart_char!='>'){
		if(error_flag==1)break;
	}
	USART_printf(USART1, data_buf2);

	send_flag=1;
	while(send_flag==1);
	Delay(1500);
	//while(send_flag==1);
	data_buf2[0]='\0';
	USART_printf(USART1, "AT+CIPSEND=%d\r\n",strlen(data_buf3));
	error_flag=0;
	while(usart_char!='>'){
		if(error_flag==1)break;
	}
	USART_printf(USART1, data_buf3);
	unlink=0;
	while(unlink==0);
	data_buf3[0]='\0';


	



	
	
//	if((esp_wait(5))==1)return 1;
//	USART_printf(USART1, "AT+CIPCLOSE\r\n");
//	esp_wait(5);
	return 0;
}

	
int esp_wait(int time){
	process_flag=1;
	timeout=0x6DDD00*time;
	error_flag=0;
	while((process_flag)!=0){
		if(timeout==0){LED1(ON);return 1;}
		timeout--;
		if(error_flag==1)return 2;
	}
	return 0;
}



/*
void esp_check(void){
	 USART_printf(USART1, "AT+CWJAP?\r\n");
	 if((esp_wait(5))==2)esp_ap_connect();
	 //USART_printf(USART1, "AT+CIPSTATUS\r\n");
	 //if((esp_wait(5))==2)
	 //esp_tcp_connect();
	 recheck=0;

}*/
