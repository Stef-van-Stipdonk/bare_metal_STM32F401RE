#include <stdint.h>
#ifndef UART_H
#define UART_H 1

#include <stddef.h>
#include "gpio.h"
#include "common_defines.h"
#include "rcc.h"

struct uart_t {
	volatile uint32_t SR;	// Status Register
	volatile uint32_t DR;	// Data Register
	volatile uint32_t BRR;	// Baud Rate Register
	volatile uint32_t CR1;	// Control Register 1
	volatile uint32_t CR2;	// Control Register 2
	volatile uint32_t CR3;	// Control Register 3
	volatile uint32_t GTPR;	// Guard Time and Prescaler Register
} __attribute__((packed));

#define UART1 ((struct uart_t *) 0x40011000)
#define UART2 ((struct uart_t *) 0x40004400)

#define UART_IRQ_NUMBER 38

static inline void spin(volatile uint32_t count) {
  while (count--) (void) 0;
}

// TODO: Look at setting up clocks, seems like I have my config wrong.

static inline void uart_init(struct uart_t *uart_p, uint32_t baud_p) {
	// TODO: Look at RCC clock enabling
	// TODO: Look at usart flow control
	// TODO: Look at setting databits
	// TODO: Abstract away CR flow
	// TODO: Enable receive interrupt
	// TODO: Look at DMA
	// TODO: Setup NVIC for interrupt handling
	// TODO: Abstract away usart enable
	// TODO: Look at non blocking send
	
	if (uart_p == NULL)
		return; // TODO: Add error here

	if (UART1 != uart_p && UART2 != uart_p)
		return; // TODO: Add error here
	
	// TODO: Add check for baudrate here

	uint8_t af = 7;
	uint16_t rx = 0;
	uint16_t tx = 0;
	

	if (uart_p == UART1) {
		RCC->APB2ENR |= BIT(4);
		uint32_t uartdiv = (APB2_MAX_FREQ + (baud_p / 2)) / baud_p;
		uart_p->BRR = (uartdiv & ~0xFU) | ((uartdiv & ~0xFU) >> 1);
		tx = PIN('A', 9);
		rx = PIN('A', 10);
	}

	if (uart_p == UART2) {
		RCC->APB1ENR |= BIT(17);
		uint32_t usartdiv  = (APB1_MAX_FREQ + (baud_p >> 1)) / baud_p;
		uint32_t mantissa  =  usartdiv / 16;
		uint32_t fraction  =  usartdiv - (mantissa * 16);
		uart_p->BRR = (mantissa << 4) | (fraction & 0xF);
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
}

static inline int uart_read_ready(struct uart_t *uart_p) {
	return uart_p->SR & BIT(5);
}

static inline uint8_t uart_read_byte(struct uart_t *uart_p) {
	return (uint8_t) (uart_p->DR & 255);
}

static inline void uart_write_byte(struct uart_t *uart_p, uint8_t byte_p) {
	while ((uart_p->SR & BIT(7)) == 0) {
		spin(1);
	}
	uart_p->DR = byte_p;

}

static inline void uart_write_buf(struct uart_t *uart_p, char *buf_p) {
	if (uart_p == NULL)
		return; // TODO: Add error here

	if (UART1 != uart_p && UART2 != uart_p)
		return; // TODO: Add error here
	
	if (buf_p == NULL)
		return; // TODO: Add error here

	while (*buf_p != '\0')
		uart_write_byte(uart_p, *(uint8_t *) buf_p++);
}

#endif // UART_H
