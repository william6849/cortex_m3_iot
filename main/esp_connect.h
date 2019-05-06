#ifndef __ESP_H
#define	__ESP_H

#include "usart.h"
#include "stm32f10x.h"
#include <string.h>
#include <stdlib.h>
#include "led.h"
#include "var.h"

int esp_init(void);
int esp_reset(void);
int esp_cwmode(void);
int esp_ap_connect(void);
int esp_tcp_connect(void);
int esp_wait(int time);

int esp_send();

//void esp_check(void);
#endif 
