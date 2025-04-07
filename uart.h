#include <stdint.h>
#ifndef UART_H
#define UART_H 1


//
// Setup procedure:
// 1. Enable USART by writing the UE bit in USART_CR1 register to 1.
// 2. Program the M bit in USART_CR1 to define the word length.
// 3. Program the number of stop bits in USART_CR2.
// 4. Select DMA enble (DMAT) in USART_CR3 if multibuffer communication is to take place.
//    Configure the DMA register as defined in multibuffer communication.
// 5. Select the desired baudrate using the USART_BRR register
// 6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
// 7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
//    for each data to be transmitted in case of single buffer.
// 8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
//    that the transmission of the last frame is complete. This is required for instance when
//    the USART is disabled or enters the Halt mode to avoid corrupting the last transmission.
//
// Single byte communication:
// The TXE bit is set by the hardware and it indicates:
// - The data has been moved from TDR to the shift register and the data transmission has
//   started.
// - The TDR register is empty.
// - The next data can be written in the USART_DR register without overwriting the
//   previous data.
// 
// This flag generates an interrupt if the TXEIE bit is set.
//


#include <stddef.h>
#include "gpio.h"
#include "common_defines.h"
#include "rcc.h"

// TODO: Look at rounding issues
// TODO: Clear SR error bits or confirm they're not set
// TODO: Configure config registers CR2/CR3

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


static inline void uart_init(struct uart_t *uart_p, unsigned long baud_p) {
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

	uart_p->CR1 &= ~(1U << 12); // Set M bit to 0, meaning 8 bit word length
	uart_p->CR2 &= ~(1u << 12 | 1u << 13); // Set stopbits to 0
	uart_p->BRR = FREQ / baud_p;
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
