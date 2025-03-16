#include "gpio.h"
#include "rcc.h"
#include <stdint.h>

int main(void) {
	uint16_t led = PIN('A', 5);
	RCC->AHB1ENR = BIT(PINBANK(led));
	gpio_set_mode(led, GPIO_MODE_OUTPUT);
	for (;;) {}
	return 0;
}

__attribute__((naked, noreturn)) void _reset(void) {
  extern long _sbss, _ebss, _sdata, _edata, _sidata;
  for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;
  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;

  main();             // Call main()
  for (;;) (void) 0;  // Infinite loop in the case if main() returns
}
extern void _estack(void);

__attribute__((section(".vectors"))) void (* const tab[16 + 91])(void) = {
	_estack, _reset
};
