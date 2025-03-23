#include "gpio.h"
#include "rcc.h"
#include "systick.h"
#include <stdint.h>

int main(void) {
	uint16_t led = PIN('A', 5);
	RCC->AHB1ENR |= BIT(0);
	systick_init(16000000 / 1000); // TODO: understand what good defaults are for this.
	gpio_set_mode(led, GPIO_MODE_OUTPUT);

	uint32_t timer, period = 5000;
	for (;;) {
		if (timer_expired(&timer, period, s_ticks)) {
			static bool led_state;
			gpio_write(led, led_state);
			led_state = !led_state;
		}
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
	_estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SysTick_Handler
};
