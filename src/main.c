#include "stm32f103xb.h"
#include "stdio.h"
#include "string.h"
#include "usart.h"
#include "rcc_init.h"
#include "gpio.h"
#include "tim.h"
#include "spi.h"
#include "indicator.h"
#include "i2c.h"
#include "ds1307.h"
#include "ds1820.h"
#include "wdg.h"

#define SET_BLINK_NUM_MS 100
#define SET_BLINK_BLANK_MS 50
#define SHOW_TIME_DELAY_RAM_ADDR 0
#define SHOW_DATE_DELAY_RAM_ADDR 1
#define SHOW_DAY_DELAY_RAM_ADDR 2
#define SHOW_TEMPERATURE_DELAY_RAM_ADDR 3
#define SHOW_DELAY_MAX 60
#define SHOW_DELAY_MIN 0

enum {
    showTime,
    showDate,
    showDay,
    showTemperature,
    setHour,
    setMinute,
    setMonth,
    setDate,
    setDay,
    setYear,
    setShowTimeDelay,
    setShowDateDelay,
    setShowDayDelay,
    setShowTemperatureDelay
} clockMode;
uint8_t rtcDataChangedFlag = 1;

void blinkStatusLed(int count) {
    for (int i=0;i<count;i++) {
        status_led_on();
        delay_ms(10);
        status_led_off();
        delay_ms(300);
    }  
    delay_ms(300);
}

void logRtcData(struct ds1307_data_struct *rtc) {
    USART1_Send_String("\n\rtime: ");
    USART1_Send_uInt(rtc->hourH);
    USART1_Send_uInt(rtc->hourL);
    USART1_Send_String(":");
    USART1_Send_uInt(rtc->minuteH);
    USART1_Send_uInt(rtc->minuteL);
    USART1_Send_String(":");
    USART1_Send_uInt(rtc->secondH);
    USART1_Send_uInt(rtc->secondL);

    USART1_Send_String("\n\rday: ");
    USART1_Send_uInt(rtc->day);

    USART1_Send_String("\n\rdate: ");
    USART1_Send_uInt(rtc->dateH);
    USART1_Send_uInt(rtc->dateL);
    USART1_Send_String(".");
    USART1_Send_uInt(rtc->monthH);
    USART1_Send_uInt(rtc->monthL);
    USART1_Send_String(".");
    USART1_Send_uInt(rtc->yearH);
    USART1_Send_uInt(rtc->yearL);
}

void logTempData(uint8_t minus, uint8_t temp) {
    USART1_Send_String("\n\rtemp: ");
    if (minus) USART1_Send_String("-");
    else USART1_Send_String("+");
    USART1_Send_uInt((uint32_t)temp);
    USART1_Send_String("C");
}

