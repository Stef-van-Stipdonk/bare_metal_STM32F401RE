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

static inline void systick_init(uint32_t ticks_p) {
	if ((ticks_p - 1) > 0xffffff) return;
	
	SYSTICK->LOAD = ticks_p - 1;
	SYSTICK->VAL = 0;
	SYSTICK->CTRL = BIT(0) | BIT(1) | BIT(2);
	RCC->APB2ENR |= BIT(14);
}

static volatile uint32_t s_ticks;
void SysTick_Handler(void) {
	s_ticks++;
}

bool timer_expired(uint32_t *t, uint32_t prd, uint32_t now) {
	if (now + prd < *t) *t = 0;                    // Time wrapped? Reset timer
	if (*t == 0) *t = now + prd;                   // First poll? Set expiration
	if (*t > now) return false;                    // Not expired yet, return
	*t = (now - *t) > prd ? now + prd : *t + prd;  // Next expiration time
	return true;                                   // Expired, return true
}

#endif // SYSTICK_H
