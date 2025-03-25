#ifndef RCC_H
#define RCC_H 1

// Purpose:
// header file for the reset and clock control (RCC)

#include <stdint.h>

struct rcc_t {
	volatile uint32_t CR;		// Control Register
	volatile uint32_t PLLCFGR;	// PLL Configuration Register
	volatile uint32_t CFGR;		// Clock Configuration Register
	volatile uint32_t CIR;		// Clock Interrupt Register
	volatile uint32_t AHB1RSTR;	// AHB1 Peripheral Reset Register
	volatile uint32_t AHB2RSTR;	// AHB2 Peripheral Reset Register

	uint32_t : 32;			// RESERVED SPACE
	uint32_t : 32;			// RESERVED SPACE

	volatile uint32_t APB1RSTR;	// APB1 Peripheral Reset Register
	volatile uint32_t APB2RSTR;	// APB2 Peripheral Reset Register

	uint32_t : 32;			// RESERVED SPACE
	uint32_t : 32;			// RESERVED SPACE

	volatile uint32_t AHB1ENR;	// AHB1 Peripheral Clock Enable Register
	volatile uint32_t AHB2ENR;	// AHB2 Peripheral Clock Enable Register

	uint32_t : 32;			// RESERVED SPACE
	uint32_t : 32;			// RESERVED SPACE

	volatile uint32_t APB1ENR;	// APB1 Peripheral Clock Enable Register
	volatile uint32_t APB2ENR;	// APB2 Peripheral Clock Enable Register

	uint32_t : 32;			// RESERVED SPACE
	uint32_t : 32;			// RESERVED SPACE

	volatile uint32_t AHB1LPENR;	// AHB1 Peripheral Clock Enable in Low Power Mode Register
	volatile uint32_t AHB2LPENR;	// AHB2 Peripheral Clock Enable in Low Power Mode Register

	uint32_t : 32;			// RESERVED SPACE
	uint32_t : 32;			// RESERVED SPACE

	volatile uint32_t APB1LPENR;	// APB1 Peripheral Clock Enable in Low Power Mode Register
	volatile uint32_t APB2LPENR;	// APB2 Peripheral Clock Enabled in Low Power Mode Register

	uint32_t : 32;			// RESERVED SPACE
	uint32_t : 32;			// RESERVED SPACE

	volatile uint32_t BDCR;		// Backup Domain Control Register
	volatile uint32_t CSR;		// Clock Control & Status Register

	uint32_t : 32;			// RESERVED SPACE
	uint32_t : 32;			// RESERVED SPACE

	volatile uint32_t SSCGR;	// Spread Spectrum Clock Generation Register
	volatile uint32_t PLLI2SCFGR;	// PLLI2S Configuration Register

	uint32_t : 32;			// RESERVED SPACE

	volatile uint32_t DCKCFGR;	// Dedicated Clocks Configuration Register
};

#define RCC ((struct rcc_t *) 0x40023800)

#define RCC_APB2ENR_SYSCFGEN BIT(14)

#endif // RCC_H
