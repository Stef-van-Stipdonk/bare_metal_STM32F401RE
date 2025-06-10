#ifndef SYSTICK_REGS_H
#define SYSTICK_REGS_H 1

#include <stdint.h>
#include "common_defines.h"

struct systick_t {
	volatile uint32_t CTRL;		// Control and Status Register
	volatile uint32_t LOAD;		// Reload Value Register
	volatile uint32_t VAL;		// Current Value Register
	volatile uint32_t CALIB;	// Calibration Value Register
};

#define SYSTICK ((struct systick_t *) 0xE000E010)
#define STK_LOAD_MAX_VALUE 0xffffff

#define SYSTICK_CTRL_ENABLE BIT(0)
#define SYSTICK_CTRL_TICKINT BIT(1)
#define SYSTICK_CTRL_CLKSOURCE BIT(2)

#endif // SYSTICK_REGS_H
