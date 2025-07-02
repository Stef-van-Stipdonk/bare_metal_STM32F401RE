#include "nvic.h"
#include "nvic_regs.h"

void nvic_enable_irq(uint32_t IRQ_number) {
    NVIC->ISER[(((uint32_t)IRQ_number) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQ_number) & 0x1FUL));
}
