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
#define UART_SR_NF_POS     2
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
#define UART_SR_ORE_POS     3
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
#define UART_SR_IDLE_POS     4
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
#define UART_SR_RXNE_POS     5
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
#define UART_SR_TC_POS     6
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
#define UART_SR_TXE_POS     7
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
#define UART_SR_LBD_POS     8
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
#define UART_SR_CTS_POS     9
#define UART_SR_CTS_WIDTH   1
#define UART_SR_CTS_MASK    (0x1 << UART_SR_CTS_POS)

#define UART_SR_SET_CTS(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_SR_CTS_MASK) | (((val) & 0x1) << UART_SR_CTS_POS); \
    } while (0)

#define UART_SR_GET_CTS(reg) \
    (((reg) & UART_SR_CTS_MASK) >> UART_SR_CTS_POS)

//
// USART_DR_DR
//
#define UART_DR_DR_POS 0
#define UART_DR_DR_WIDTH 8
#define UART_DR_DR_MASK (0xF << UART_DR_DR_POS)

#define UART_DR_SET_DR(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_DR_DR_MASK) | (((val) & 0xF) << UART_DR_DR_POS); \
    } while (0)

#define UART_DR_GET_DR(reg) \
    (((reg) & UART_DR_DR_MASK) >> UART_DR_DR_POS)

//
// USART_BRR_DIV_Fraction
//
#define UART_BRR_DIV_FRACTION_POS   0
#define UART_BRR_DIV_FRACTION_WIDTH 4
#define UART_BRR_DIV_FRACTION_MASK  (0xF << UART_BRR_DIV_FRACTION_POS)

#define UART_BRR_SET_DIV_FRACTION(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_BRR_DIV_FRACTION_MASK) | (((val) & 0xF) << UART_BRR_DIV_FRACTION_POS); \
    } while (0)

#define UART_BRR_GET_DIV_FRACTION(reg) \
    (((reg) & UART_BRR_DIV_FRACTION_MASK) >> UART_BRR_DIV_FRACTION_POS)


//
// USART_BRR_DIV_Mantissa
//
#define UART_BRR_DIV_MANTISSA_POS   4
#define UART_BRR_DIV_MANTISSA_WIDTH 12
#define UART_BRR_DIV_MANTISSA_MASK  (0xFFF << UART_BRR_DIV_MANTISSA_POS)

#define UART_BRR_SET_DIV_MANTISSA(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_BRR_DIV_MANTISSA_MASK) | (((val) & 0xFFF) << UART_BRR_DIV_MANTISSA_POS); \
    } while (0)

#define UART_BRR_GET_DIV_MANTISSA(reg) \
    (((reg) & UART_BRR_DIV_MANTISSA_MASK) >> UART_BRR_DIV_MANTISSA_POS)


//
// UART_CR1_OVER8
//
#define UART_CR1_OVER8_POS      15
#define UART_CR1_OVER8_WIDTH    1
#define UART_CR1_OVER8_MASK     (0x1 << UART_CR1_OVER8_POS)

#define UART_CR1_SET_OVER8(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_OVER8_MASK) | (((val) & 0x1) << UART_CR1_OVER8_POS); \
    } while (0)

#define UART_CR1_GET_OVER8(reg) \
    (((reg) & UART_CR1_OVER8_MASK) >> UART_CR1_OVER8_POS)


//
// UART_CR1_UE
//
#define UART_CR1_UE_POS         13
#define UART_CR1_UE_WIDTH       1
#define UART_CR1_UE_MASK        (0x1 << UART_CR1_UE_POS)

#define UART_CR1_SET_UE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_UE_MASK) | (((val) & 0x1) << UART_CR1_UE_POS); \
    } while (0)

#define UART_CR1_GET_UE(reg) \
    (((reg) & UART_CR1_UE_MASK) >> UART_CR1_UE_POS)


//
// UART_CR1_M
//
#define UART_CR1_M_POS          12
#define UART_CR1_M_WIDTH        1
#define UART_CR1_M_MASK         (0x1 << UART_CR1_M_POS)

#define UART_CR1_SET_M(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_M_MASK) | (((val) & 0x1) << UART_CR1_M_POS); \
    } while (0)

#define UART_CR1_GET_M(reg) \
    (((reg) & UART_CR1_M_MASK) >> UART_CR1_M_POS)


//
// UART_CR1_WAKE
//
#define UART_CR1_WAKE_POS       11
#define UART_CR1_WAKE_WIDTH     1
#define UART_CR1_WAKE_MASK      (0x1 << UART_CR1_WAKE_POS)

