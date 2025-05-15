#ifndef UART_REGS_H
#define UART_REGS_H

#include <stdint.h>

#define UART_SR_PE_POS     0
#define UART_SR_PE_WIDTH   1
#define UART_SR_PE_MASK    (0x1 << UART_CFGR_PE_POS)

#define UART_SR_SET_PE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_PE_MASK) | (((val) & 0x1) << UART_SR_PE_POS); \
    } while (0)

#define UART_SR_GET_PE(reg) \
    (((reg) & UART_SR_PE_MASK) >> UART_SR_PE_POS)

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

#endif // UART_REGS_H
