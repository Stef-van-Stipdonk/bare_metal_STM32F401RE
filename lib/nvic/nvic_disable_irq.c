#include "nvic.h"
#include "nvic_regs.h"

#define ICER0_BOUNDARY 31
#define ICER1_BOUNDARY (ICER0_BOUNDARY + 32)
#define ICER2_BOUNDARY (ICER1_BOUNDARY + 32)
#define ICER3_BOUNDARY (ICER2_BOUNDARY + 32)
#define ICER4_BOUNDARY (ICER3_BOUNDARY + 32)
#define ICER5_BOUNDARY (ICER4_BOUNDARY + 32)
#define ICER6_BOUNDARY (ICER5_BOUNDARY + 32)
#define ICER7_BOUNDARY (ICER6_BOUNDARY + 32)

void nvic_disable_irq(uint32_t IRQ_number) {
	if (IRQ_number > ICER7_BOUNDARY) {
		return;
	}

	if (IRQ_number < ICER0_BOUNDARY) {
		NVIC->ICER[0] = (1 << IRQ_number);
	}
	else if (IRQ_number < ICER1_BOUNDARY) {
		NVIC->ICER[1] = (1 << (IRQ_number - ICER0_BOUNDARY));
	}
	else if (IRQ_number < ICER2_BOUNDARY) {
		NVIC->ICER[2] = (1 << (IRQ_number - ICER1_BOUNDARY));
	}
	else if (IRQ_number < ICER3_BOUNDARY) {
		NVIC->ICER[3] = (1 << (IRQ_number - ICER2_BOUNDARY));
	}
	else if (IRQ_number < ICER4_BOUNDARY) {
		NVIC->ICER[4] = (1 << (IRQ_number - ICER3_BOUNDARY));
	}
	else if (IRQ_number < ICER5_BOUNDARY) {
		NVIC->ICER[5] = (1 << (IRQ_number - ICER4_BOUNDARY));
	}
	else if (IRQ_number < ICER6_BOUNDARY) {
		NVIC->ICER[6] = (1 << (IRQ_number - ICER5_BOUNDARY));
	}
	else if (IRQ_number < ICER7_BOUNDARY) {
		if (IRQ_number > ICER7_BOUNDARY + 15) { // bits 16 to 31 are reserved
			return;
		}

		NVIC->ICER[7] = (1 << (IRQ_number - ICER6_BOUNDARY));
	}
}