#define UART_CR1_SET_WAKE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_WAKE_MASK) | (((val) & 0x1) << UART_CR1_WAKE_POS); \
    } while (0)

#define UART_CR1_GET_WAKE(reg) \
    (((reg) & UART_CR1_WAKE_MASK) >> UART_CR1_WAKE_POS)


//
// UART_CR1_PCE
//
#define UART_CR1_PCE_POS        10
#define UART_CR1_PCE_WIDTH      1
#define UART_CR1_PCE_MASK       (0x1 << UART_CR1_PCE_POS)

#define UART_CR1_SET_PCE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_PCE_MASK) | (((val) & 0x1) << UART_CR1_PCE_POS); \
    } while (0)

#define UART_CR1_GET_PCE(reg) \
    (((reg) & UART_CR1_PCE_MASK) >> UART_CR1_PCE_POS)


//
// UART_CR1_PS
//
#define UART_CR1_PS_POS         9
#define UART_CR1_PS_WIDTH       1
#define UART_CR1_PS_MASK        (0x1 << UART_CR1_PS_POS)

#define UART_CR1_SET_PS(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_PS_MASK) | (((val) & 0x1) << UART_CR1_PS_POS); \
    } while (0)

#define UART_CR1_GET_PS(reg) \
    (((reg) & UART_CR1_PS_MASK) >> UART_CR1_PS_POS)


//
// UART_CR1_PEIE
//
#define UART_CR1_PEIE_POS       8
#define UART_CR1_PEIE_WIDTH     1
#define UART_CR1_PEIE_MASK      (0x1 << UART_CR1_PEIE_POS)

#define UART_CR1_SET_PEIE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_PEIE_MASK) | (((val) & 0x1) << UART_CR1_PEIE_POS); \
    } while (0)

#define UART_CR1_GET_PEIE(reg) \
    (((reg) & UART_CR1_PEIE_MASK) >> UART_CR1_PEIE_POS)


//
// UART_CR1_TXEIE
//
#define UART_CR1_TXEIE_POS      7
#define UART_CR1_TXEIE_WIDTH    1
#define UART_CR1_TXEIE_MASK     (0x1 << UART_CR1_TXEIE_POS)

#define UART_CR1_SET_TXEIE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_TXEIE_MASK) | (((val) & 0x1) << UART_CR1_TXEIE_POS); \
    } while (0)

#define UART_CR1_GET_TXEIE(reg) \
    (((reg) & UART_CR1_TXEIE_MASK) >> UART_CR1_TXEIE_POS)


//
// UART_CR1_TCIE
//
#define UART_CR1_TCIE_POS       6
#define UART_CR1_TCIE_WIDTH     1
#define UART_CR1_TCIE_MASK      (0x1 << UART_CR1_TCIE_POS)

#define UART_CR1_SET_TCIE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_TCIE_MASK) | (((val) & 0x1) << UART_CR1_TCIE_POS); \
    } while (0)

#define UART_CR1_GET_TCIE(reg) \
    (((reg) & UART_CR1_TCIE_MASK) >> UART_CR1_TCIE_POS)


//
// UART_CR1_RXNEIE
//
#define UART_CR1_RXNEIE_POS     5
#define UART_CR1_RXNEIE_WIDTH   1
#define UART_CR1_RXNEIE_MASK    (0x1 << UART_CR1_RXNEIE_POS)

#define UART_CR1_SET_RXNEIE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_RXNEIE_MASK) | (((val) & 0x1) << UART_CR1_RXNEIE_POS); \
    } while (0)

#define UART_CR1_GET_RXNEIE(reg) \
    (((reg) & UART_CR1_RXNEIE_MASK) >> UART_CR1_RXNEIE_POS)


//
// UART_CR1_IDLEIE
//
#define UART_CR1_IDLEIE_POS     4
#define UART_CR1_IDLEIE_WIDTH   1
#define UART_CR1_IDLEIE_MASK    (0x1 << UART_CR1_IDLEIE_POS)

#define UART_CR1_SET_IDLEIE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_IDLEIE_MASK) | (((val) & 0x1) << UART_CR1_IDLEIE_POS); \
    } while (0)

#define UART_CR1_GET_IDLEIE(reg) \
    (((reg) & UART_CR1_IDLEIE_MASK) >> UART_CR1_IDLEIE_POS)


