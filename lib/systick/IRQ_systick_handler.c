#include "systick.h"

volatile uint32_t s_ticks = 0;

void IRQ_systick_handler(void) {
	s_ticks++;
}
