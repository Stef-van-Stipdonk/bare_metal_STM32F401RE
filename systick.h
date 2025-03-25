#ifndef SYSTICK_H
#define SYSTICK_H 1

/*
 * System timer
 * Width: 24 bit
 *
 * DESCRIPTION:
 * The timer counts down from the "reload value" (STK_LOAD) to zero,
 * then reloads (wraps to) the "reload value" (STK_LOAD) set in the STK_LOAD register.
 *
 * More info:
 *	Section 4.5 | PM0214 Programming manual
 * 
 * REGISTERS:
 *	(STK_CTRL) SysTick control and status register
 *		Address:		0xE000E010
 *		Type:			RW
 *		Required privilege:	Privileged
 *		Reset Value:		0x00000000
 *
 *	(STK_LOAD) SysTick reload value register
 *		Address:		0xE000E014
 *		Type:			RW
 *		Required privilege:	Privileged
 *		Reset Value:		Unknown
 *
 *	(STK_VAL) Systick current value register
 *		Address:		0xE000E018
 *		Type:			RW
 *		Required privilege:	Privileged
 *		Reset Value:		Unknown
 *
 *	(STK_CALIB) Calibration value register
 *		Address:		0xE000E01C
 *		Type:			RO
 *		Required privilege:	Privileged
 *		Reset Value:		0xC0000000
 *
*/

#include <stdint.h>
#include <stdbool.h>
#include "rcc.h"
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

static inline void systick_init(uint32_t ticks_p) {
	uint32_t ticks = ticks_p - 1; // Ticks should be N-1 for repeat interrupts

	if (ticks <= 0 && ticks > STK_LOAD_MAX_VALUE) {
		return;
	}

	SYSTICK->LOAD = ticks;
	SYSTICK->VAL = 0;
	SYSTICK->CTRL = SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_TICKINT | SYSTICK_CTRL_CLKSOURCE;
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
}

static volatile uint32_t s_ticks;
void SysTick_Handler(void) {
	s_ticks++;
}

bool timer_expired(uint32_t *timer_p, uint32_t period_p, uint32_t now_p) {
	if (now_p + period_p < *timer_p) {
		*timer_p = 0;
	}

	if (*timer_p == 0) {
		*timer_p = now_p + period_p;
	}

	if (*timer_p > now_p) {
		return false;
	}

	*timer_p = (now_p - *timer_p) > period_p ? now_p + period_p : *timer_p + period_p;
	return true;
}

#endif // SYSTICK_H
