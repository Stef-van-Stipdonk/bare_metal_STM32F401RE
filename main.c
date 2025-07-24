#include "nvic.h"
#include "rcc.h"
#include "systick.h"
#include "uart.h"
#include "flash.h"
#include "uart_regs.h"
#include "circular_buffer.h"
#include <stdint.h>

extern volatile struct circular_buffer uart_receive_buffer;

static uint32_t r[16];
static uint32_t cpsr;

void IRQ_HardFaultHandler() { 
    asm volatile (
        "mov %[r0], r0\n"
        "mov %[r1], r1\n"
        "mov %[r2], r2\n"
        "mov %[r3], r3\n"
        "mov %[r4], r4\n"
        "mov %[r5], r5\n"
        "mov %[r6], r6\n"
        "mov %[r7], r7\n"
        "mov %[r8], r8\n"
        "mov %[r9], r9\n"
        "mov %[r10], r10\n"
        "mov %[r11], r11\n"
        "mov %[r12], r12\n"
        "mov %[sp], sp\n"
        "mov %[lr], lr\n"
        "mov %[pc], pc\n"
        "mrs %[cpsr], cpsr\n"
        : [r0]  "=r" (r[0]),
          [r1]  "=r" (r[1]),
          [r2]  "=r" (r[2]),
          [r3]  "=r" (r[3]),
          [r4]  "=r" (r[4]),
          [r5]  "=r" (r[5]),
          [r6]  "=r" (r[6]),
          [r7]  "=r" (r[7]),
          [r8]  "=r" (r[8]),
          [r9]  "=r" (r[9]),
          [r10] "=r" (r[10]),
          [r11] "=r" (r[11]),
          [r12] "=r" (r[12]),
          [sp]  "=r" (r[13]),
          [lr]  "=r" (r[14]),
          [pc]  "=r" (r[15]),
          [cpsr] "=r" (cpsr)
    );
}


int main(void) {
	rcc_init();
	uart_init(UART2, 115200);
	uart_write_buffer(UART2, "[INFO] UART initialized\r\n");



    for (int i = 0; i < 16; i++) {
        uart_write_byte(UART2, (uint8_t)r[i]);
    }


    uint16_t tmp = uart_receive_buffer.head; 

    for (;;) {
        if (tmp != uart_receive_buffer.head)
        {
            uint8_t out;
            CircularBuffer_Pop(&uart_receive_buffer, &out);
            uart_write_byte(UART2, out);
            tmp = uart_receive_buffer.head;
        }
        }
}


extern void _estack(void);

__attribute__((naked, noreturn)) void _reset(void) {
    extern long _sbss, _ebss, _sdata, _edata, _sidata;
    for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;  // Clear BSS
    for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;  // Copy data section

    // Debug: Indicate reset handler is called

    main();  // Call main()
    for (;;) (void) 0;  // Infinite loop if main() returns
}

__attribute__((section(".vectors"))) void (* const tab[16 + 91])(void) = {
	_estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, IRQ_systick_handler, [16 + 38] = IRQ_uart_handler, 
};
