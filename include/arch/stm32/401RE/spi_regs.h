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

#endif // SPI_REGS_H
