#ifndef GPIO_REGS_H
#define GPIO_REGS_H

#include <stdint.h>

struct gpio_t {
	volatile uint32_t MODER;	// Port Mode Register
	volatile uint32_t OTYPER;	// Port Output Type Register
	volatile uint32_t OSPEEDR;	// Port Output Speed Register
	volatile uint32_t PUPDR;	// Port Pull-up/Pull-down Register
	volatile uint32_t IDR;		// Port Input Data Register
	volatile uint32_t ODR;		// Port Output Data Register
	volatile uint32_t BSRR;		// Port Bit Set/Reset Register
	volatile uint32_t LCKR;		// Port Configuration Lock Register
	volatile uint32_t AFR[2];	// Alternate Function Low Register
};

#endif // GPIO_REGS_H
