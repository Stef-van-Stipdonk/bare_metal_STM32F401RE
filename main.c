#include "rcc.h"
#include "systick.h"
#include "uart.h"
#include "flash.h"
#include <stdint.h>

int main(void) {
	rcc_init();
	uart_init(UART2, 115200);
	uart_write_buffer(UART2, "[INFO] UART initialized\r\n");
	systick_init(1000000);

    uint32_t last_ticks = s_ticks;
    for (;;) {
        if (s_ticks != last_ticks) {
            uart_write_buffer(UART2, "TICK\r\n");
            last_ticks = s_ticks;
        }
    }
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
	_estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, systick_handler 
};
