#include "stm32f103xb.h"
#include "tim.h"
#include "usart.h"
#include "ds1820.h"

void ds1820_init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // port A clock enable

    GPIOA->CRH |= GPIO_CRH_MODE8; // output mode, max speed 50 Mhz
    GPIOA->CRH |= GPIO_CRH_CNF8_0; // GPIO output open-drain
    GPIOA->CRH &= ~GPIO_CRH_CNF8_1; // GPIO output open-drain
    GPIOA->ODR |= GPIO_ODR_ODR8; // set 1, but external pullup needed
}

uint8_t ds1820_reset(void) {
    uint8_t status;

    GPIOA->ODR &= ~GPIO_ODR_ODR8;
    delay_us(500);
    GPIOA->ODR |= GPIO_ODR_ODR8;
    delay_us(65);
    status = GPIOA->IDR & GPIO_IDR_IDR8;
    delay_us(500);

    return (status ? 1 : 0);
}

uint8_t ds1820_readBit(void) {
    uint8_t bit = 0;
    GPIOA->ODR &= ~GPIO_ODR_ODR8;
    delay_us(2);
    GPIOA->ODR |= GPIO_ODR_ODR8;
    delay_us(15);
    bit = (GPIOA->IDR & GPIO_IDR_IDR8 ? 1 : 0);
    delay_us(45);
    return bit;
}

uint8_t ds1820_readByte(void) {
    uint8_t byte = 0;
    for (uint8_t i = 0; i <= 7; i++)
        byte += ds1820_readBit() << i;
    return byte;
}

void ds1820_writeBit(uint8_t bit) {
    GPIOA->ODR &= ~GPIO_ODR_ODR8;
    delay_us(bit ? 3 : 65);
    GPIOA->ODR |= GPIO_ODR_ODR8;
    delay_us(bit ? 65 : 3);
}

void ds1820_writeByte(uint8_t byte) {
    for (uint8_t i = 0; i < 8; i++) {
        ds1820_writeBit(byte >> i & 1);
        delay_us(5);
    }
}

void ds1820_startTempMeasure(void) {
    if (ds1820_reset()) { USART1_Send_String("ds1820 reset error"); }
    ds1820_writeByte(0xCC);
    ds1820_writeByte(0x44);	
}

uint16_t ds1820_getTemp(void) {
    uint8_t data[9];
    // while (ds1820_readByte() != 0xFF); // 600ms
    // delay_us(800);
    if (ds1820_reset()) { USART1_Send_String("ds1820 reset error"); }
    ds1820_writeByte(0xCC);
    ds1820_writeByte(0xBE);
    for (uint8_t i = 0; i < 9; i++) {
        data[i] = ds1820_readByte();
    }
    ds1820_reset();
    return ((data[0]/2) | (data[1]) << 8);
}
