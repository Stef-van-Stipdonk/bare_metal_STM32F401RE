#include "nvic.h"
#include "nvic_regs.h"

#define ISER0_BOUNDARY 31
#define ISER1_BOUNDARY (ISER0_BOUNDARY + 32)
#define ISER2_BOUNDARY (ISER1_BOUNDARY + 32)
#define ISER3_BOUNDARY (ISER2_BOUNDARY + 32)
#define ISER4_BOUNDARY (ISER3_BOUNDARY + 32)
#define ISER5_BOUNDARY (ISER4_BOUNDARY + 32)
#define ISER6_BOUNDARY (ISER5_BOUNDARY + 32)
#define ISER7_BOUNDARY (ISER6_BOUNDARY + 32)

void nvic_enable_irq(uint32_t IRQ_number) {
	if (IRQ_number > ISER7_BOUNDARY) {
		return;
	}

	if (IRQ_number < ISER0_BOUNDARY) {
		NVIC->ISER[0] = (1 << IRQ_number);
	}
	else if (IRQ_number < ISER1_BOUNDARY) {
		NVIC->ISER[1] = (1 << (IRQ_number - ISER0_BOUNDARY));
	}
	else if (IRQ_number < ISER2_BOUNDARY) {
		NVIC->ISER[2] = (1 << (IRQ_number - ISER1_BOUNDARY));
	}
	else if (IRQ_number < ISER3_BOUNDARY) {
		NVIC->ISER[3] = (1 << (IRQ_number - ISER2_BOUNDARY));
	}
	else if (IRQ_number < ISER4_BOUNDARY) {
		NVIC->ISER[4] = (1 << (IRQ_number - ISER3_BOUNDARY));
	}
	else if (IRQ_number < ISER5_BOUNDARY) {
		NVIC->ISER[5] = (1 << (IRQ_number - ISER4_BOUNDARY));
	}
	else if (IRQ_number < ISER6_BOUNDARY) {
		NVIC->ISER[6] = (1 << (IRQ_number - ISER5_BOUNDARY));
	}
	else if (IRQ_number < ISER7_BOUNDARY) {
		if (IRQ_number > ISER7_BOUNDARY + 15) { // bits 16 to 31 are reserved
			return;
		}

		NVIC->ISER[7] = (1 << (IRQ_number - ISER6_BOUNDARY));
	}
}
