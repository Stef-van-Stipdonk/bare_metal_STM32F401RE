#include <stdint.h>
#include "uart.h"
#include "uart_regs.h"

uint8_t uart_read_byte(struct uart_t *uart_p) {
	return (uint8_t) (uart_p->DR & 255);
}
