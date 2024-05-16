#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"
#include "bsp_led.h"

#define KEY1_GPIO   GPIOA
#define KEY2_GPIO   GPIOC
#define KEY1_PIN    GPIO_Pin_0
#define KEY2_PIN    GPIO_Pin_13

#define KEY_ON  1
#define KEY_OFF 0

#define Led_reverse(GPIOx,pin)  {GPIOx->ODR ^= pin;}
#define LED1_REVERSE    Led_reverse(GPIOB,LED_R_PIN)
#define LED2_REVERSE    Led_reverse(GPIOB,LED_G_PIN)

void KEY_GPIO_CONFIG(void);
int Key_scan(GPIO_TypeDef* GPIOx ,uint16_t key_pin);

#endif