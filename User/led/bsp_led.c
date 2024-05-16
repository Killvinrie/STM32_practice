#include "bsp_led.h"



void LED_GPIO_CONFIG(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	GPIO_InitStruct.GPIO_Pin = LED_R;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = LED_G;	
	GPIO_Init(GPIOB,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = LED_B;
	GPIO_Init(GPIOB,&GPIO_InitStruct);

	GPIO_SetBits(GPIOB,LED_R_PIN);
	GPIO_SetBits(GPIOB,LED_G_PIN);
	GPIO_SetBits(GPIOB,LED_B_PIN);
}

void delay(int count)
{
	for(;count>0;count--);
}


