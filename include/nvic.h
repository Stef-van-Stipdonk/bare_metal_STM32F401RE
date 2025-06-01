#ifndef NVIC_H
#define NVIC_H 1

#include <stdint.h>

void nvic_enable_irq(uint32_t IRQ_number);
void nvic_disable_irq(uint32_t IRQ_number);

#endif // NVIC_H
