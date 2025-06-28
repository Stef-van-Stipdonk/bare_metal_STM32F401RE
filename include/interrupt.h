#ifndef INTERRUPTS_H
#define INTERRUPTS_H 1

__weak IRQ_systick_handler(void) {
    // Left empty on purpose, please define new definition
}

__weak IRQ_uart_handler(void) {
    // Left empty on purpose, please define new definition
}

#endif // INTERRUPTS_H
