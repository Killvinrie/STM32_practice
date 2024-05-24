#include "bsp_usart.h"

static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
 
  NVIC_Init(&NVIC_InitStructure);
}


void Usart1_CONFIG(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;

    RCC_APB2PeriphClockCmd(USART1_CLK,ENABLE);
    RCC_APB2PeriphClockCmd(USART1_GPIO_CLK,ENABLE);

    GPIO_InitStruct.GPIO_Pin = USART1_TX;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(USART1_GPIO,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin = USART1_RX;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(USART1_GPIO, &GPIO_InitStruct);

    USART_InitStruct.USART_BaudRate = USART1_BAUDRATE;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART1, &USART_InitStruct);

    NVIC_Configuration();
    
    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);

    USART_Cmd(USART1, ENABLE);
}

void USART1_SEND_BYTE(USART_TypeDef* USARTx, uint16_t Data)
{
    USART_SendData(USARTx, Data);
    
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET);
}