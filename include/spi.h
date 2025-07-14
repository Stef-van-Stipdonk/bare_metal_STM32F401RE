#ifndef SPI_H
#define SPI_H 1

#include <stdint.h>

struct spi_t;

uint8_t Spi_init(struct spi_t* peripheral);

#endif // SPI_H
