#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "ds1307.h"
#include "i2c.h"
#include "usart.h"

uint8_t dec2bcd(uint8_t dec) {
    uint8_t dec_H = (dec / 10) << 4;
    uint8_t dec_L = dec % 10;
    return dec_H | dec_L;
}

uint8_t bcd2dec(uint8_t bcd) {
    uint8_t bcd_H = (bcd >> 4) & 0x0F;
    uint8_t bcd_L = bcd & 0x0F;
    return bcd_H*10 + bcd_L;
}

void ds1307_osc_enable(void) {
    USART1_Send_String("\n\rds1307 osc enabling...");
    uint8_t i2c_rd_value = 0;
    I2C1_ReadBytes(0x0000, &i2c_rd_value, 1);
    uint8_t i2c_wr_value = i2c_rd_value &= ~(0x80);
    I2C1_WriteBytes(0x0000, &i2c_wr_value, 1);
    I2C1_ReadBytes(0x0000, &i2c_rd_value, 1);
    if (!(i2c_rd_value & 0x80)) USART1_Send_String("ok");
    else USART1_Send_String("ERROR");
}

void ds1307_osc_disable(void) {
    USART1_Send_String("\n\rds1307 osc disabling...");
    uint8_t i2c_rd_value = 0;
    I2C1_ReadBytes(0x0000, &i2c_rd_value, 1);
    uint8_t i2c_wr_value = i2c_rd_value |= (0x80);
    I2C1_WriteBytes(0x0000, &i2c_wr_value, 1);
    I2C1_ReadBytes(0x0000, &i2c_rd_value, 1);
    if (i2c_rd_value & 0x80) USART1_Send_String("ok");
    else USART1_Send_String("ERROR");
}

void ds1307_set_24h_format(void) {
    USART1_Send_String("\n\rds1307 setting 24h format...");
    uint8_t i2c_rd_value = 0;
    I2C1_ReadBytes(0x0002, &i2c_rd_value, 1);
    uint8_t i2c_wr_value = i2c_rd_value &= ~(0x40);
    I2C1_WriteBytes(0x0002, &i2c_wr_value, 1);
    I2C1_ReadBytes(0x0002, &i2c_rd_value, 1);
    if (!(i2c_rd_value & 0x40)) USART1_Send_String("ok");
    else USART1_Send_String("ERROR");
}

void ds1307_set_12h_format(void) {
    USART1_Send_String("\n\rds1307 setting 12h format...");
    uint8_t i2c_rd_value = 0;
    I2C1_ReadBytes(0x0002, &i2c_rd_value, 1);
    uint8_t i2c_wr_value = i2c_rd_value |= (0x40);
    I2C1_WriteBytes(0x0002, &i2c_wr_value, 1);
    I2C1_ReadBytes(0x0002, &i2c_rd_value, 1);
    if (i2c_rd_value & 0x40) USART1_Send_String("ok");
    else USART1_Send_String("ERROR");
}

void ds1307_set_1Hz_sqw(void) {
    USART1_Send_String("\n\rds1307 setting 1Hz SQW out...");
    uint8_t i2c_rd_value = 0;
    I2C1_ReadBytes(0x0007, &i2c_rd_value, 1);
    uint8_t i2c_wr_value = i2c_rd_value;
    i2c_wr_value &= ~(0b00000011); // freq = 1HZ
    i2c_wr_value |= (0b00010000); // enable SQW out
    I2C1_WriteBytes(0x0007, &i2c_wr_value, 1);
    I2C1_ReadBytes(0x0007, &i2c_rd_value, 1);
    if (i2c_rd_value & 0b00010000) USART1_Send_String("ok");
    else USART1_Send_String("ERROR");
}

void ds1307_init(struct ds1307_data_struct *rtc_data) {
    rtc_data->secondH = 0;
    rtc_data->secondL = 0;

    rtc_data->hourH = 0;
    rtc_data->hourL = 0;
    rtc_data->minuteH = 0;
    rtc_data->minuteL = 0;

    rtc_data->day = 0;

    rtc_data->dateH = 0;
    rtc_data->dateL = 0;
    rtc_data->monthH = 0;
    rtc_data->monthL = 0;

    rtc_data->yearH = 0;
    rtc_data->yearL = 0;

    ds1307_set_24h_format();
    ds1307_set_1Hz_sqw();
    ds1307_osc_enable();
}

