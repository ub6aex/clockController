#include "stm32f103xb.h"
#include "indicator.h"
#include "spi.h"
#include "gpio.h"
#include "tim.h"

void resetShifts() {
    shifts_nrst_on();
    delay_ms(10);
    shifts_nrst_off();
}

void indicatorEnable() {
    shifts_nrst_off();
}

void indicatorDisable() {
    shifts_nrst_on();
}

uint8_t data[7];

void clearBuffer() {
    for (int i=0;i<7;i++) data[i] = 0x00;
}

void sendBuffer(uint8_t *buffer) {
    for (int i=0;i<7;i++) SPI2_Send_byte(buffer[i]);
}

void fillMinus() {
    data[5] |= 0b00110000;
    data[6] |= 0b00000100;
}

void fillPlus() {
    data[5] |= 0b00110000;
    data[6] |= 0b00001110;
}

void fillPoint() {
    data[0] |= 0b10000000;
}

void fillColon() {
    data[0] |= 0b01000000;
}

uint16_t digit_masks[13] = {
    0b0111111111111, //0
    0b0011111000000, //1
    0b1111101111101, //2
    0b1111111110101, //3
    0b1011111000111, //4
    0b1110111110111, //5
    0b1110111111111, //6
    0b0111111000001, //7
    0b1111111111111, //8
    0b1111111110111, //9
    0b0000000000000, //10 - void
    0b1101000000010, //11 - degree
    0b0110001101110, //12 - celsium
};

uint16_t day_dig1_masks[8] = {
    0b0000000000000, //void
    0b0111111011111, //Mo
    0b1101010111111, //Tu
    0b0110001101110, //We
    0b1011111000111, //Th
    0b0111111011111, //Fr
    0b0110001101110, //Sa
    0b1101010111111, //Su
};

uint16_t day_dig2_masks[8] = {
    0b00000000000000, //void
    0b01011111011111, //Mo
    0b10110000000001, //Tu
    0b01101000011111, //We
    0b10110000000001, //Th
    0b10110000000001, //Fr
    0b01110010111111, //Sa
    0b00110001101110, //Su
};

void fillNum1(uint16_t *mask, uint8_t num) {
    data[5] |= mask[num] >> 8;
    data[6] |= mask[num];
}

void fillNum2(uint16_t *mask, uint8_t num) {
    data[3] |= mask[num] >> 10; 
    data[4] |= mask[num] >> 2;
    data[5] |= mask[num] << 6;
}

void fillNum3(uint16_t *mask, uint8_t num) {
    data[1] |= mask[num] >> 13;
    data[2] |= mask[num] >> 5;
    data[3] |= mask[num] << 3;
}

void fillNum4(uint16_t *mask, uint8_t num) {
    data[0] |= mask[num] >> 7;
    data[1] |= mask[num] << 1;
}

void indicatorSetNum(uint8_t num1, uint8_t num2, uint8_t num3, uint8_t num4) {
    clearBuffer();
    fillNum1(digit_masks, num1);
    fillNum2(digit_masks, num2);
    fillNum3(digit_masks, num3);
    fillNum4(digit_masks, num4);
    resetShifts();
    sendBuffer(data);
}

void indicatorSetTime(uint8_t num1, uint8_t num2, uint8_t num3, uint8_t num4) {
    clearBuffer();
    fillNum1(digit_masks, num1);
    fillNum2(digit_masks, num2);
    fillColon();
    fillNum3(digit_masks, num3);
    fillNum4(digit_masks, num4);
    resetShifts();
    sendBuffer(data);
}

void indicatorSetDate(uint8_t num1, uint8_t num2, uint8_t num3, uint8_t num4) {
    clearBuffer();
    fillNum1(digit_masks, num1);
    fillNum2(digit_masks, num2);
    fillPoint();
    fillNum3(digit_masks, num3);
    fillNum4(digit_masks, num4);
    resetShifts();
    sendBuffer(data);
}

void indicatorSetDay(uint8_t day) {
    clearBuffer();
    fillNum2(day_dig1_masks, day);
    fillNum3(day_dig2_masks, day);
    resetShifts();
    sendBuffer(data);
}

void indicatorSetTemp(uint8_t minus, uint8_t tempH, uint8_t tempL) {
    clearBuffer();
    if ((tempH == 0) && (tempL == 0)) {
        fillNum2(digit_masks, 0);
        fillNum3(digit_masks, 11); // degree symbol
    } else {
        if (tempH == 0) tempH = 10; // void indicator mask
        if (minus) fillMinus();
        else fillPlus();
        fillNum2(digit_masks, tempH);
        fillNum3(digit_masks, tempL);
        fillNum4(digit_masks, 11); // degree symbol
    }
    resetShifts();
    sendBuffer(data);
}

void indicatorTestDigits() {
    for (uint8_t i=0;i<10;i++) {
        indicatorSetNum(i,i,i,i);
        delay_ms(500);
    }
    clearBuffer();
    resetShifts();
}

void indicatorTestSigns() {
    clearBuffer();
    fillMinus();
    resetShifts();
    sendBuffer(data);
    delay_ms(1000);

    clearBuffer();
    fillPoint();
    resetShifts();
    sendBuffer(data);
    delay_ms(1000);

    clearBuffer();
    fillColon();
    resetShifts();
    sendBuffer(data);
    delay_ms(1000);

    clearBuffer();
    resetShifts();
}

void indicatorTestSegment(uint8_t num) {
    if (num > 56) return;
    clearBuffer();
    if (num == 0) for (int i=0;i<7;i++) data[i] = 0xFF; // fill all segments
    else if (num < 8*1+1) data[6] = (1 << (num-1-8*0));
    else if (num < 8*2+1) data[5] = (1 << (num-1-8*1));
    else if (num < 8*3+1) data[4] = (1 << (num-1-8*2));
    else if (num < 8*4+1) data[3] = (1 << (num-1-8*3));
    else if (num < 8*5+1) data[2] = (1 << (num-1-8*4));
    else if (num < 8*6+1) data[1] = (1 << (num-1-8*5));
    else if (num < 8*7+1) data[0] = (1 << (num-1-8*6));
    else return;
    resetShifts();
    sendBuffer(data);
}
