#ifndef _DS1820_H_
#define _DS1820_H_

void ds1820_init(void); 
uint8_t ds1820_reset(void);
uint8_t ds1820_readBit(void);
uint8_t ds1820_readByte(void);
void ds1820_writeBit(uint8_t bit);
void ds1820_writeByte(uint8_t bit);
void ds1820_startTempMeasure(void);
uint16_t ds1820_getTemp(void);

#endif
