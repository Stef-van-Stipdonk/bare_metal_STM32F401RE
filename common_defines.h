#ifndef COMMON_DEFINES_H
#define COMMON_DEFINES_H 1

#define BIT(x) (1UL << (x))
#define GPIO(bank) ((struct gpio_t *) (0x40020000 + 0x400 * (bank)))
#define PIN(bank, num) ((((bank) - 'A') << 8) | (num))
#define PINNO(pin) (uint8_t)(pin & 255)
#define PINBANK(pin) (pin >> 8)


#define FREQ 16000000 // 16 Mhz

#endif // COMMON_DEFINES_H
