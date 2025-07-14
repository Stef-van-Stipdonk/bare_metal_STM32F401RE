#include "spi.h"
#include "spi_regs.h"

/*
1. Select the BR[2:0] bits to define the serial clock baud rate (see SPI_CR1 register).

2. Select the CPOL and CPHA bits to define one of the four relationships between the
data transfer and the serial clock (see Figure 194). This step is not required when the
TI mode is selected.

3. Set the DFF bit to define 8- or 16-bit data frame format

4. Configure the LSBFIRST bit in the SPI_CR1 register to define the frame format. This
step is not required when the TI mode is selected.

5. If the NSS pin is required in input mode, in hardware mode, connect the NSS pin to a
high-level signal during the complete byte transmit sequence. In NSS software mode,
set the SSM and SSI bits in the SPI_CR1 register. If the NSS pin is required in output
mode, the SSOE bit only should be set. This step is not required when the TI mode is
selected.

6. Set the FRF bit in SPI_CR2 to select the TI protocol for serial communications.

7. The MSTR and SPE bits must be set (they remain set only if the NSS pin is connected
to a high-level signal).
*/
uint8_t Spi_init(struct spi_t* peripheral) {
    peripheral->CR1 &= ~SPI_CR1_BR_DIV_2;
    peripheral->CR1 &= ~SPI_CR1_CPHA_FIRST_CLOCK_TRANSITION_IS_DATA_CAPTURE;
    peripheral->CR1 &= ~SPI_CR1_CPOL_CK_0_WHEN_IDLE;
    peripheral->CR1 &= ~SPI_CR1_DFF_8_BIT_DATA_FRAME;
    peripheral->CR1 &= ~SPI_CR1_LSBFIRST_MSB;
    peripheral->CR2 &= ~SPI_CR2_FRF_FRAME_FORMAT_MOTOROLA;
    peripheral->CR1 &= ~SPI_CR1_MSTR_IS_MASTER;
    peripheral->CR1 &= ~SPI_CR1_SPE_SPI_ENABLE;

    __asm("nop\nnop\nnop\nnop\nnop\nnop");

    return 0;
}
