#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H 1

#include <stdint.h>

struct circular_buffer {
    uint8_t *buffer;
    uint16_t head;
    uint16_t tail;
    const uint16_t max_length;
};

#define CircularBuffer_init(x, size)        \
    uint8_t x##_data_space[size];           \
    struct circular_buffer x = {            \
        .buffer = x##_data_space,           \
        .head = 0,                          \
        .tail = 0,                          \
        .max_length = size                  \
    };

uint8_t CircularBuffer_Push(volatile struct circular_buffer *buffer, uint8_t data);

uint8_t CircularBuffer_Pop(volatile struct circular_buffer *buffer, uint8_t *data);

#endif // CIRCULAR_BUFFER_H
