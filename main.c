#include "nvic.h"
#include "rcc.h"
#include "systick.h"
#include "uart.h"
#include "flash.h"
#include "uart_regs.h"
#include <stdint.h>

static volatile  char test_v = 'a';

int main(void) {
	rcc_init();
	uart_init(UART2, 115200);
	uart_write_buffer(UART2, "[INFO] UART initialized\r\n");
	// systick_init(1000000);

    UART2->CR1 |= BIT(5); // Enable interrupts
    nvic_enable_irq(38);
    char tmp = test_v;
    for (;;) {
        if (tmp != test_v) {
            tmp = test_v;
            uart_write_byte(UART2, test_v);
        }
    }
}

// UART interrupt handler
void uart_handler(void) {
	test_v = (uint8_t) (UART2->DR & 255);
}

extern void _estack(void);

__attribute__((naked, noreturn)) void _reset(void) {
    extern long _sbss, _ebss, _sdata, _edata, _sidata;
    for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;  // Clear BSS
    for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;  // Copy data section

    // Debug: Indicate reset handler is called

    main();  // Call main()
    for (;;) (void) 0;  // Infinite loop if main() returns
}

__attribute__((section(".vectors"))) void (* const tab[16 + 91])(void) = {
	_estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, IRQ_systick_handler, [16 + 38] = uart_handler, 
};
