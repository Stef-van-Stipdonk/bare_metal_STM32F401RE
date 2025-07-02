#include "rcc_regs.h"
#include "gpio.h"
#include "common_defines.h"
#include "gpio_regs.h"

void gpio_set_mode(uint16_t pin_p, uint8_t mode_p) {
	struct gpio_t *gpio = GPIO(PINBANK(pin_p));
	uint8_t pin_nr = PINNO(pin_p);
	RCC->AHB1ENR |= BIT(0);
	gpio->MODER &= ~(3U << (pin_nr * 2));
	gpio->MODER |= (mode_p & 3U) << (pin_nr * 2);
}
