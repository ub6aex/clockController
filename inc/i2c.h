#ifndef _I2C_H_
#define _I2C_H_

void I2C1init(void);
void I2C1_WriteBytes(uint16_t addr,uint8_t *buf, uint16_t bytes_count);
void I2C1_ReadBytes(uint16_t addr, uint8_t *buf, uint16_t bytes_count);

#endif
