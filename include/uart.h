#ifndef UART_H
#define UART_H 1

#include <stdint.h>

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

/**
* Description: intializes uart
* Params:
* - uart_p[in/out] address of the uart peripheral to be initialized
* - baud_p[in] the desired baudrate of the uart perhiperal
*/
void uart_init(struct uart_t *uart_p, uint32_t baud_p);


/**
* Description: Check if data can be read from uart
* Params:
* - uart_p[in] address of the uart peripheral to check for readyness
*/
int uart_read_ready(const struct uart_t *uart_p);

/**
* Description: Read a byte from uart perhipheral
* Params:
* - uart_p[in] address of the uart peripheral to read from
*/
uint8_t uart_read_byte(struct uart_t *uart_p);

/**
* Description: Write a byte to uart perhipheral
* Params:
* - uart_p[in] address of the uart peripheral to write to
* - byte_p[in] byte to write
*/
void uart_write_byte(struct uart_t *uart_p, uint8_t byte_p);


/**
* Description: Write buffer to uart perhipheral
* Params:
* - uart_p[in] address of the uart peripheral to write to
* - buf_p[in] buffer to write
*/
void uart_write_buffer(struct uart_t *uart_p, char *buf_p);

#endif // UART_H
