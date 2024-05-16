#include "stm32f10x.h"
#include "bsp_led.h"

int main()
{
	LED_GPIO_CONFIG();


	while (1)
	{
		GPIO_SetBits(GPIOB,LED_R_PIN);
		delay(0xFFFFF);
		GPIO_ResetBits(GPIOB,LED_R_PIN);
		delay(0xFFFFF);

		GPIO_SetBits(GPIOB,LED_G_PIN);
		delay(0xFFFFF);
		GPIO_ResetBits(GPIOB,LED_G_PIN);
		delay(0xFFFFF);

		GPIO_SetBits(GPIOB,LED_B_PIN);
		delay(0xFFFFF);
		GPIO_ResetBits(GPIOB,LED_B_PIN);
		delay(0xFFFFF);
	}
}