void ds1307_get_time(struct ds1307_data_struct *rtc_data) {
    uint8_t i2c_rd_value[2] = {0};
    I2C1_ReadBytes(0x0001, i2c_rd_value, 2);
    rtc_data->minuteL = (i2c_rd_value[0] & 0b00001111);
    rtc_data->minuteH = ((i2c_rd_value[0] & 0b01110000) >> 4);
    rtc_data->hourL = (i2c_rd_value[1] & 0b00001111);
    rtc_data->hourH = ((i2c_rd_value[1] & 0b00110000) >> 4);
}

void ds1307_get_all(struct ds1307_data_struct *rtc_data) {
    uint8_t i2c_rd_value[7] = {0};
    I2C1_ReadBytes(0x0000, i2c_rd_value, 7);
    rtc_data->secondL = (i2c_rd_value[0] & 0b00001111);
    rtc_data->secondH = ((i2c_rd_value[0] & 0b01110000) >> 4);

    rtc_data->minuteL = (i2c_rd_value[1] & 0b00001111);
    rtc_data->minuteH = ((i2c_rd_value[1] & 0b01110000) >> 4);
    rtc_data->hourL = (i2c_rd_value[2] & 0b00001111);
    rtc_data->hourH = ((i2c_rd_value[2] & 0b00110000) >> 4);

    rtc_data->day = (i2c_rd_value[3] & 0b00000111);

    rtc_data->dateL = (i2c_rd_value[4] & 0b00001111);
    rtc_data->dateH = ((i2c_rd_value[4] & 0b00110000) >> 4);
    rtc_data->monthL = (i2c_rd_value[5] & 0b00001111);
    rtc_data->monthH = ((i2c_rd_value[5] & 0b00010000) >> 4);

    rtc_data->yearL = i2c_rd_value[6] & 0b00001111;
    rtc_data->yearH = ((i2c_rd_value[6] & 0b11110000) >> 4);
}

void ds1307_set_hour(uint8_t hour) {
    uint8_t i2c_wr_value[] = {dec2bcd(hour) & 0b00111111};
    I2C1_WriteBytes(0x0002, i2c_wr_value, 1);
}

void ds1307_set_minute(uint8_t min) {
    uint8_t i2c_wr_value[] = {dec2bcd(min) & 0b01111111};
    I2C1_WriteBytes(0x0001, i2c_wr_value, 1);
}

void ds1307_set_second(uint8_t second) {
    uint8_t i2c_wr_value[] = {dec2bcd(second) & 0b01111111};
    I2C1_WriteBytes(0x0000, i2c_wr_value, 1);
}

void ds1307_set_month(uint8_t month) {
    uint8_t i2c_wr_value[] = {dec2bcd(month) & 0b00011111};
    I2C1_WriteBytes(0x0005, i2c_wr_value, 1);
}

void ds1307_set_date(uint8_t date) {
    uint8_t i2c_wr_value[] = {dec2bcd(date) & 0b00111111};
    I2C1_WriteBytes(0x0004, i2c_wr_value, 1);
}

void ds1307_set_day(uint8_t day) {
    uint8_t i2c_wr_value[] = {dec2bcd(day) & 0b00000111};
    I2C1_WriteBytes(0x0003, i2c_wr_value, 1);
}

void ds1307_set_year(uint8_t year) {
    uint8_t i2c_wr_value[] = {dec2bcd(year)};
    I2C1_WriteBytes(0x0006, i2c_wr_value, 1);
}

void ds1307_set_ram(uint8_t addr, uint8_t data) {
    uint8_t i2c_wr_value[] = {data};
    I2C1_WriteBytes(0x0008+addr, i2c_wr_value, 1);
}

uint8_t ds1307_get_ram(uint8_t addr) {
    uint8_t i2c_rd_value[] = {0};
    I2C1_ReadBytes(0x0008+addr, i2c_rd_value, 1);
    return i2c_rd_value[0];
}
