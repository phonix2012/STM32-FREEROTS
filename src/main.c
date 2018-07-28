/*
  ******************************************************************************
  * @file    IO_Toggle/main.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main program body
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
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4_discovery.h"
#include "conf_clock.h"
#include "stm32f4xx_conf.h"
#include "main.h"
#include <queue.h>

 // again, added because ST didn't put it here ?
/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */
static QueueHandle_t uart_txq;    // TX queue for UART

/** @addtogroup IO_Toggle
  * @{
  */


// static QueueHandle_t uart_txq;    // TX queue for UART

/* Private typedef -----------------------------------------------------------*/

extern void vApplicationStackOverflowHook(xTaskHandle *pxTask,signed portCHAR *pcTaskName);

void
vApplicationStackOverflowHook(xTaskHandle *pxTask,signed portCHAR *pcTaskName)
{
  (void)pxTask;
  (void)pcTaskName;
  for(;;);
}

//usart task
static void uart_task()
{
  char ch;

  for (;;) {
    // Receive char to be TX
    if ( xQueueReceive(uart_txq,&ch,500) == pdPASS )
    {
      GPIO_ToggleBits(GPIO_LED,LED2);
      while (!USART_GetFlagStatus(UART,USART_FLAG_TXE))
      // while ( !usart_get_flag(USART1,USART_SR_TXE) )
        taskYIELD();  // Yield until ready
      USART_SendData(UART,ch);
      // usart_send(USART1,ch);
    }
    // Toggle LED to show signs of life
    GPIO_ToggleBits(GPIO_LED,LED1);

  }
}


// static inline void
// static void uart_putc(char ch)
// {
//   while (!USART_GetFlagStatus(UART,USART_FLAG_TXE));
//     USART_SendData(UART,ch);
// }


// task1(void *args) {
// static void task1()
// {
//   int c = 66;
//   int i;
//   for (;;)
//   {
//     GPIO_ToggleBits(GPIO_LED,LED1);
//     GPIO_ToggleBits(GPIO_LED,LED2);
//     GPIO_ToggleBits(GPIO_LED,LED3);
//     GPIO_ToggleBits(GPIO_LED,LED4);

//       uart_putc(c);

//       uart_putc('\r');
//       uart_putc('\n');
//     vTaskDelay(pdMS_TO_TICKS(500));

//     // for (i = 0; i < 10000000; i++)
//     //   __asm__("nop");
//     // }

//   }
// }
static void uart_puts(const char *s)
{

  for ( ; *s; ++s ) {
    // blocks when queue is full
    xQueueSend(uart_txq,s,portMAX_DELAY);
  }
}

static void demo_task() {

  for (;;) {
    uart_puts("Now this is a message..\n\r");
    uart_puts("  sent via FreeRTOS queues.\n\n\r");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}



void init_LED()
{
  GPIO_InitTypeDef  GPIO_InitStructure;
   /* GPIOD Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /* Configure PD12, PD13, PD14 and PD15 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = LED1 | LED2 | LED3 | LED4 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIO_LED, &GPIO_InitStructure);

}




 void uart_setup()
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  /* Enable UART clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);

  /* Connect UART pins to AF2 */
  GPIO_PinAFConfig(UART_PORT, UART_PIN_TX, UART_PIN_AF);
  GPIO_PinAFConfig(UART_PORT, UART_PIN_RX, UART_PIN_AF);

  /* GPIO Configuration for UART Tx */
  GPIO_InitStructure.GPIO_Pin   = UART_PIN_TX;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(UART_PORT, &GPIO_InitStructure);

  /* GPIO Configuration for USART Rx */
  GPIO_InitStructure.GPIO_Pin   = UART_PIN_RX;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_Init(UART_PORT, &GPIO_InitStructure);

  /* USARTx configured as follow:
    - BaudRate = 115200 baud
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(UART, &USART_InitStructure);
  /* Enable USART */
  USART_Cmd(UART, ENABLE);
  uart_txq =  xQueueCreate(256,sizeof(char));
}

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured,
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
        system_stm32f4xx.c file
     */
  int status;

  status = rcc_clock_setup_hse_3v3(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);

  init_LED();
  uart_setup();

  xTaskCreate(uart_task,"UART",100,NULL,configMAX_PRIORITIES-1,NULL);
  xTaskCreate(demo_task,"DEMO",100,NULL,configMAX_PRIORITIES-2,NULL);

  // xTaskCreate(task1,"task1",100,NULL,configMAX_PRIORITIES-1,NULL);
  vTaskStartScheduler();

 while(1)
 {
 }
  return 0;

}

/**
  * @brief  Delay Function.
  * @param  nCount:specifies the Delay time length.
  * @retval None
  */
void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE***/