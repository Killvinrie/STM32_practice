#include"bsp_key.h"

void KEY_GPIO_CONFIG(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = KEY1_PIN;
    GPIO_Init(KEY1_GPIO,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = KEY2_PIN;
    GPIO_Init(KEY2_GPIO,&GPIO_InitStruct);
    
}

int Key_scan(GPIO_TypeDef* GPIOx ,uint16_t key_pin)
{
    if(GPIO_ReadInputDataBit(GPIOx,key_pin) == KEY_ON)
    {
        while(GPIO_ReadInputDataBit(GPIOx,key_pin) == KEY_ON);
        return KEY_ON;
    }
    else 
        return KEY_OFF;
}