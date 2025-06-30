#include "circular_buffer.h"
#include <stdint.h>

uint8_t CircularBuffer_Push(volatile struct circular_buffer *buffer, uint8_t data) {
    if (!buffer) {
        return 1;
    }

    if (!buffer->buffer) {
        return 1;
    }

    uint16_t next = buffer->head + 1;

    if (next >= buffer->max_length) {
        next = 0;
    }
    
    if (next == buffer->tail) {
        return 1;
    }

    buffer->buffer[buffer->head] = data;
    buffer->head = next;
    return 0;
}
