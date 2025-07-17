#include "spi.h"
#include "spi_regs.h"
#include "common.h"
#include "common_defines.h"
#include <stdint.h>


void Spi_WriteByte(struct spi_t* peripheral, uint8_t data) {
    while (peripheral->SR & BIT(1)) {
        spin(1);
    }
    
    peripheral->DR = data;
}
