#include "systick.h"

void systick_handler(void) {
	s_ticks++;
}
