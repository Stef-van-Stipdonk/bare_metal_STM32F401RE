
#include "rcc.h"
#include "rcc_regs.h"

void rcc_init() {
	RCC->CR |= RCC_CR_HSION; // Enable to HSI

	while (!(RCC->CR & RCC_CR_HSIRDY)) // Wait for HSI to be ready
		;

	uint32_t reg_mask;
	reg_mask = RCC->CFGR;
	reg_mask &= ~((1U << 1) | (1U << 0));
	RCC->CFGR = (reg_mask | RCC_CFGR_SW_HSI);

	reg_mask = RCC->CFGR;
	reg_mask &= ~((1U << 4) | (1U << 5) | (1U << 6) | (1U << 7));
	RCC->CFGR = (reg_mask | RCC_CFGR_HPRE_NODIV << 4);

	reg_mask = RCC->CFGR;
	reg_mask &= ~((1U << 10) | (1U << 11) | (1U << 12));
	RCC->CFGR = (reg_mask | RCC_CFGR_PPRE_DIV2 << 10);

	reg_mask = RCC->CFGR;
	reg_mask &= ~((1U << 13) | (1U << 14) | (1U << 15));
	RCC->CFGR = (reg_mask | RCC_CFGR_PPRE_NODIV << 13);

	RCC->CR &= ~RCC_CR_PLLON;

	while (RCC->CR & RCC_CR_PLLRDY)
		;

	// PLLM = 16
	// PLLN = 336
	// PLLP = 0b01 (which is 4 in the datasheet)
	// HSI  = 16 Mhz
	// (HSI / PLLM) * PLLN / PLLP = SYCLK
	RCC->PLLCFGR = 0			// Means Default HSI
		| 16 << RCC_PLLCFGR_PLLM_POS	// Set PLLM
		| 336 << RCC_PLLCFGR_PLLN_POS	// Set PLLN
		| 0b01 << RCC_PLLCFGR_PLLP_POS	// Set PLLP
		| 7 << RCC_PLLCFGR_PLLQ_POS	// Set PLLQ
		| 0 << RCC_PLLCFGR_PLLR_POS;	// Set PLLR

	RCC->CR |= RCC_CR_PLLON; // Enable PLL

	while (!(RCC->CR & RCC_CR_PLLRDY)) // Wait for PLL to be ready
		;

	FLASH->ACR
		|= FLASH_ACR_LATENCY_2WS // Based on 84 Mhz clock
		| FLASH_ACR_PRFTEN
		| FLASH_ACR_ICEN
		| FLASH_ACR_DCEN;

	reg_mask = RCC->CFGR;
	reg_mask &= ~((1U << 1) | (1U << 0));
	RCC->CFGR = (reg_mask | RCC_CFGR_SW_PLL); // Set PLL as the system clock source

	while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) // Wait for PLL to be set as the clock source
		;
}
