#include "uart.h"
#include "common_defines.h"

int uart_read_ready(const struct uart_t *uart_p) {
	return uart_p->SR & BIT(5);
}
