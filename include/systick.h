#ifndef SYSTICK_H
#define SYSTICK_H 1

#include <stdint.h>
#include "systick_regs.h"

extern volatile uint32_t s_ticks;

void systick_init(uint32_t ticks_p);

void systick_handler(void);

#endif // SYSTICK_H
