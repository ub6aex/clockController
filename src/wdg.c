#include "stm32f103xb.h"
#include "wdg.h"

#define WDG_COUNT 0x00004000U

void WDGinit(uint16_t ms) {
    IWDG->KR=0x5555; // access key
    IWDG->PR=7; // prescaler
    IWDG->RLR=ms*40/256; // counter
    IWDG->KR=0xAAAA; // reset timer
    IWDG->KR=0xCCCC; // enable wdg
}

void WDGreset() {
    IWDG->KR=0xAAAA; // reset timer
}
