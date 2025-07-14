#ifndef SPI_REGS_H
#define SPI_REGS_H 1

#include <stdint.h>

struct spi_t {
    volatile uint32_t CR1;      // Control Register 1
    volatile uint32_t CR2;      // Control Register 2
    volatile uint32_t SR;       // Status Register
    volatile uint32_t DR;       // Data Register
    volatile uint32_t CRCPR;    // CRC Polynomial Register
    volatile uint32_t RXCRCR;   // RX CRC Register
    volatile uint32_t TXCRCR;   // TX CRC Register
    volatile uint32_t I2SCFGR;  // I2S Configuration Register
    volatile uint32_t I2SPR;    // I2S Prescaler Register
} __attribute__((packed));

#define SPI1 ((struct spi_t *) 0x40013400)
#define SPI2 ((struct spi_t *) 0x40003800)
#define SPI3 ((struct spi_t *) 0x40003C00)
#define SPI4 ((struct spi_t *) 0x40013000)


#define SPI_CR1_CPHA_FIRST_CLOCK_TRANSITION_IS_DATA_CAPTURE (0U << 0)
#define SPI_CR1_CPHA_SECOND_CLOCK_TRANSITION_IS_DATA_CAPTURE (1U << 0)

#define SPI_CR1_CPOL_CK_0_WHEN_IDLE    (0U << 1)
#define SPI_CR1_CPOL_CK_1_WHEN_IDLE    (1U << 1)

#define SPI_CR1_MSTR_IS_SLAVE    (0U << 2)
#define SPI_CR1_MSTR_IS_MASTER    (1U << 2)

#define SPI_CR1_BR_DIV_2    (0b000U << 3)
#define SPI_CR1_BR_DIV_4    (0b001U << 3)
#define SPI_CR1_BR_DIV_8    (0b010U << 3)
#define SPI_CR1_BR_DIV_16   (0b011U << 3)
#define SPI_CR1_BR_DIV_32   (0b100U << 3)
#define SPI_CR1_BR_DIV_64   (0b101U << 3)
#define SPI_CR1_BR_DIV_128  (0b110U << 3)
#define SPI_CR1_BR_DIV_256  (0b111U << 3)

#define SPI_CR1_SPE_SPI_ENABLE    (1U << 2)
#define SPI_CR1_SPE_SPI_DISABLED    (0U << 2)

#define SPI_CR1_LSBFIRST_MSB    (0U << 7)
#define SPI_CR1_LSBFIRST_LSB    (1U << 7)

#define SPI_CR1_SSM_SLAVE_MANAGEMENT_ENABLE    (1U << 9)
#define SPI_CR1_SSM_SLAVE_MANAGEMENT_DISABLED    (0U << 9)

#define SPI_CR1_RXONLY_RECEIVE_ONLY_FULL_DUPLEX   (0U << 10)
#define SPI_CR1_RXONLY_RECEIVE_ONLY_OUTPUT_DISABLED   (1U << 10)

#define SPI_CR1_DFF_8_BIT_DATA_FRAME   (0U << 11)
#define SPI_CR1_DFF_16_BIT_DATA_FRAME   (1U << 11)

#define SPI_CR1_CRCNEXT_DATA_PHASE   (1U << 12)
#define SPI_CR1_CRCNEXT_NEXT_TRANSFER_IS_CRC   (1U << 12)

#define SPI_CR1_CRCEN_CRC_CALC_DISABLED   (0U << 13)
#define SPI_CR1_CRCEN_CRC_CALC_ENABLE   (1U << 13)

#define SPI_CR1_DIDIOE_DISABLED   (0U << 14)
#define SPI_CR1_DIDIOE_ENABLE   (1U << 14)

#define SPI_CR1_DIDIMODE_2_LINE_UNIDIRECTIONAL   (1U << 15)
#define SPI_CR1_DIDIMODE_1_LINE_BIDIRECTIONAL   (1U << 15)

#define SPI_CR2_RXDMAEN_DMA_DISABLED   (0U << 0)
#define SPI_CR2_RXDMAEN_DMA_ENABLE   (1U << 0)

#define SPI_CR2_TXDMAEN_DMA_DISABLED   (0U << 1)
#define SPI_CR2_TXDMAEN_DMA_ENABLE   (1U << 1)

#define SPI_CR2_SSOE_SS_OUTPUT_DISABLED   (1U << 2)
#define SPI_CR2_SSOE_SS_OUTPUT_ENABLE   (1U << 2)

#define SPI_CR2_FRF_FRAME_FORMAT_MOTOROLA   (0U << 4)
#define SPI_CR2_FRF_FRAME_FORMAT_TI   (1U << 4)

#define SPI_CR2_ERRIE_ERROR_INTERRUPT_DISABLED   (0U << 5)
#define SPI_CR2_ERRIE_ERROR_INTERRUPT_ENABLE   (1U << 5)

#define SPI_CR2_RXNEI_BUFFER_NOT_EMPTY_INT_DISABLE   (0U << 6)
#define SPI_CR2_RXNEI_BUFFER_NOT_EMPTY_INT_ENABLE   (1U << 6)

#define SPI_CR2_TXEIE_BUFFER_EMPTY_INT_DISABLE   (0U << 7)
#define SPI_CR2_TXEIE_BUFFER_EMPTY_INT_ENABLE   (1U << 7)

#endif // SPI_REGS_H
