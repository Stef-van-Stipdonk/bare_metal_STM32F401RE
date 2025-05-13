#include <stdint.h>
#ifndef FLASH_H
#define FLASH_H 1

#define FLASH_ACR_LATENCY_0WS (0 << 0)
#define FLASH_ACR_LATENCY_1WS (1 << 0)
#define FLASH_ACR_LATENCY_2WS (1 << 1)

#define FLASH_ACR_PRFTEN (1 << 8)	// enable Prefetch
#define FLASH_ACR_ICEN (1 << 9)		// enable instruction cache
#define FLASH_ACR_DCEN (1 << 10)	// enable data cache

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
