#include "stm32f103xb.h"
#include "rcc_init.h"
#include "usart.h"

void RCCinit(void) {

    __IO uint32_t StartUpCounter = 0, HSEStatus = 0, HSEStartUp_TimeOut = 0x500, RESET = 1;

    // enable HSE   
    RCC->CR |= ((uint32_t)RCC_CR_HSEON);

    // wait for HSE ready flag or timeout
    do {
        HSEStatus = RCC->CR & RCC_CR_HSERDY;
        StartUpCounter++;  
    } while((HSEStatus == 0) && (StartUpCounter != HSEStartUp_TimeOut));

    if ((RCC->CR & RCC_CR_HSERDY) != RESET) {
        HSEStatus = (uint32_t)0x01;
    } else {
        HSEStatus = (uint32_t)0x00;
    }  

    // If HSE started ok
    if (HSEStatus == (uint32_t)0x01) {
        // Flash prefetch buffer enable
        FLASH->ACR |= FLASH_ACR_PRFTBE;

        // Flash latency
        FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
        FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    

        RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1; // AHB prescaler
        RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1; // APB2 prescaler
        RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2; // APB1 prescaler

        // set PLL source HSE
        // 72MHz
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
        RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL9);

        // Enable PLL
        RCC->CR |= RCC_CR_PLLON;

        // Wait for PLL ready flag
        while((RCC->CR & RCC_CR_PLLRDY) == 0) {
        }

        // Choose PLL as a system clock
        RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
        RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

        // Wait for PLL is system clock
        while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08) {
        }

        USART1_Init(72); 
    } else {
        // rcc init failed. Wait for WDG reset.
        USART1_Send_String("\n\rExternal osc init fail, working from internal 8M HSI RC ");
    }
}

/*
// Hardcode Exaples:
#include "stm32f103.h"

void RCC_HSE_ON(void)
{  
    RCC_CR = 0x83; //¸´Î» RCC_CR 
    RCC_CR |= 0x00010000;  //Æô¶¯HSE
    while(((RCC_CR & 0x00020000) >> 16)==1);  //µÈ´ýÍâ²¿¾§ÕñHSEÎÈ¶¨
    FLASH_ACR = 0x2; //2¸ö·ÃÎÊµÈ´ý×´Ì¬
    FLASH_ACR |= 0x10; //Ô¤È¡»º³åÇøÊ¹ÄÜ
    RCC_CFGR = 0x0; //RESET RCC_CFGR Register
    RCC_CFGR |= 0x001D0000; //HSE²»·ÖÆµ×÷ÎªPLLÊäÈë£¬PLL 9±¶Æµ 
    RCC_CR |=  0x01000000; //Æô¶¯PLL
    while(((RCC_CR & 0x01000000) >> 25)==1); //µÈ´ýPLL±¶ÆµÊ±ÖÓÎÈ¶¨
    RCC_CFGR |= 0x00000400; //APB1 2·ÖÆµ
    RCC_CFGR |= 0x2; //PLLÊ±ÖÓ×÷ÎªÏµÍ³Ê±ÖÓ
    while(((RCC_CFGR & 0x00000008) >> 4)==1); //µÈ´ýPLL±¶ÆµÊ±ÖÓÎÈ¶¨
}
*/
