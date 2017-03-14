#ifndef _TIME_H_
#define _TIME_H_
#include "stm32f10x.h"

void time_init();
uint32_t millis();
uint32_t micros();
void delayMicroseconds(uint32_t micros);
void delayMillis(uint32_t millis);

#endif
