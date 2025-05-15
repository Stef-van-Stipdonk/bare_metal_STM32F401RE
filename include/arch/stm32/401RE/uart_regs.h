#ifndef UART_REGS_H
#define UART_REGS_H

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
* MACROS UART_SR
*/

//
// USART_SR_PE
//
#define UART_SR_PE_POS     0
#define UART_SR_PE_WIDTH   1
#define UART_SR_PE_MASK    (0x1 << UART_SR_PE_POS)

#define UART_SR_SET_PE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_PE_MASK) | (((val) & 0x1) << UART_SR_PE_POS); \
    } while (0)

#define UART_SR_GET_PE(reg) \
    (((reg) & UART_SR_PE_MASK) >> UART_SR_PE_POS)

//
// USART_SR_FE
//
#define UART_SR_FE_POS     1
#define UART_SR_FE_WIDTH   1
#define UART_SR_FE_MASK    (0x1 << UART_SR_FE_POS)

#define UART_SR_SET_SE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_FE_MASK) | (((val) & 0x1) << UART_SR_FE_POS); \
    } while (0)

#define UART_SR_GET_FE(reg) \
    (((reg) & UART_SR_FE_MASK) >> UART_SR_FE_POS)


//
// USART_SR_NF
//
#define UART_SR_NF_POS     1
#define UART_SR_NF_WIDTH   1
#define UART_SR_NF_MASK    (0x1 << UART_SR_NF_POS)

#define UART_SR_SET_NF(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_NF_MASK) | (((val) & 0x1) << UART_SR_NF_POS); \
    } while (0)

#define UART_SR_GET_NF(reg) \
    (((reg) & UART_SR_NF_MASK) >> UART_SR_NF_POS)


//
// USART_SR_ORE
//
#define UART_SR_ORE_POS     1
#define UART_SR_ORE_WIDTH   1
#define UART_SR_ORE_MASK    (0x1 << UART_SR_ORE_POS)

#define UART_SR_SET_ORE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_ORE_MASK) | (((val) & 0x1) << UART_SR_ORE_POS); \
    } while (0)

#define UART_SR_GET_ORE(reg) \
    (((reg) & UART_SR_ORE_MASK) >> UART_SR_ORE_POS)


//
// USART_SR_IDLE
//
#define UART_SR_IDLE_POS     1
#define UART_SR_IDLE_WIDTH   1
#define UART_SR_IDLE_MASK    (0x1 << UART_SR_IDLE_POS)

#define UART_SR_SET_IDLE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_IDLE_MASK) | (((val) & 0x1) << UART_SR_IDLE_POS); \
    } while (0)

#define UART_SR_GET_IDLE(reg) \
    (((reg) & UART_SR_IDLE_MASK) >> UART_SR_IDLE_POS)


//
// USART_SR_RXNE
//
#define UART_SR_RXNE_POS     1
#define UART_SR_RXNE_WIDTH   1
#define UART_SR_RXNE_MASK    (0x1 << UART_SR_RXNE_POS)

#define UART_SR_SET_RXNE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_RXNE_MASK) | (((val) & 0x1) << UART_SR_RXNE_POS); \
    } while (0)

#define UART_SR_GET_RXNE(reg) \
    (((reg) & UART_SR_RXNE_MASK) >> UART_SR_RXNE_POS)


//
// USART_SR_TC
//
#define UART_SR_TC_POS     1
#define UART_SR_TC_WIDTH   1
#define UART_SR_TC_MASK    (0x1 << UART_SR_TC_POS)

#define UART_SR_SET_TC(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_TC_MASK) | (((val) & 0x1) << UART_SR_TC_POS); \
    } while (0)

#define UART_SR_GET_TC(reg) \
    (((reg) & UART_SR_TC_MASK) >> UART_SR_TC_POS)


//
// USART_SR_TXE
//
#define UART_SR_TXE_POS     1
#define UART_SR_TXE_WIDTH   1
#define UART_SR_TXE_MASK    (0x1 << UART_SR_TXE_POS)

#define UART_SR_SET_TXE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_TXE_MASK) | (((val) & 0x1) << UART_SR_TXE_POS); \
    } while (0)

#define UART_SR_GET_TXE(reg) \
    (((reg) & UART_SR_TXE_MASK) >> UART_SR_TXE_POS)


//
// USART_SR_LBD
//
#define UART_SR_LBD_POS     1
#define UART_SR_LBD_WIDTH   1
#define UART_SR_LBD_MASK    (0x1 << UART_SR_LBD_POS)

#define UART_SR_SET_LBD(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_LBD_MASK) | (((val) & 0x1) << UART_SR_LBD_POS); \
    } while (0)

#define UART_SR_GET_LBD(reg) \
    (((reg) & UART_SR_LBD_MASK) >> UART_SR_LBD_POS)


//
// USART_SR_CTS
//
#define UART_SR_CTS_POS     1
#define UART_SR_CTS_WIDTH   1
#define UART_SR_CTS_MASK    (0x1 << UART_SR_CTS_POS)

#define UART_SR_SET_CTS(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_CTS_MASK) | (((val) & 0x1) << UART_SR_CTS_POS); \
    } while (0)

#define UART_SR_GET_CTS(reg) \
    (((reg) & UART_SR_CTS_MASK) >> UART_SR_CTS_POS)

#endif // UART_REGS_H
