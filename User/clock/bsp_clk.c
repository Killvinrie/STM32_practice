#include "bsp_clk.h"

void RCC_CLK_config(uint32_t pllmul)
{
    RCC_DeInit();

    RCC_HSEConfig(RCC_HSE_ON);
    if(RCC_WaitForHSEStartUp())
    {
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
        FLASH_SetLatency(FLASH_Latency_2);

        RCC_HCLKConfig(RCC_SYSCLK_Div1);
        RCC_PCLK1Config(RCC_HCLK_Div2);
        RCC_PCLK2Config(RCC_HCLK_Div1);

        RCC_PLLConfig(RCC_PLLSource_HSE_Div1,pllmul);
        RCC_PLLCmd(ENABLE);
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
        while(RCC_GetSYSCLKSource() != 0x08);  // wait untill the cfgr->sw  switch to pll
    }
    else
    {
        //if  HSE  failed to startup,  do something here.
    }
    

}