//
// UART_CR1_TE
//
#define UART_CR1_TE_POS         3
#define UART_CR1_TE_WIDTH       1
#define UART_CR1_TE_MASK        (0x1 << UART_CR1_TE_POS)

#define UART_CR1_SET_TE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_TE_MASK) | (((val) & 0x1) << UART_CR1_TE_POS); \
    } while (0)

#define UART_CR1_GET_TE(reg) \
    (((reg) & UART_CR1_TE_MASK) >> UART_CR1_TE_POS)


//
// UART_CR1_RE
//
#define UART_CR1_RE_POS         2
#define UART_CR1_RE_WIDTH       1
#define UART_CR1_RE_MASK        (0x1 << UART_CR1_RE_POS)

#define UART_CR1_SET_RE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_RE_MASK) | (((val) & 0x1) << UART_CR1_RE_POS); \
    } while (0)

#define UART_CR1_GET_RE(reg) \
    (((reg) & UART_CR1_RE_MASK) >> UART_CR1_RE_POS)


//
// UART_CR1_RWU
//
#define UART_CR1_RWU_POS        1
#define UART_CR1_RWU_WIDTH      1
#define UART_CR1_RWU_MASK       (0x1 << UART_CR1_RWU_POS)

#define UART_CR1_SET_RWU(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_RWU_MASK) | (((val) & 0x1) << UART_CR1_RWU_POS); \
    } while (0)

#define UART_CR1_GET_RWU(reg) \
    (((reg) & UART_CR1_RWU_MASK) >> UART_CR1_RWU_POS)


//
// UART_CR1_SBK
//
#define UART_CR1_SBK_POS        0
#define UART_CR1_SBK_WIDTH      1
#define UART_CR1_SBK_MASK       (0x1 << UART_CR1_SBK_POS)

#define UART_CR1_SET_SBK(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR1_SBK_MASK) | (((val) & 0x1) << UART_CR1_SBK_POS); \
    } while (0)

#define UART_CR1_GET_SBK(reg) \
    (((reg) & UART_CR1_SBK_MASK) >> UART_CR1_SBK_POS)


//
// UART_CR2_LINEN
//
#define UART_CR2_LINEN_POS       14
#define UART_CR2_LINEN_WIDTH     1
#define UART_CR2_LINEN_MASK      (0x1 << UART_CR2_LINEN_POS)

#define UART_CR2_SET_LINEN(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR2_LINEN_MASK) | (((val) & 0x1) << UART_CR2_LINEN_POS); \
    } while (0)

#define UART_CR2_GET_LINEN(reg) \
    (((reg) & UART_CR2_LINEN_MASK) >> UART_CR2_LINEN_POS)


//
// UART_CR2_STOP
//
#define UART_CR2_STOP_POS        12
#define UART_CR2_STOP_WIDTH      2
#define UART_CR2_STOP_MASK       (0x3 << UART_CR2_STOP_POS)

#define UART_CR2_SET_STOP(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR2_STOP_MASK) | (((val) & 0x3) << UART_CR2_STOP_POS); \
    } while (0)

#define UART_CR2_GET_STOP(reg) \
    (((reg) & UART_CR2_STOP_MASK) >> UART_CR2_STOP_POS)


//
// UART_CR2_CLKEN
//
#define UART_CR2_CLKEN_POS       11
#define UART_CR2_CLKEN_WIDTH     1
#define UART_CR2_CLKEN_MASK      (0x1 << UART_CR2_CLKEN_POS)

#define UART_CR2_SET_CLKEN(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR2_CLKEN_MASK) | (((val) & 0x1) << UART_CR2_CLKEN_POS); \
    } while (0)

#define UART_CR2_GET_CLKEN(reg) \
    (((reg) & UART_CR2_CLKEN_MASK) >> UART_CR2_CLKEN_POS)


//
// UART_CR2_CPOL
//
#define UART_CR2_CPOL_POS        10
#define UART_CR2_CPOL_WIDTH      1
#define UART_CR2_CPOL_MASK       (0x1 << UART_CR2_CPOL_POS)

#define UART_CR2_SET_CPOL(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR2_CPOL_MASK) | (((val) & 0x1) << UART_CR2_CPOL_POS); \
    } while (0)

#define UART_CR2_GET_CPOL(reg) \
    (((reg) & UART_CR2_CPOL_MASK) >> UART_CR2_CPOL_POS)


//
// UART_CR2_CPHA
//
#define UART_CR2_CPHA_POS        9
#define UART_CR2_CPHA_WIDTH      1
#define UART_CR2_CPHA_MASK       (0x1 << UART_CR2_CPHA_POS)

