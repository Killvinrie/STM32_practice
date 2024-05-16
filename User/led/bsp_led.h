#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"



#define LED_GPIO    GPIOB
#define LED_R_PIN   GPIO_Pin_5
#define LED_G_PIN   GPIO_Pin_0
#define LED_B_PIN   GPIO_Pin_1

#define LED_R_ON    LED_GPIO->BRR = GPIO_Pin_5
#define LED_G_ON    LED_GPIO->BRR = GPIO_Pin_0
#define LED_B_ON    LED_GPIO->BRR = GPIO_Pin_1

enum LED_PIN
{
    LED_R = GPIO_Pin_5,
    LED_G = GPIO_Pin_0,
    LED_B = GPIO_Pin_1
};

void LED_GPIO_CONFIG(void);
void delay(int count);

#endif
