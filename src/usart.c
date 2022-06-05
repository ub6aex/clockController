#include "stm32f103xb.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>

void USART1_Init(uint16_t mhz) {
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // UART1 clock enable
    USART1->CR1 = 0; // Reset USART1 control register 1
    USART1->CR1 |= (USART_CR1_RE | USART_CR1_TE); // Receiver enable, Transmitter enable
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    USART1->BRR |=  mhz*1000000/115200; // baud rate register

    //PINs init
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // port A enable
    
    GPIOA->CRH |= GPIO_CRH_MODE9; // PA9 Output mode, max speed 50 MHz
    GPIOA->CRH &= ~GPIO_CRH_CNF9_0; // Alternate function output Push-pull
    GPIOA->CRH |= GPIO_CRH_CNF9_1;

    GPIOA->CRH &= ~GPIO_CRH_MODE10; // PA10 Input mode
    GPIOA->CRH |= GPIO_CRH_CNF10_0; // Floating input
    GPIOA->CRH &= ~GPIO_CRH_CNF10_1;

    USART1->CR1 |= USART_CR1_UE; // Enable UART1

}

void USART1_Send_Byte(unsigned char ucSend_Data) {
    USART1->DR = ucSend_Data & 0x01FF;
    while(((USART1->SR & 0x80) >> 7) != 1);
}

unsigned char USART1_Receive_Byte(void) {
    unsigned char ucTemp = 0;

    while(((USART1->SR & 0x20) >> 5) != 1);
    //while(USART1_SR == 0xC0);

    ucTemp = USART1->DR;
    //USART1_Send_Byte(ucTemp);

    return ucTemp;
}

void USART1_Send_String(char *pucString) {
   while(*pucString!='\0') {
        USART1_Send_Byte(*pucString);
        pucString++;
    }
}

void USART1_Send_uInt(uint32_t number) {
    char str[8] = "";
    sprintf(str, "%lu", number);
    USART1_Send_String(str);
}
