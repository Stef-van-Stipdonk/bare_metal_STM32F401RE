#include "spi.h"
#include "spi_regs.h"
#include "rcc_regs.h"
#include "common_defines.h"
#include "gpio.h"
#include <stdint.h>

uint8_t Spi_Init(struct spi_t* peripheral) {
    
    RCC->APB2ENR |= BIT(12);

    __asm("nop\nnop\nnop\nnop\nnop\nnop");
    
    uint8_t af = 5;
    
    uint16_t sck = PIN('A', 5); 
    gpio_set_mode(sck, GPIO_MODE_AF);
    gpio_set_af(sck, af);

    uint16_t mosi = PIN('A', 7);
    gpio_set_mode(mosi, GPIO_MODE_AF);
    gpio_set_af(mosi, af);

    peripheral->CR1 |= SPI_CR1_BR_DIV_2;
    peripheral->CR1 |= SPI_CR1_CPHA_FIRST_CLOCK_TRANSITION_IS_DATA_CAPTURE;
    peripheral->CR1 |= SPI_CR1_CPOL_CK_0_WHEN_IDLE;
    peripheral->CR1 |= SPI_CR1_DFF_8_BIT_DATA_FRAME;
    peripheral->CR1 |= SPI_CR1_LSBFIRST_MSB;
    peripheral->CR2 |= SPI_CR2_FRF_FRAME_FORMAT_MOTOROLA;
    peripheral->CR1 |= SPI_CR1_MSTR_IS_MASTER;
    peripheral->CR1 |= SPI_CR1_SPE_SPI_ENABLE;

    __asm("nop\nnop\nnop\nnop\nnop\nnop");

    return 0;
}
