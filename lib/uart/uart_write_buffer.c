#include "uart.h"
#include "common_defines.h"
#include <stddef.h>

void uart_write_buffer(struct uart_t *uart_p, char *buf_p) {
	if (uart_p == NULL)
		return; // TODO: Add error here

	if (UART1 != uart_p && UART2 != uart_p)
		return; // TODO: Add error here
	
	if (buf_p == NULL)
		return; // TODO: Add error here

	while (*buf_p != '\0')
		uart_write_byte(uart_p, *(uint8_t *) buf_p++);

	while (!(uart_p->SR & BIT(6)))
		;
}
