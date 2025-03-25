#include <stdint.h>
#ifndef NVIC_H
#define NVIC_H 1

struct nvic_t {
	volatile uint32_t ISER0; // Interrupt set-enable register 0
	volatile uint32_t ISER1; // Interrupt set-enable register 1
	volatile uint32_t ISER2; // Interrupt set-enable register 2
	volatile uint32_t ISER3; // Interrupt set-enable register 3
	volatile uint32_t ISER4; // Interrupt set-enable register 4
	volatile uint32_t ISER5; // Interrupt set-enable register 5
	volatile uint32_t ISER6; // Interrupt set-enable register 6
	volatile uint32_t ISER7; // Interrupt set-enable register 7

	volatile uint32_t ICER0; // Interrupt clear-enable register 0
	volatile uint32_t ICER1; // Interrupt clear-enable register 1
	volatile uint32_t ICER2; // Interrupt clear-enable register 2
	volatile uint32_t ICER3; // Interrupt clear-enable register 3
	volatile uint32_t ICER4; // Interrupt clear-enable register 4
	volatile uint32_t ICER5; // Interrupt clear-enable register 5
	volatile uint32_t ICER6; // Interrupt clear-enable register 6
	volatile uint32_t ICER7; // Interrupt clear-enable register 7

	volatile uint32_t ISPR0; // Interrupt set-pending registrer 0
	volatile uint32_t ISPR1; // Interrupt set-pending registrer 1
	volatile uint32_t ISPR2; // Interrupt set-pending registrer 2
	volatile uint32_t ISPR3; // Interrupt set-pending registrer 3
	volatile uint32_t ISPR4; // Interrupt set-pending registrer 4
	volatile uint32_t ISPR5; // Interrupt set-pending registrer 5
	volatile uint32_t ISPR6; // Interrupt set-pending registrer 6
	volatile uint32_t ISPR7; // Interrupt set-pending registrer 7

	volatile uint32_t ICPR0; // Interrupt clear-pending register 0
	volatile uint32_t ICPR1; // Interrupt clear-pending register 1
	volatile uint32_t ICPR2; // Interrupt clear-pending register 2
	volatile uint32_t ICPR3; // Interrupt clear-pending register 3
	volatile uint32_t ICPR4; // Interrupt clear-pending register 4
	volatile uint32_t ICPR5; // Interrupt clear-pending register 5
	volatile uint32_t ICPR6; // Interrupt clear-pending register 6
	volatile uint32_t ICPR7; // Interrupt clear-pending register 7

	volatile uint32_t IABR0; // Interrupt active bit register 0
	volatile uint32_t IABR1; // Interrupt active bit register 1
	volatile uint32_t IABR2; // Interrupt active bit register 2
	volatile uint32_t IABR3; // Interrupt active bit register 3
	volatile uint32_t IABR4; // Interrupt active bit register 4
	volatile uint32_t IABR5; // Interrupt active bit register 5
	volatile uint32_t IABR6; // Interrupt active bit register 6
	volatile uint32_t IABR7; // Interrupt active bit register 7

	volatile uint32_t IPR0; // Interrupt priority register 0
	volatile uint32_t IPR1; // Interrupt priority register 1
	volatile uint32_t IPR2; // Interrupt priority register 2
	volatile uint32_t IPR3; // Interrupt priority register 3
	volatile uint32_t IPR4; // Interrupt priority register 4
	volatile uint32_t IPR5; // Interrupt priority register 5
	volatile uint32_t IPR6; // Interrupt priority register 6
	volatile uint32_t IPR7; // Interrupt priority register 7
	volatile uint32_t IPR8; // Interrupt priority register 8
	volatile uint32_t IPR9; // Interrupt priority register 9
	volatile uint32_t IPR10; // Interrupt priority register 10
	volatile uint32_t IPR11; // Interrupt priority register 11
	volatile uint32_t IPR12; // Interrupt priority register 12
	volatile uint32_t IPR13; // Interrupt priority register 13
	volatile uint32_t IPR14; // Interrupt priority register 14
	volatile uint32_t IPR15; // Interrupt priority register 15
	volatile uint32_t IPR16; // Interrupt priority register 16
	volatile uint32_t IPR17; // Interrupt priority register 17
	volatile uint32_t IPR18; // Interrupt priority register 18
	volatile uint32_t IPR19; // Interrupt priority register 19
	volatile uint32_t IPR20; // Interrupt priority register 20
	volatile uint32_t IPR21; // Interrupt priority register 21
	volatile uint32_t IPR22; // Interrupt priority register 22
	volatile uint32_t IPR23; // Interrupt priority register 23
	volatile uint32_t IPR24; // Interrupt priority register 24
	volatile uint32_t IPR25; // Interrupt priority register 25
	volatile uint32_t IPR26; // Interrupt priority register 26
	volatile uint32_t IPR27; // Interrupt priority register 27
	volatile uint32_t IPR28; // Interrupt priority register 28
	volatile uint32_t IPR29; // Interrupt priority register 29
	volatile uint32_t IPR30; // Interrupt priority register 30
	volatile uint32_t IPR31; // Interrupt priority register 31
	volatile uint32_t IPR32; // Interrupt priority register 32
	volatile uint32_t IPR33; // Interrupt priority register 33
	volatile uint32_t IPR34; // Interrupt priority register 34
	volatile uint32_t IPR35; // Interrupt priority register 35
	volatile uint32_t IPR36; // Interrupt priority register 36
	volatile uint32_t IPR37; // Interrupt priority register 37
	volatile uint32_t IPR38; // Interrupt priority register 38
	volatile uint32_t IPR39; // Interrupt priority register 39
	volatile uint32_t IPR40; // Interrupt priority register 40
	volatile uint32_t IPR41; // Interrupt priority register 41
	volatile uint32_t IPR42; // Interrupt priority register 42
	volatile uint32_t IPR43; // Interrupt priority register 43
	volatile uint32_t IPR44; // Interrupt priority register 44
	volatile uint32_t IPR45; // Interrupt priority register 45
	volatile uint32_t IPR46; // Interrupt priority register 46
	volatile uint32_t IPR47; // Interrupt priority register 47
	volatile uint32_t IPR48; // Interrupt priority register 48
	volatile uint32_t IPR49; // Interrupt priority register 49
	volatile uint32_t IPR50; // Interrupt priority register 50
	volatile uint32_t IPR51; // Interrupt priority register 51
	volatile uint32_t IPR52; // Interrupt priority register 52
	volatile uint32_t IPR53; // Interrupt priority register 53
	volatile uint32_t IPR54; // Interrupt priority register 54
	volatile uint32_t IPR55; // Interrupt priority register 55
	volatile uint32_t IPR56; // Interrupt priority register 56
	volatile uint32_t IPR57; // Interrupt priority register 57
	volatile uint32_t IPR58; // Interrupt priority register 58
	volatile uint32_t IPR59; // Interrupt priority register 59
};

#define NVIC ((struct nvic_t *)0xE000E100);

#endif // NVIC_H
