#ifndef COMMON_DEFINES_H
#define COMMON_DEFINES_H 1

#define BIT(x) (1UL << (x))
#define GPIO(bank) ((struct gpio_t *) (0x40020000 + 0x400 * (bank)))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (uint8_t)(pin & 255)
#define PINBANK(pin) (pin >> 8)

#define INITIAL_CPU_FREQ 16000000 // 16 Mhz
#define APB1_MAX_FREQ 42000000 // 42 Mhz
#define APB2_MAX_FREQ 84000000 // 42 Mhz
#define AHB1_MAX_FREQ 84000000 // 84 Mhz
#define AHB2_MAX_FREQ 84000000 // 84 Mhz

#endif // COMMON_DEFINES_H
