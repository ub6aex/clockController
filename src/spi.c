#include "stm32f103xb.h"
#include "spi.h"

#define CS_LOW   GPIOB->BSRR = GPIO_BSRR_BR12
#define CS_HIGH  GPIOB->BSRR = GPIO_BSRR_BS12

void SPI2init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // port B clock enable
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; // Alternate Function I/O clock enable
    // RCC->APB1RSTR |= RCC_APB1RSTR_SPI2RST; //SPI reset

    // NSS
    // GPIOB->CRH |= GPIO_CRH_MODE12; // output mode, max speed 50 Mhz
    // GPIOB->CRH &= ~GPIO_CRH_CNF12; // GPIO output push-pull
    // GPIOB->CRH &= ~GPIO_CRH_CNF12_1; // 

    // SCK
    GPIOB->CRH |= GPIO_CRH_MODE13; // output mode, max speed 50 Mhz
    GPIOB->CRH &= ~GPIO_CRH_CNF13_0; // AF output push-pull
    GPIOB->CRH |= GPIO_CRH_CNF13_1; // AF output push-pull

    // MISO
    GPIOB->CRH &= ~GPIO_CRH_MODE14; // input mode
    GPIOB->CRH |= GPIO_CRH_CNF14_0; // floating input
    GPIOB->CRH &= ~GPIO_CRH_CNF14_1; // floating input

    // MOSI
    GPIOB->CRH |= GPIO_CRH_MODE15; // output mode, max speed 50 Mhz
    GPIOB->CRH &= ~GPIO_CRH_CNF15_0; // AF output push-pull
    GPIOB->CRH |= GPIO_CRH_CNF15_1; // AF output push-pull

    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN; // spi clock enable

    // speed 101: fPCLK/64
    SPI2->CR1 |= SPI_CR1_BR_0;
    SPI2->CR1 &= ~SPI_CR1_BR_1;
    SPI2->CR1 |= SPI_CR1_BR_2;

    SPI2->CR1 &= ~SPI_CR1_CPOL;
    SPI2->CR1 &= ~SPI_CR1_CPHA;
    SPI2->CR1 |= SPI_CR1_CPHA;
    // SPI2->CR1 |= SPI_CR1_DFF; // 16 bit
    SPI2->CR1 &= ~SPI_CR1_LSBFIRST;
    SPI2->CR1 |= SPI_CR1_SSM;
    SPI2->CR1 |= SPI_CR1_SSI;

    SPI2->CR1 |= SPI_CR1_MSTR; // master mode
    SPI2->CR1 |= SPI_CR1_SPE; // SPI enable
}

void SPI2_Send_byte(uint8_t data) {
    while (!(SPI2->SR & SPI_SR_TXE));
    SPI2->DR = data;
}
