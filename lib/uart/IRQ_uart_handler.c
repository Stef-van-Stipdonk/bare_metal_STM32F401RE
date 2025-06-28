#include "uart.h"
#include "uart_regs.h"
#include "circular_buffer.h"
#include <stdint.h>
#include "uart_regs.h"

extern volatile struct circular_buffer uart_receive_buffer;

void IRQ_uart_handler(void) {
    CircularBuffer_Push(&uart_receive_buffer,(uint8_t) (UART2->DR & 255));
}
