#ifndef _INDICATOR_H_
#define _INDICATOR_H_

void indicatorEnable();
void indicatorDisable();
void indicatorSetNum(uint8_t dig1, uint8_t dig2, uint8_t dig3, uint8_t dig4);
void indicatorSetTime(uint8_t dig1, uint8_t dig2, uint8_t dig3, uint8_t dig4);
void indicatorSetDate(uint8_t dig1, uint8_t dig2, uint8_t dig3, uint8_t dig4);
void indicatorSetDay(uint8_t day);
void indicatorSetTemp(uint8_t minus, uint8_t tempH, uint8_t tempL);
void indicatorTestDigits();
void indicatorTestSigns();
void indicatorTestSegment(uint8_t num);

#endif
