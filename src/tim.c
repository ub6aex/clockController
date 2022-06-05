#include "stm32f103xb.h"
#include "tim.h"

#define SYSTEMCOREFREQ 72000000U // System Clock Frequency

void TIM2init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // TIM2 clock enable
    TIM2->PSC = 36000-1; // prescaler for 500us delay
    TIM2->CR1 |= TIM_CR1_OPM; // one pulse mode
}

void delay_ms(uint16_t value) {
    TIM2->ARR = (value-1)*2;
    TIM2->CNT = 0;
    TIM2->CR1 |= TIM_CR1_CEN; // start timer
    while((TIM2->SR & TIM_SR_UIF)==0){} // wait
    TIM2->SR &= ~TIM_SR_UIF; // reset flag
}

void delay_us(uint32_t micros) {
    micros *= (SYSTEMCOREFREQ / 1000000) / 10;
    while (micros--) ;
}
