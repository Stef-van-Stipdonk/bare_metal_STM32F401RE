#include "gpio.h"
#include "rcc.h"
#include "uart.h"
#include "systick.h"
#include "flash.h"
#include "common_defines.h"
#include <stdint.h>

void init() {
	RCC->CR |= RCC_CR_HSION; // Enable to HSI

	while (!(RCC->CR & RCC_CR_HSIRDY)) // Wait for HSI to be ready
		;
	
	RCC->CFGR |= RCC_CFGR_SW_HSI; // Set clocksource to HSI

	while (!(RCC->CFGR & RCC_CFGR_SWS_HSI)) // Wait until HSI is used as the system clock
		;

	FLASH->ACR 
		|= FLASH_ACR_LATENCY_2WS // Based on 84 Mhz clock
		| FLASH_ACR_PRFTEN
		| FLASH_ACR_ICEN
		| FLASH_ACR_DCEN;

	// PLLM = 16
	// PLLN = 336
	// PLLP = 0b01 (which is 4 in the datasheet)
	// HSI  = 16 Mhz
	// (HSI / PLLM) * PLLN / PLLP = SYCLK
	RCC->PLLCFGR 
		|= 16 << RCC_PLLCFGR_PLLM_POS	// Set PLLM
		| 336 << RCC_PLLCFGR_PLLN_POS	// Set PLLN
		| 0b01 << RCC_PLLCFGR_PLLP_POS	// Set PLLP
		| RCC_PLLCFGR_PLLSRC_HSI;	// Set source HSI
	
	RCC->CR |= RCC_CR_PLLON; // Enable PLL

	while (!(RCC->CR & RCC_CR_PLLRDY)) // Wait for PLL to be ready
		;

	RCC->CFGR |= RCC_CFGR_SW_PLL; // Set PLL as the system clock source

	while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) // Wait for PLL to be set as the clock source
		;
}

int main(void) {
	init();
	uart_init(UART2, 115200);
	uart_write_buf(UART2, "[INFO] UART initialized\r\n");
 
	for (;;) {
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
