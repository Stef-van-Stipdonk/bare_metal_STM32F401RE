#include "nvic.h"
#include "rcc.h"
#include "systick.h"
#include "uart.h"
#include "flash.h"
#include "uart_regs.h"
#include "circular_buffer.h"
#include <stdint.h>

extern volatile struct circular_buffer uart_receive_buffer;

int main(void) {
	rcc_init();
	uart_init(UART2, 115200);
	uart_write_buffer(UART2, "[INFO] UART initialized\r\n");

    uint16_t tmp = uart_receive_buffer.head; 

    for (;;) {
        if (tmp != uart_receive_buffer.head)
        {
            uint8_t out;
            CircularBuffer_Pop(&uart_receive_buffer, &out);
            uart_write_byte(UART2, out);
            tmp = uart_receive_buffer.head;
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
	_estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, IRQ_systick_handler, [16 + 38] = IRQ_uart_handler, 
};
