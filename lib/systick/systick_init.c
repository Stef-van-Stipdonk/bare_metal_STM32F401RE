#include "systick.h"
#include "systick_regs.h"
#include <stdint.h>

volatile uint32_t s_ticks = 0;

void systick_init(uint32_t ticks_p) {
	uint32_t ticks = ticks_p - 1;

	if (ticks == 0 || ticks > STK_LOAD_MAX_VALUE) {
		return;
	}

	SYSTICK->LOAD = ticks;
	SYSTICK->VAL = 0;
	SYSTICK->CTRL = (SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_TICKINT | SYSTICK_CTRL_CLKSOURCE);
}

