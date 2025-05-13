#include "uart.h"
#include "common_defines.h"
#include "common.h"

void uart_write_byte(struct uart_t *uart_p, uint8_t byte_p) {
	while ((uart_p->SR & BIT(7)) == 0) {
		spin(1);
	}
	uart_p->DR = byte_p;

}
