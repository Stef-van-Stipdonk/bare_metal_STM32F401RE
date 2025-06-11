#include "uart.h"
#include "uart_regs.h"
#include <stdint.h>

extern char test_v;

void IRQ_uart_handler(void) {
    test_v = (uint8_t) (UART2->DR & 255);
}
