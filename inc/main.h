#ifndef __MAIN_H
#define __MAIN_H


#include "stm32f4_discovery.h"
#include "conf_clock.h"
#include "stm32f4xx_conf.h"

#define UART4_TX GPIO_Pin_0
#define UART4_RX GPIO_Pin_1
#define UART_PORT GPIOA
#define UART_PIN_TX GPIO_PinSource0
#define UART_PIN_RX GPIO_PinSource1
#define UART_PIN_AF GPIO_AF_UART4
#define UART   UART4

#define LED1 GPIO_Pin_12
#define LED2 GPIO_Pin_13
#define LED3 GPIO_Pin_14
#define LED4 GPIO_Pin_15
#define GPIO_LED GPIOD


#endif