#include "bsp_systick.h"

static volatile uint32_t delay_count;


void Systick_init()
{
    while(SysTick_Config(SYSCLK_FREQ_72MHz/1000000));
}

void Delay_Decrement(void)
{
    if(delay_count>0)
    {
        delay_count--;
    }
}

void DelayINT_us(uint32_t us)
{
    delay_count = us;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    while(delay_count>0);
}

void Delaytick_us(uint32_t us)
{   
    int i;

    SysTick_Config(SYSCLK_FREQ_72MHz/1000000);
    
    for(i=0;i<us;i++)
    {
        while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    }
    //Disable the systick after the delay
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}