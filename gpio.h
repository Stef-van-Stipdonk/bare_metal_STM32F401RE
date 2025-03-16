#ifndef GPIO_H
#define GPIO_H 1

// Purpose:
// Setup for GPIO registers

#include <stdint.h>

#define BIT(x) (1UL << (x))
#define GPIO(bank) ((struct gpio_t *) (0x40020000 + 0x400 * (bank)))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (uint8_t)(pin & 255)
#define PINBANK(pin) (pin >> 8)

struct gpio_t {
	volatile uint32_t MODER;	// Port Mode Register
	volatile uint32_t OTYPER;	// Port Output Type Register
	volatile uint32_t OSPEEDR;	// Port Output Speed Register
	volatile uint32_t PUPDR;	// Port Pull-up/Pull-down Register
	volatile uint32_t IDR;		// Port Input Data Register
	volatile uint32_t ODR;		// Port Output Data Register
	volatile uint32_t BSRR;		// Port Bit Set/Reset Register
	volatile uint32_t LCKR;		// Port Configuration Lock Register
	volatile uint32_t AFRL;		// Alternate Function Low Register
	volatile uint32_t AFRH;		// Alternate Function High Register
};


enum {
	GPIO_MODE_INPUT, 
	GPIO_MODE_OUTPUT, 
	GPIO_MODE_AF, 
	GPIO_MODE_ANALOG
};

static inline void gpio_set_mode(uint16_t pin_p, uint8_t mode_p) {
	struct gpio_t *gpio = GPIO(PINBANK(pin_p));
	uint8_t pin_nr = PINNO(pin_p);
	gpio->MODER &= ~(3U << (pin_nr * 2));
	gpio->MODER |= (mode_p & 3U) << (pin_nr * 2);
}

#endif // GPIO_H
