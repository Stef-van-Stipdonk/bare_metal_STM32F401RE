#ifndef GPIO_H
#define GPIO_H 1

// Purpose:
// Setup for GPIO registers

#include <stdint.h>
#include <stdbool.h>

#include "rcc.h"
#include "common_defines.h"

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

enum {
	GPIO_MODE_INPUT, 
	GPIO_MODE_OUTPUT, 
	GPIO_MODE_AF, 
	GPIO_MODE_ANALOG
};

static inline void gpio_write(uint16_t pin_p, bool val_p) {
	struct gpio_t *gpio = GPIO(PINBANK(pin_p));
	gpio->BSRR = (1U << PINNO(pin_p)) << (val_p ? 0 : 16);
}

static inline void gpio_set_mode(uint16_t pin_p, uint8_t mode_p) {
	struct gpio_t *gpio = GPIO(PINBANK(pin_p));
	uint8_t pin_nr = PINNO(pin_p);
	RCC->AHB1ENR |= BIT(0);
	gpio->MODER &= ~(3U << (pin_nr * 2));
	gpio->MODER |= (mode_p & 3U) << (pin_nr * 2);
}

static inline void gpio_set_af(uint16_t pin_p, uint8_t af_num_p) {
	struct gpio_t *gpio = GPIO(PINBANK(pin_p));
	int pin_nr = PINNO(pin_p);
	gpio->AFR[pin_nr >> 3] &= ~(15UL << ((pin_nr & 7) * 4));
	gpio->AFR[pin_nr >> 3] |= ((uint32_t) af_num_p) << ((pin_nr & 7) * 4);
}



#endif // GPIO_H
