#include "time.h"

volatile uint32_t micros_counter = 0;

#define SystemCoreClock 72000000

void time_init()
{
    SysTick_Config(SystemCoreClock / 1000000);
}

void SysTick_Handler()
{
    micros_counter++;
}

uint32_t millis()
{
    return micros_counter/1000;
}

uint32_t micros()
{
    return micros_counter;
}

void delayMicroseconds(uint32_t micros)
{
    int t=micros*36;
    for(;t--;t>0);
    // uint32_t stop_micros_counter = micros_counter + micros;
    // while (micros_counter < stop_micros_counter);
}

void delayMillis(uint32_t millis)
{
    delayMicroseconds(millis*1000);
}
