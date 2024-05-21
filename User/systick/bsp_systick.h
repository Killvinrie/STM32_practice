#ifndef __BSP_SYSTICK__H
#define __BSP_SYSTICK__H

#include "stm32f10x.h"

void Systick_init(void);
void Delay_Decrement(void);
void DelayINT_us(uint32_t us);
void Delaytick_us(uint32_t us);




#endif