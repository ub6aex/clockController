#ifndef _DS1706_H_
#define _DS1706_H_

struct ds1307_data_struct {
    uint8_t minuteH;
    uint8_t minuteL;
    uint8_t hourH;
    uint8_t hourL;

    uint8_t day;

    uint8_t dateH;
    uint8_t dateL;
    uint8_t monthH;
    uint8_t monthL;

    uint8_t yearH;
    uint8_t yearL;

    uint8_t secondH;
    uint8_t secondL;
};

uint8_t dec2bcd(uint8_t dec);
uint8_t bcd2dec(uint8_t bcd);

void ds1307_init(struct ds1307_data_struct *rtc_data);

void ds1307_osc_enable();
void ds1307_osc_disable();

void ds1307_set_24h_format();
void ds1307_set_12h_format();

void ds1307_get_time(struct ds1307_data_struct *rtc_data);
void ds1307_get_all(struct ds1307_data_struct *rtc_data);

void ds1307_set_hour(uint8_t hour);
void ds1307_set_minute(uint8_t min);
void ds1307_set_second(uint8_t second);

void ds1307_set_month(uint8_t month);
void ds1307_set_date(uint8_t date);
void ds1307_set_day(uint8_t day);
void ds1307_set_year(uint8_t year);

void ds1307_set_ram(uint8_t addr, uint8_t data);
uint8_t ds1307_get_ram(uint8_t addr);

#endif