#define UART_CR2_SET_CPHA(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR2_CPHA_MASK) | (((val) & 0x1) << UART_CR2_CPHA_POS); \
    } while (0)

#define UART_CR2_GET_CPHA(reg) \
    (((reg) & UART_CR2_CPHA_MASK) >> UART_CR2_CPHA_POS)


//
// UART_CR2_LBCL
//
#define UART_CR2_LBCL_POS        8
#define UART_CR2_LBCL_WIDTH      1
#define UART_CR2_LBCL_MASK       (0x1 << UART_CR2_LBCL_POS)

#define UART_CR2_SET_LBCL(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR2_LBCL_MASK) | (((val) & 0x1) << UART_CR2_LBCL_POS); \
    } while (0)

#define UART_CR2_GET_LBCL(reg) \
    (((reg) & UART_CR2_LBCL_MASK) >> UART_CR2_LBCL_POS)


//
// UART_CR3_ONEBIT
//
#define UART_CR3_ONEBIT_POS     11
#define UART_CR3_ONEBIT_WIDTH   1
#define UART_CR3_ONEBIT_MASK    (0x1 << UART_CR3_ONEBIT_POS)

#define UART_CR3_SET_ONEBIT(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_ONEBIT_MASK) | (((val) & 0x1) << UART_CR3_ONEBIT_POS); \
    } while (0)

#define UART_CR3_GET_ONEBIT(reg) \
    (((reg) & UART_CR3_ONEBIT_MASK) >> UART_CR3_ONEBIT_POS)


//
// UART_CR3_CTSIE
//
#define UART_CR3_CTSIE_POS      10
#define UART_CR3_CTSIE_WIDTH    1
#define UART_CR3_CTSIE_MASK     (0x1 << UART_CR3_CTSIE_POS)

#define UART_CR3_SET_CTSIE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_CTSIE_MASK) | (((val) & 0x1) << UART_CR3_CTSIE_POS); \
    } while (0)

#define UART_CR3_GET_CTSIE(reg) \
    (((reg) & UART_CR3_CTSIE_MASK) >> UART_CR3_CTSIE_POS)


//
// UART_CR3_CTSE
//
#define UART_CR3_CTSE_POS       9
#define UART_CR3_CTSE_WIDTH     1
#define UART_CR3_CTSE_MASK      (0x1 << UART_CR3_CTSE_POS)

#define UART_CR3_SET_CTSE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_CTSE_MASK) | (((val) & 0x1) << UART_CR3_CTSE_POS); \
    } while (0)

#define UART_CR3_GET_CTSE(reg) \
    (((reg) & UART_CR3_CTSE_MASK) >> UART_CR3_CTSE_POS)


//
// UART_CR3_RTSE
//
#define UART_CR3_RTSE_POS       8
#define UART_CR3_RTSE_WIDTH     1
#define UART_CR3_RTSE_MASK      (0x1 << UART_CR3_RTSE_POS)

#define UART_CR3_SET_RTSE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_RTSE_MASK) | (((val) & 0x1) << UART_CR3_RTSE_POS); \
    } while (0)

#define UART_CR3_GET_RTSE(reg) \
    (((reg) & UART_CR3_RTSE_MASK) >> UART_CR3_RTSE_POS)


//
// UART_CR3_DMAT
//
#define UART_CR3_DMAT_POS       7
#define UART_CR3_DMAT_WIDTH     1
#define UART_CR3_DMAT_MASK      (0x1 << UART_CR3_DMAT_POS)

#define UART_CR3_SET_DMAT(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_DMAT_MASK) | (((val) & 0x1) << UART_CR3_DMAT_POS); \
    } while (0)

#define UART_CR3_GET_DMAT(reg) \
    (((reg) & UART_CR3_DMAT_MASK) >> UART_CR3_DMAT_POS)


//
// UART_CR3_DMAR
//
#define UART_CR3_DMAR_POS       6
#define UART_CR3_DMAR_WIDTH     1
#define UART_CR3_DMAR_MASK      (0x1 << UART_CR3_DMAR_POS)

#define UART_CR3_SET_DMAR(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_DMAR_MASK) | (((val) & 0x1) << UART_CR3_DMAR_POS); \
    } while (0)

#define UART_CR3_GET_DMAR(reg) \
    (((reg) & UART_CR3_DMAR_MASK) >> UART_CR3_DMAR_POS)


