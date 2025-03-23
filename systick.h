#ifndef SYSTICK_H
#define SYSTICK_H 1

#include <stdint.h>
#include "rcc.h"
#include <stdbool.h>

#define BIT(x) (1UL << (x))

struct systick_t {
	volatile uint32_t CTRL;		// Control and Status Register
	volatile uint32_t LOAD;		// Reload Value Register
	volatile uint32_t VAL;		// Current Value Register
	volatile uint32_t CALIB;	// Calibration Value Register
};

#define SYSTICK ((struct systick_t *) 0xE000E010)

static inline void systick_init(uint32_t ticks_p) {
	if ((ticks_p - 1) > 0xffffff) return; // Timer is 24 bit
	
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
