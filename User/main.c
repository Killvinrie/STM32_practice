#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_clk.h"
#include "bsp_exti.h"
#include "bsp_usart.h"

int key1 = 0;
int key2 = 0;

int main()
{
	LED_GPIO_CONFIG();
	//LED_R_ON;
	LED_G_ON;

	//RCC_CLK_config(RCC_PLLMul_16);   config teh pll to output 128Mhz clock frequency.

	// KEY_GPIO_CONFIG();				config the KEY1&KEY2   (GPIOA GPIOC ) to implement key check and led reverse.
	//KEY_EXTI_CONFIG();
	Usart1_CONFIG();
	USART_SendData(USART1,100);
	while(1)
	{
		
	}
	// while (1)
	// {
	// 	// GPIO_SetBits(GPIOB,LED_R_PIN);
	// 	// delay(0xFFFFFF);
	// 	// GPIO_ResetBits(GPIOB,LED_R_PIN);
	// 	// delay(0xFFFFFF);

	// 	// GPIO_SetBits(GPIOB,LED_G_PIN);
	// 	// delay(0xFFFFFF);
	// 	// GPIO_ResetBits(GPIOB,LED_G_PIN);
	// 	// delay(0xFFFFFF);

	// 	// GPIO_SetBits(GPIOB,LED_B_PIN);
	// 	// delay(0xFFFFFF);
	// 	// GPIO_ResetBits(GPIOB,LED_B_PIN);
	// 	// delay(0xFFFFFF);
	// }
	// while (1)
	// {	
	// 	//key1 =GPIO_ReadInputDataBit(KEY1_GPIO,KEY1_PIN);
	// 	// key2 =GPIO_ReadInputDataBit(KEY2_GPIO,KEY2_PIN);
	// 	// if(key1 == 1)
	// 	// {
	// 	// 	delay(0xFFF);
	// 	// }
	// 	// if(key2 == 1)
	// 	// {
	// 	// 	delay(0xFFF);
	// 	// }
	// 	// if(Key_scan(KEY1_GPIO,KEY1_PIN) == KEY_ON)
	// 	// {
	// 	// 	GPIOB->ODR ^= LED_R_PIN;
	// 	// 	// LED1_REVERSE;
	// 	// }
	// 	// if(Key_scan(KEY2_GPIO,KEY2_PIN) == KEY_ON)
	// 	// {
	// 	// 	GPIOB->ODR ^= LED_G_PIN;
	// 	// }
	// }
	
}