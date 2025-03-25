#include "gpio.h"
#include "uart.h"
#include "systick.h"
#include <stdint.h>

int main(void) {
	uint16_t led = PIN('A', 5);
	systick_init(FREQ / 1000);
	gpio_set_mode(led, GPIO_MODE_OUTPUT);
	uart_init(UART2, 115200);
	uint32_t timer, period = 500;
	for (;;) {
		if (timer_expired(&timer, period, s_ticks)) {
			static bool led_state;
			gpio_write(led, led_state);
			led_state = !led_state;
			uart_write_buf(UART2, "hi\r\n", 4);
		}
	}
}

__attribute__((naked, noreturn)) void _reset(void) {
    extern long _sbss, _ebss, _sdata, _edata, _sidata;
    for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;  // Clear BSS
    for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;  // Copy data section

    // Debug: Indicate reset handler is called

    main();  // Call main()
    for (;;) (void) 0;  // Infinite loop if main() returns
}

extern void _estack(void);

__attribute__((section(".vectors"))) void (* const tab[16 + 91])(void) = {
	_estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SysTick_Handler
};
