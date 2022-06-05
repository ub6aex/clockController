#ifndef _GPIO_H_
#define _GPIO_H_

void GPIOinit(void);

void status_led_on(void);
void status_led_off(void);

void shifts_nrst_on(void);
void shifts_nrst_off(void);

int readInput(int);

#endif
