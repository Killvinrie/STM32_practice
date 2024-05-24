#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "stm32f10x.h"

#define USART1_GPIO     GPIOA
#define USART1_CLK  RCC_APB2Periph_USART1
#define USART1_GPIO_CLK RCC_APB2Periph_GPIOA

#define USART1_TX   GPIO_Pin_9
#define USART1_RX   GPIO_Pin_10

#define USART1_BAUDRATE  115200





void Usart1_CONFIG(void);
void USART1_SEND_BYTE(USART_TypeDef* USARTx, uint16_t Data);



#endif