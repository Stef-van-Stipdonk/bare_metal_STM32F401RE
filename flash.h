#include <stdint.h>
#ifndef FLASH_H
#define FLASH_H 1

struct flash_t {
	volatile uint32_t ACR;		// Flash acces control register
	volatile uint32_t KEYR;		// Flash key register
	volatile uint32_t OPTKEYR;	// Flash option key register
	volatile uint32_t SR;		// Flash status register
	volatile uint32_t CR;		// Flash control register
	volatile uint32_t OPTCR;	// Flash option control register
};

#define FLASH ((struct flash_t *) 0x40023C00)

#endif // FLASH_H
