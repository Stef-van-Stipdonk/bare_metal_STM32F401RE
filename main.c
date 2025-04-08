#include "gpio.h"
#include "rcc.h"
#include "uart.h"
#include "systick.h"
#include "flash.h"
#include "common_defines.h"
#include <stdint.h>

void init() {
	RCC->CR |= (1U << 16); // Turn on HSE clock
	
	while ((RCC->CR & (1U << 17)) == 0) // IS HSE ready
		;

	// HSE = 8 MHZ, target SYSCLK = 84 Mhz:
	// - pllm = 8 devices 8 Mhz to 1 Mhz
	// - plln = 336 multiplies 1 Mhz to 336 Mhz (VC0 frequency)
	// - pllp = 4 devides 336 Mhz by 4 to get 84 Mhz
	// - pllsrc = 1 selects HSE as PLL source
	// - pllq = 7 for usb and sdio etc (or so I've read)
	const uint32_t pllm = 8;
	const uint32_t plln = 336;
	const uint32_t pllp = 4;
	const uint32_t pllsrc = 1;
	const uint32_t pllq = 7;

	RCC->PLLCFGR |= pllm << 0;
	RCC->PLLCFGR |= plln << 6;
	RCC->PLLCFGR |= pllp << 16;
	RCC->PLLCFGR |= pllsrc << 22;
	RCC->PLLCFGR |= pllq << 24;

	RCC->CR |= (1U << 24);
	while ((RCC->CR & (1U << 25)) == 0) // Wait for PLL lock
		;

	FLASH->ACR &= ~7U;
	FLASH->ACR |= 2;

	RCC->CFGR &= ~(3U << 0);
	RCC->CFGR |= 2U << 0;

	while ((RCC->CFGR & 0xCU) != (2U << 2))
		;
}

int main(void) {
	init();
	systick_init(INITIAL_CPU_FREQ);
	uart_init(UART2, 115200);
	uart_write_buf(UART2, "[INFO] UART initialized\r\n");

	uint16_t led = PIN('A', 5);
	gpio_set_mode(led, GPIO_MODE_OUTPUT);
	uint32_t timer, period = 500;
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

    main();  // Call main()
    for (;;) (void) 0;  // Infinite loop if main() returns
}

extern void _estack(void);

__attribute__((section(".vectors"))) void (* const tab[16 + 91])(void) = {
	_estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SysTick_Handler
};