//
// UART_CR3_SCEN
//
#define UART_CR3_SCEN_POS       5
#define UART_CR3_SCEN_WIDTH     1
#define UART_CR3_SCEN_MASK      (0x1 << UART_CR3_SCEN_POS)

#define UART_CR3_SET_SCEN(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_SCEN_MASK) | (((val) & 0x1) << UART_CR3_SCEN_POS); \
    } while (0)

#define UART_CR3_GET_SCEN(reg) \
    (((reg) & UART_CR3_SCEN_MASK) >> UART_CR3_SCEN_POS)


//
// UART_CR3_NACK
//
#define UART_CR3_NACK_POS       4
#define UART_CR3_NACK_WIDTH     1
#define UART_CR3_NACK_MASK      (0x1 << UART_CR3_NACK_POS)

#define UART_CR3_SET_NACK(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_NACK_MASK) | (((val) & 0x1) << UART_CR3_NACK_POS); \
    } while (0)

#define UART_CR3_GET_NACK(reg) \
    (((reg) & UART_CR3_NACK_MASK) >> UART_CR3_NACK_POS)


//
// UART_CR3_HDSEL
//
#define UART_CR3_HDSEL_POS      3
#define UART_CR3_HDSEL_WIDTH    1
#define UART_CR3_HDSEL_MASK     (0x1 << UART_CR3_HDSEL_POS)

#define UART_CR3_SET_HDSEL(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_HDSEL_MASK) | (((val) & 0x1) << UART_CR3_HDSEL_POS); \
    } while (0)

#define UART_CR3_GET_HDSEL(reg) \
    (((reg) & UART_CR3_HDSEL_MASK) >> UART_CR3_HDSEL_POS)


//
// UART_CR3_IRLP
//
#define UART_CR3_IRLP_POS       2
#define UART_CR3_IRLP_WIDTH     1
#define UART_CR3_IRLP_MASK      (0x1 << UART_CR3_IRLP_POS)

#define UART_CR3_SET_IRLP(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_IRLP_MASK) | (((val) & 0x1) << UART_CR3_IRLP_POS); \
    } while (0)

#define UART_CR3_GET_IRLP(reg) \
    (((reg) & UART_CR3_IRLP_MASK) >> UART_CR3_IRLP_POS)


//
// UART_CR3_IREN
//
#define UART_CR3_IREN_POS       1
#define UART_CR3_IREN_WIDTH     1
#define UART_CR3_IREN_MASK      (0x1 << UART_CR3_IREN_POS)

#define UART_CR3_SET_IREN(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_IREN_MASK) | (((val) & 0x1) << UART_CR3_IREN_POS); \
    } while (0)

#define UART_CR3_GET_IREN(reg) \
    (((reg) & UART_CR3_IREN_MASK) >> UART_CR3_IREN_POS)


//
// UART_CR3_EIE
//
#define UART_CR3_EIE_POS        0
#define UART_CR3_EIE_WIDTH      1
#define UART_CR3_EIE_MASK       (0x1 << UART_CR3_EIE_POS)

#define UART_CR3_SET_EIE(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_CR3_EIE_MASK) | (((val) & 0x1) << UART_CR3_EIE_POS); \
    } while (0)

#define UART_CR3_GET_EIE(reg) \
    (((reg) & UART_CR3_EIE_MASK) >> UART_CR3_EIE_POS)


//
// UART_GTPR_GT (Guard Time)
//
#define UART_GTPR_GT_POS       8
#define UART_GTPR_GT_WIDTH     8
#define UART_GTPR_GT_MASK      (0xFF << UART_GTPR_GT_POS)

#define UART_GTPR_SET_GT(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_GTPR_GT_MASK) | (((val) & 0xFF) << UART_GTPR_GT_POS); \
    } while (0)

#define UART_GTPR_GET_GT(reg) \
    (((reg) & UART_GTPR_GT_MASK) >> UART_GTPR_GT_POS)


//
// UART_GTPR_PSC (Prescaler)
//
#define UART_GTPR_PSC_POS      0
#define UART_GTPR_PSC_WIDTH    8
#define UART_GTPR_PSC_MASK     (0xFF << UART_GTPR_PSC_POS)

#define UART_GTPR_SET_PSC(reg, val) \
    do { \
        (reg) = ((reg) & ~UART_GTPR_PSC_MASK) | (((val) & 0xFF) << UART_GTPR_PSC_POS); \
    } while (0)

#define UART_GTPR_GET_PSC(reg) \
    (((reg) & UART_GTPR_PSC_MASK) >> UART_GTPR_PSC_POS)


#endif // UART_REGS_H
