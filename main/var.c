int tcp_connection_flag = 0;
int ap_connection_flag = 0;
int process_flag = 1;
char usart_char='\0';
char buff[2048]="";
int TX_data_buff_flag;
int error_flag=0;
int send_flag=0;
char data_buf[2048];
char data_buf2[2048];
char data_buf3[2048];
int data_count=0;
char int_bu[16];
int buf_flag=0;
int unlink=0;
char *point;
int adc_flag=0;

char* mystrcat( char* dest, char* src )
{
     while (*dest) dest++;
     while (*dest++ = *src++);
     return --dest;
}

