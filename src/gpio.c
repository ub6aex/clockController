#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "gpio.h"
#include "tim.h"

void GPIOinit(void) {
/*****************  port A  *****************/
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // port A clock enable

    GPIOA->CRL |= GPIO_CRL_MODE1; // output mode, max speed 50 Mhz
    GPIOA->CRL &= ~GPIO_CRL_CNF1; // general purpose output push-pull

/*****************  port B  *****************/
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // port B clock enable

    // input 1
    GPIOB->CRL &= ~GPIO_CRL_MODE0; // input mode
    GPIOB->CRL |= GPIO_CRL_CNF0_0; // floating input
    GPIOB->CRL &= ~GPIO_CRL_CNF0_1; // floating input

    // input 2
    GPIOB->CRL &= ~GPIO_CRL_MODE1; // input mode
    GPIOB->CRL |= GPIO_CRL_CNF1_0; // floating input
    GPIOB->CRL &= ~GPIO_CRL_CNF1_1; // floating input

    // input 3
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;
    GPIOB->CRL &= ~GPIO_CRL_MODE3; // input mode
    GPIOB->CRL |= GPIO_CRL_CNF3_0; // floating input
    GPIOB->CRL &= ~GPIO_CRL_CNF3_1; // floating input

    // input 4
    GPIOB->CRL &= ~GPIO_CRL_MODE4; // input mode
    GPIOB->CRL |= GPIO_CRL_CNF4_0; // floating input
    GPIOB->CRL &= ~GPIO_CRL_CNF4_1; // floating input

    // shifts NRST
    GPIOB->CRH |= GPIO_CRH_MODE9; // output mode, max speed 50 Mhz
    GPIOB->CRH &= ~GPIO_CRH_CNF9; // general purpose output push-pull

    // RTC SQW
    GPIOB->CRH &= ~GPIO_CRH_MODE8; // input mode
    GPIOB->CRH |= GPIO_CRH_CNF8_0; // floating input
    GPIOB->CRH &= ~GPIO_CRH_CNF8_1; // floating input
}

void status_led_on(void) {
    GPIOA->ODR &= ~GPIO_ODR_ODR1;
}

void status_led_off(void) {
    GPIOA->ODR |= GPIO_ODR_ODR1;
}

void shifts_nrst_on(void) {
    GPIOB->ODR &= ~GPIO_ODR_ODR9;
}

void shifts_nrst_off(void) {
    GPIOB->ODR |= GPIO_ODR_ODR9;
}

int readInput(int num) {
    switch(num) {
        case 1:
            if (READ_BIT(GPIOB->IDR, GPIO_IDR_IDR0)) {
                delay_ms(10);
                if (READ_BIT(GPIOB->IDR, GPIO_IDR_IDR0)) return 0;
                else return 1;
            } else return 1;
        case 2:
            if (READ_BIT(GPIOB->IDR, GPIO_IDR_IDR1)) {
                delay_ms(10);
                if (READ_BIT(GPIOB->IDR, GPIO_IDR_IDR1)) return 0;
                else return 1;
            } else return 1;
        case 3:
            if (READ_BIT(GPIOB->IDR, GPIO_IDR_IDR3)) {
                delay_ms(10);
                if (READ_BIT(GPIOB->IDR, GPIO_IDR_IDR3)) return 0;
                else return 1;
            } else return 1;
        case 4:
            if (READ_BIT(GPIOB->IDR, GPIO_IDR_IDR4)) {
                delay_ms(10);
                if (READ_BIT(GPIOB->IDR, GPIO_IDR_IDR4)) return 0;
                else return 1;
            } else return 1;
        default:
            return 0;
  }
}

/*
// Hardcode Exaples:

void GPIOB_init(void) {
    GPIOB_CRL &= 0xFFFFFFF0; //ÉèÖÃ GPIOA_0-4ÎªÊä³öÄ£Ê½
    GPIOB_CRL |= 0x3; 
    GPIOB_ODR |= 0x1;
}
*/
