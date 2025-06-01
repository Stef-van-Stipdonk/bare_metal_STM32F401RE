#ifndef MOCK_NVIC_REGS_H
#define MOCK_NVIC_REGS_H


#include <stdint.h>

struct nvic_t {
    uint32_t ISER[8];
    uint32_t ICER[8];
};

extern struct nvic_t mock_nvic;

#endif // MOCK_NVIC_REGS_H
