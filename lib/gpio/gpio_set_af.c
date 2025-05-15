#include "gpio.h"
#include "common_defines.h"
#include "gpio_regs.h"

void gpio_set_af(uint16_t pin_p, uint8_t af_num_p) {
	struct gpio_t *gpio = GPIO(PINBANK(pin_p));
	int pin_nr = PINNO(pin_p);
	gpio->AFR[pin_nr >> 3] &= ~(15UL << ((pin_nr & 7) * 4));
	gpio->AFR[pin_nr >> 3] |= ((uint32_t) af_num_p) << ((pin_nr & 7) * 4);
}
