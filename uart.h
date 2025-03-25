#include "gpio.h"
#include <stdint.h>
#ifndef UART_H
#define UART_H 1

#include "rcc.h"
#include <stddef.h>

#define BIT(x) (1UL << (x))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define FREQ 16000000 // 16 Mhz

struct uart_t {
	volatile uint32_t SR;	// Status Register
	volatile uint32_t DR;	// Data Register
	volatile uint32_t BRR;	// Baud Rate Register
	volatile uint32_t CR1;	// Control Register 1
	volatile uint32_t CR2;	// Control Register 2
	volatile uint32_t CR3;	// Control Register 3
	volatile uint32_t GTPR;	// Guard Time and Prescaler Register
};

#define UART1 ((struct uart_t *) 0x40011000)
#define UART2 ((struct uart_t *) 0x40004400)

static inline void spin(volatile uint32_t count) {
  while (count--) (void) 0;
}

static inline void uart_init(struct uart_t *uart_p, unsigned long baud_p) {
	uint8_t af = 7;
	uint16_t rx = 0;
	uint16_t tx = 0;

	if (uart_p == UART1) {
		RCC->APB2ENR |= BIT(4);
		tx = PIN('A', 9);
		rx = PIN('A', 10);
	}

	if (uart_p == UART2) {
		RCC->APB1ENR |= BIT(17);
		tx = PIN('A', 2);
		rx = PIN('A', 3);
	}

	gpio_set_mode(tx, GPIO_MODE_AF);
	gpio_set_af(tx, af);

	gpio_set_mode(rx, GPIO_MODE_AF);
	gpio_set_af(rx, af);

	uart_p->CR1 = 0;
	uart_p->BRR = FREQ / baud_p;
	uart_p->CR1 |= BIT(13) | BIT(2) | BIT(3);
}

static inline int uart_read_ready(struct uart_t *uart_p) {
	return uart_p->SR & BIT(5);
}

static inline uint8_t uart_read_byte(struct uart_t *uart_p) {
	return (uint8_t) (uart_p->DR & 255);
}

static inline void uart_write_byte(struct uart_t *uart_p, uint8_t byte_p) {
	uart_p->DR = byte_p;
	while ((uart_p->SR & BIT(7)) == 0) 
		spin(1);
}

static inline void uart_write_buf(struct uart_t *uart_p, char *buf_p, size_t len_p) {
	while (len_p-- > 0)
		uart_write_byte(uart_p, *(uint8_t *) buf_p++);
}

#endif // UART_H

