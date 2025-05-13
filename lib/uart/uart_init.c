#include "uart.h"
#include "rcc.h"
#include "common_defines.h"
#include "gpio.h"
#include "common.h"
#include <stdint.h>
#include <stddef.h>

void uart_init(struct uart_t *uart_p, uint32_t baud_p) {
	if (uart_p == NULL)
		return; // TODO: Add error here

	if (UART1 != uart_p && UART2 != uart_p)
		return; // TODO: Add error here

	RCC->AHB1ENR |= BIT(0);
	__asm volatile ("dsb");

	uint8_t af = 7;
	uint16_t rx = 0;
	uint16_t tx = 0;
	

	if (uart_p == UART1) {
		RCC->APB2ENR |= BIT(4);
		uart_p->BRR = APB2_MAX_FREQ / baud_p;
		tx = PIN('A', 9);
		rx = PIN('A', 10);
	}

	if (uart_p == UART2) {
		RCC->APB1ENR |= BIT(17);
		uart_p->BRR = APB1_MAX_FREQ / baud_p;
		tx = PIN('A', 2);
		rx = PIN('A', 3);
	}

	gpio_set_mode(tx, GPIO_MODE_AF);
	gpio_set_af(tx, af);

	gpio_set_mode(rx, GPIO_MODE_AF);
	gpio_set_af(rx, af);

	uart_p->CR1 &= ~(1U << 12); // Set M bit to 0, meaning 8 bit word length
	uart_p->CR2 &= ~(1u << 12 | 1u << 13); // Set stopbits to 0
	uart_p->CR1 |= BIT(13); // Flip UE register: USART enable
	uart_p->CR1 |= BIT(3);
	uart_p->CR1 |= BIT(2);

	spin(84000000);
}