int main() {
    WDGinit(10000); // init and launch watchdog first
    USART1_Init(8); // 8 mhz before rcc init
    USART1_Send_String("\n\r----- Start -----");
    USART1_Send_String("\n\rGPIO init");
    GPIOinit();
    USART1_Send_String("\n\rRCC init");
    RCCinit();
    USART1_Send_String("\n\rTIM2 init");
    TIM2init();
    USART1_Send_String("\n\rSPI22 init");
    SPI2init();
    USART1_Send_String("\n\rI2C1 init");
    I2C1init();
    delay_ms(1000);
    USART1_Send_String("\n\rDS1307 init");
    struct ds1307_data_struct rtc;
    struct ds1307_data_struct rtcBuffer = {0};
    ds1307_init(&rtc);

    USART1_Send_String("\n\rds1820 init");
    ds1820_init();
    USART1_Send_String("\n\rds1820 reset...");
    if (!ds1820_reset()) USART1_Send_String("ok");
    else USART1_Send_String("ERROR");
    status_led_on();
    ds1820_startTempMeasure();
    delay_ms(1000);
    status_led_off();
    uint16_t temp_value_signed = ds1820_getTemp();
    uint8_t temp_value_unsigned = (temp_value_signed & 0x00FF);
    uint8_t temp_minus = (temp_value_signed >> 8);

    clockMode = showTime; // init state

    uint8_t showTime_delay = ds1307_get_ram(SHOW_TIME_DELAY_RAM_ADDR);
    uint8_t showDate_delay = ds1307_get_ram(SHOW_DATE_DELAY_RAM_ADDR);
    uint8_t showDay_delay = ds1307_get_ram(SHOW_DAY_DELAY_RAM_ADDR);
    uint8_t showTemperature_delay = ds1307_get_ram(SHOW_TEMPERATURE_DELAY_RAM_ADDR);
    if(!showTime_delay && !showDate_delay && !showDay_delay && !showTemperature_delay) {
        showTime_delay = 50;
        showDate_delay = 25;
        showDay_delay = 25;
        showTemperature_delay = 25;
    }
    uint32_t show_delay_counter = showTime_delay*10;

    indicatorEnable();

    USART1_Send_String("\n\r----- Start main loop -----");
    while(1) {
        WDGreset(); // watchdog reset
        ds1307_get_all(&rtc);

        if (clockMode != setShowTemperatureDelay) {
            if ((rtcBuffer.secondL == 0) & (rtc.secondL == 1)) ds1820_startTempMeasure();
            if ((rtcBuffer.secondL == 5) & (rtc.secondL == 6)) {
                temp_value_signed = ds1820_getTemp();
                temp_value_unsigned = (temp_value_signed & 0x00FF);
                temp_minus = (temp_value_signed >> 8);
                if (temp_value_unsigned > 50) showTemperature_delay = 0; // sensor error
            }
        }

        // delay_ms(1000);

        if (memcmp(&rtcBuffer, &rtc, sizeof(rtc)-2)) { // compare without seconds
            rtcDataChangedFlag = 1;
            logRtcData(&rtc);
            logTempData(temp_minus, temp_value_unsigned);
            USART1_Send_String("\n\r");
        }
        memcpy(&rtcBuffer, &rtc, sizeof(struct ds1307_data_struct));

        switch(clockMode) {
            case showTime:
                if ((!show_delay_counter)||(!showTime_delay)) {
                    show_delay_counter = showDate_delay*50; clockMode = showDate; rtcDataChangedFlag = 1;
                    break;
                } else show_delay_counter -= 1;
                if (rtcDataChangedFlag) {
                    indicatorSetTime(rtcBuffer.hourH,rtcBuffer.hourL,rtcBuffer.minuteH,rtcBuffer.minuteL);
                    rtcDataChangedFlag = 0;
                }
                break;

            case showDate:
                if ((!show_delay_counter)||(!showDate_delay)) {
                    show_delay_counter = showDay_delay*50; clockMode = showDay; rtcDataChangedFlag = 1;
                    break;
                } else show_delay_counter -= 1;
                if (rtcDataChangedFlag) {
                    indicatorSetDate(rtcBuffer.dateH,rtcBuffer.dateL,rtcBuffer.monthH,rtcBuffer.monthL);
                    rtcDataChangedFlag = 0;
                }
                break;

            case showDay:
                if ((!show_delay_counter)||(!showDay_delay)) {
                    show_delay_counter = showTemperature_delay*50; clockMode = showTemperature; rtcDataChangedFlag = 1;
                    break;
                } else show_delay_counter -= 1;
                if (rtcDataChangedFlag) {
                    indicatorSetDay(rtcBuffer.day);
                    rtcDataChangedFlag = 0;
                }
                break;

            case showTemperature:
                if ((!show_delay_counter)||(!showTemperature_delay)) {
                    show_delay_counter = showTime_delay*50; clockMode = showTime; rtcDataChangedFlag = 1;
                    break;
                } else show_delay_counter -= 1;
                if (rtcDataChangedFlag) {
                    uint8_t temp_value_unsigned_H = temp_value_unsigned / 10;
                    uint8_t temp_value_unsigned_L = temp_value_unsigned % 10;
                    indicatorSetTemp(temp_minus, temp_value_unsigned_H, temp_value_unsigned_L);
                    rtcDataChangedFlag = 0;
                }
                break;

            case setHour:
                indicatorSetTime(rtcBuffer.hourH,rtcBuffer.hourL,rtcBuffer.minuteH,rtcBuffer.minuteL);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetTime(10,10,rtcBuffer.minuteH,rtcBuffer.minuteL);
                delay_ms(SET_BLINK_BLANK_MS);
                uint8_t hour = bcd2dec((rtcBuffer.hourH << 4) | rtcBuffer.hourL);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setMinute; }

                if (readInput(2)) {
                    if (hour == 23) hour = 0; else hour++;
                }
                else if (readInput(3)) {
                    if (hour == 0) hour = 23; else hour--;
                }
                else break;

                USART1_Send_String("\n\rset hour: ");
                USART1_Send_uInt(hour);
                ds1307_set_hour(hour);

                break;

            case setMinute:
                indicatorSetTime(rtcBuffer.hourH,rtcBuffer.hourL,rtcBuffer.minuteH,rtcBuffer.minuteL);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetTime(rtcBuffer.hourH,rtcBuffer.hourL,10,10);
                delay_ms(SET_BLINK_BLANK_MS);
                uint8_t minute = bcd2dec((rtcBuffer.minuteH << 4) | rtcBuffer.minuteL);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setDate; }

                if (readInput(2)) {
                    if (minute == 59) minute = 0; else minute++;
                }
                else if (readInput(3)) {
                    if (minute == 0) minute = 59; else minute--;
                }
                else break;

                USART1_Send_String("\n\rset minute: ");
                USART1_Send_uInt(minute);
                ds1307_set_minute(minute);
                ds1307_set_second(0);

                break;

            case setDate:
                indicatorSetDate(rtcBuffer.dateH,rtcBuffer.dateL,rtcBuffer.monthH,rtcBuffer.monthL);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetDate(10,10,rtcBuffer.monthH,rtcBuffer.monthL);
                delay_ms(SET_BLINK_BLANK_MS);
                uint8_t date = bcd2dec((rtcBuffer.dateH << 4) | rtcBuffer.dateL);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setMonth; }

                if (readInput(2)) {
                    if (date == 31) date = 1; else date++;
                }
                else if (readInput(3)) {
                    if (date == 1) date = 31; else date--;
                }
                else break;

                USART1_Send_String("\n\rset date: ");
                USART1_Send_uInt(date);
                ds1307_set_date(date);

                break;

            case setMonth:
                indicatorSetDate(rtcBuffer.dateH,rtcBuffer.dateL,rtcBuffer.monthH,rtcBuffer.monthL);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetDate(rtcBuffer.dateH,rtcBuffer.dateL,10,10);
                delay_ms(SET_BLINK_BLANK_MS);
                uint8_t month = bcd2dec((rtcBuffer.monthH << 4) | rtcBuffer.monthL);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setDay; }

                if (readInput(2)) {
                    if (month == 12) month = 1; else month++;
                }
                else if (readInput(3)) {
                    if (month == 1) month = 12; else month--;
                }
                else break;

                USART1_Send_String("\n\rset month: ");
                USART1_Send_uInt(month);
                ds1307_set_month(month);

                break;

            case setDay:
                indicatorSetDay(rtcBuffer.day);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetNum(10,10,10,10);
                delay_ms(SET_BLINK_BLANK_MS);
                uint8_t day = bcd2dec(rtcBuffer.day);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setYear; }

                if (readInput(2)) {
                    if (day == 7) day = 1; else day++;
                }
                else if (readInput(3)) {
                    if (day == 1) day = 7; else day--;
                }
                else break;

                USART1_Send_String("\n\rset day: ");
                USART1_Send_uInt(day);
                ds1307_set_day(day);

                break;

            case setYear:
                indicatorSetNum(2, 0, rtcBuffer.yearH, rtcBuffer.yearL);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetNum(2,0,10,10);
                delay_ms(SET_BLINK_BLANK_MS);
                uint8_t year = bcd2dec((rtcBuffer.yearH << 4) | rtcBuffer.yearL);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setShowTimeDelay; rtcDataChangedFlag = 1; }

                if (readInput(2)) {
                    if (year == 99) year = 0; else year++;
                }
                else if (readInput(3)) {
                    if (year == 0) year = 99; else year--;
                }
                else break;

                USART1_Send_String("\n\rset year: ");
                USART1_Send_uInt(year);
                ds1307_set_year(year);

                break;

            case setShowTimeDelay: 
                indicatorSetNum(1, 10, dec2bcd(showTime_delay) >> 4, dec2bcd(showTime_delay) & 0x0F);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetNum(1,10,10,10);
                delay_ms(SET_BLINK_BLANK_MS);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setShowDateDelay; rtcDataChangedFlag = 1; }

                if (readInput(2)) {
                    if (showTime_delay >= SHOW_DELAY_MAX) showTime_delay = SHOW_DELAY_MIN; else showTime_delay++;
                }
                else if (readInput(3)){
                    if (showTime_delay <= SHOW_DELAY_MIN) showTime_delay = SHOW_DELAY_MAX; else showTime_delay--;
                }
                else break;

                USART1_Send_String("\n\rset show_Time_delay: ");
                USART1_Send_uInt(showTime_delay);
                ds1307_set_ram(SHOW_TIME_DELAY_RAM_ADDR, showTime_delay);

                break;

            case setShowDateDelay:
                indicatorSetNum(2, 10, dec2bcd(showDate_delay) >> 4, dec2bcd(showDate_delay) & 0x0F);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetNum(2,10,10,10);
                delay_ms(SET_BLINK_BLANK_MS);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setShowDayDelay; rtcDataChangedFlag = 1; }

                if (readInput(2)) {
                    if (showDate_delay >= SHOW_DELAY_MAX) showDate_delay = SHOW_DELAY_MIN; else showDate_delay++;
                }
                else if (readInput(3)) {
                    if (showDate_delay <= SHOW_DELAY_MIN) showDate_delay = SHOW_DELAY_MAX; else showDate_delay--;
                }
                else break;

                USART1_Send_String("\n\rset show_Date_delay: ");
                USART1_Send_uInt(showDate_delay);
                ds1307_set_ram(SHOW_DATE_DELAY_RAM_ADDR, showDate_delay);

                break;

            case setShowDayDelay:
                indicatorSetNum(3, 10, dec2bcd(showDay_delay) >> 4, dec2bcd(showDay_delay) & 0x0F);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetNum(3,10,10,10);
                delay_ms(SET_BLINK_BLANK_MS);

                if (readInput(1)) { blinkStatusLed(1); clockMode = setShowTemperatureDelay; rtcDataChangedFlag = 1; }

                if (readInput(2)) {
                    if (showDay_delay >= SHOW_DELAY_MAX) showDay_delay = SHOW_DELAY_MIN; else showDay_delay++;
                }
                else if (readInput(3)) {
                    if (showDay_delay <= SHOW_DELAY_MIN) showDay_delay = SHOW_DELAY_MAX; else showDay_delay--;
                }
                else break;

                USART1_Send_String("\n\rset show_Day_delay: ");
                USART1_Send_uInt(showDay_delay);
                ds1307_set_ram(SHOW_DAY_DELAY_RAM_ADDR, showDay_delay);

                break;

            case setShowTemperatureDelay:
                indicatorSetNum(4, 10, dec2bcd(showTemperature_delay) >> 4, dec2bcd(showTemperature_delay) & 0x0F);
                delay_ms(SET_BLINK_NUM_MS);
                indicatorSetNum(4,10,10,10);
                delay_ms(SET_BLINK_BLANK_MS);

                if (readInput(1)) { blinkStatusLed(1); clockMode = showTime; rtcDataChangedFlag = 1; delay_ms(100); }

                if (readInput(2)) {
                    if (showTemperature_delay >= SHOW_DELAY_MAX) showTemperature_delay = SHOW_DELAY_MIN; else showTemperature_delay++;
                }
                else if (readInput(3)) {
                    if (showTemperature_delay <= SHOW_DELAY_MIN) showTemperature_delay = SHOW_DELAY_MAX; else showTemperature_delay--;
                }
                else break;

                USART1_Send_String("\n\rset show_Temperature_delay: ");
                USART1_Send_uInt(showTemperature_delay);
                ds1307_set_ram(SHOW_TEMPERATURE_DELAY_RAM_ADDR, showTemperature_delay);

                break;

        }

        // enter set mode
        if (readInput(1)) { 
            for (int i = 0; i < 21; i++) {
                if (!(readInput(1))) break;
                delay_ms(100);
                if ((i == 20) & (readInput(1))) {
                    blinkStatusLed(1);
                    indicatorSetNum(10,10,10,10);
                    delay_ms(2000);
                    clockMode = setHour;
                }
            }
        }

        // enter segments debug mode
        if (readInput(4)) {
            for (int i = 0; i < 51; i++) {
                if (!(readInput(4))) break;
                delay_ms(100);
                if ((i == 50) & (readInput(4))) {
                    blinkStatusLed(4);

                    uint8_t segment_num = 1;
                    indicatorTestSegment(segment_num);

                    while(!(readInput(1))) {
                        WDGreset(); // watchdog reset
                        if (readInput(2)) { if (segment_num < 56) segment_num++; indicatorTestSegment(segment_num); }
                        if (readInput(3)) { if (segment_num > 1) segment_num--; indicatorTestSegment(segment_num); }
                        if (readInput(4)) {
                            indicatorTestDigits();
                            WDGreset(); // watchdog reset
                            indicatorTestSigns();
                            WDGreset(); // watchdog reset
                            indicatorTestSegment(segment_num);
                        }
                        delay_ms(200);
                    }
                    delay_ms(1000);
                    clockMode = showTime;
                    rtcDataChangedFlag = 1;
                }
            }
        }
    }
}
