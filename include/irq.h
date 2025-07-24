#ifndef IRQ_H
#define IRQ_H 1

__weak IRQ_SystickHandler(void) {
    // Left empty on purpose, please define new definition
}

__weak IRQ_UartHandler(void) {
    // Left empty on purpose, please define new definition
}

__weak IRQ_HardFaultHandler() {
    // Left empty on purpose, please define new definition
}

#endif // IRQ_H
