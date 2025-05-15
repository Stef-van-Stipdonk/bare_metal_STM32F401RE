#ifndef GPIO_H
#define GPIO_H 1

// Purpose:
// Setup for GPIO registers

#include <stdint.h>
#include <stdbool.h>

enum {
	GPIO_MODE_INPUT,
	GPIO_MODE_OUTPUT,
	GPIO_MODE_AF,
	GPIO_MODE_ANALOG
};

/**
* Description: Set GPIO pin mode
* Params:
* - pin[in] The pin of which the mode will be set
* - mode[in] The mode to which a pin will the set
*/
void gpio_set_mode(uint16_t pin, uint8_t mode);

/**
* Description: Set GPIO Alternate Function pin mode
* Params:
* - pin[in] The pin of which the mode will be set
* - mode[in] The GPIO Alternate Function mode to set on the pin
*/
void gpio_set_af(uint16_t pin, uint8_t af_num);

#endif // GPIO_H
