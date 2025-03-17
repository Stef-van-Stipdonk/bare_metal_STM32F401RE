#include "gpio.h"
#include "rcc.h"
#include <stdint.h>

static inline void spin(volatile uint32_t count_p) {
	while (count_p--) (void) 0;
}

int main(void) {
	uint16_t led = PIN('A', 5);
	RCC->AHB1ENR |= BIT(0);
	gpio_set_mode(led, GPIO_MODE_OUTPUT);
	for (;;) {
		GPIO(PINBANK(led))->BSRR = (1U << 5);spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		GPIO(PINBANK(led))->BSRR = (1U << (5 + 16));  // Reset PA5
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
		spin(999999);
	}

}

__attribute__((naked, noreturn)) void _reset(void) {
    extern long _sbss, _ebss, _sdata, _edata, _sidata;
    for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;  // Clear BSS
    for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;  // Copy data section

    // Debug: Indicate reset handler is called
    GPIO(PINBANK(PIN('A', 5)))->BSRR = (1U << 5);  // Set PA5
    spin(999999);

    main();  // Call main()
    for (;;) (void) 0;  // Infinite loop if main() returns
}

extern void _estack(void);

__attribute__((section(".vectors"))) void (* const tab[16 + 91])(void) = {
	_estack, _reset
};
