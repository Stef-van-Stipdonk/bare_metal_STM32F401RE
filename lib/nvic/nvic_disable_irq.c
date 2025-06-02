#include "nvic.h"
#include "nvic_regs.h"

void nvic_disable_irq(uint32_t IRQ_number) {
    NVIC->ICER[(((uint32_t)IRQ_number) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQ_number) & 0x1FUL));
}
