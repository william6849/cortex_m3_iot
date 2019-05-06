#ifndef __VAR_H
#define	__VAR_H

char* mystrcat( char* dest, char* src );


extern char usart_char;
extern int tcp_connection_flag;
extern int ap_connection_flag;
extern int process_flag;
extern char buff[];
extern int TX_data_buff_flag; //??
extern int error_flag;
extern int send_flag;
extern char data_buf[];
extern char data_buf2[];
extern char data_buf3[];
extern int data_count;
extern __IO unsigned short int adc_data;
extern char int_bu[];
extern int buf_flag;
extern int unlink;
extern char *point;
extern int adc_flag;
#endif	 
