#include "circular_buffer.h"
#ifndef SPI_H
#define SPI_H 1

#include <stdint.h>

struct spi_t;

uint8_t Spi_Init(struct spi_t* peripheral);

void Spi_WriteByte(struct spi_t* peripheral, uint8_t data);

#endif // SPI_H
