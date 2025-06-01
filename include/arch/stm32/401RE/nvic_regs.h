#ifndef NVIC_REGS_H
#define NVIC_REGS_H 1

#include <stdint.h>

struct nvic_t {
	volatile uint32_t ISER[8]; // Interrupt set-enable registers
	volatile uint32_t ICER[8]; // Interrupt clear-enable registers
} __attribute__((packed));

extern struct nvic_t *NVIC;

#endif // NVIC_REGS_H
