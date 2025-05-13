#ifndef RCC_H
#define RCC_H 1

// Purpose:
// header file for the reset and clock control (RCC)

#include <stdint.h>

#define RCC_CR_HSION (1U << 0)
#define RCC_CR_HSIRDY (1U << 1)
#define RCC_CR_PLLON (1U << 24)
#define RCC_CR_PLLRDY (1U << 25)

#define RCC_CFGR_SW_HSI (0b00 << 0)
#define RCC_CFGR_SW_HSE (0b01 << 0)
#define RCC_CFGR_SW_PLL (0b10 << 0)

#define RCC_CFGR_HPRE_NODIV 0
#define RCC_CFGR_PPRE_NODIV 0
#define RCC_CFGR_PPRE_DIV2 4

#define RCC_CFGR_SWS_HSI (0b00 << 2)
#define RCC_CFGR_SWS_HSE (0b01 << 2)
#define RCC_CFGR_SWS_PLL (0b10 << 2)

#define RCC_PLLCFGR_PLLM_POS 0
#define RCC_PLLCFGR_PLLN_POS 6
#define RCC_PLLCFGR_PLLP_POS 16
#define RCC_PLLCFGR_PLLQ_POS 24
#define RCC_PLLCFGR_PLLR_POS 28
#define RCC_PLLCFGR_PLLSRC_HSI (0 << 22)
#define RCC_PLLCFGR_PLLSRC_HSE (1 << 22)

#define RCC_APB2ENR_SYSCFGEN BIT(14)

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


#endif // RCC_H
