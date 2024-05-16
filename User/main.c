#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

int key1 = 0;
int key2 = 0;
int main()
{
	LED_GPIO_CONFIG();
	LED_R_ON;
	LED_G_ON;
	
	KEY_GPIO_CONFIG();
	// while (1)
	// {
	// 	GPIO_SetBits(GPIOB,LED_R_PIN);
	// 	delay(0xFFFFF);
	// 	GPIO_ResetBits(GPIOB,LED_R_PIN);
	// 	delay(0xFFFFF);

	// 	GPIO_SetBits(GPIOB,LED_G_PIN);
	// 	delay(0xFFFFF);
	// 	GPIO_ResetBits(GPIOB,LED_G_PIN);
	// 	delay(0xFFFFF);

	// 	GPIO_SetBits(GPIOB,LED_B_PIN);
	// 	delay(0xFFFFF);
	// 	GPIO_ResetBits(GPIOB,LED_B_PIN);
	// 	delay(0xFFFFF);
	// }
	while (1)
	{	
		// key1 =GPIO_ReadInputDataBit(KEY1_GPIO,KEY1_PIN);
		// key2 =GPIO_ReadInputDataBit(KEY2_GPIO,KEY2_PIN);
		// if(key1 == 1)
		// {
		// 	delay(0xFFF);
		// }
		// if(key2 == 1)
		// {
		// 	delay(0xFFF);
		// }
		if(Key_scan(KEY1_GPIO,KEY1_PIN) == KEY_ON)
		{
			GPIOB->ODR ^= LED_R_PIN;
			// LED1_REVERSE;
		}
		if(Key_scan(KEY2_GPIO,KEY2_PIN) == KEY_ON)
		{
			GPIOB->ODR ^= LED_G_PIN;
		}
	}
	
}