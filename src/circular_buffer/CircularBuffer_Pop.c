#include "circular_buffer.h"
#include <stdint.h>

uint8_t CircularBuffer_Pop(volatile struct circular_buffer *buffer, uint8_t *data) {
    if (!data) {
        return 1;
    }

    if (!buffer) {
        *data = 0;
        return 1;
    }

    if (!buffer->buffer) {
        *data = 0;
        return 1;
    }

    if (buffer->head == buffer->tail) {
        *data = 0;
        return 1;
    }

    uint16_t next = buffer->tail + 1;

    if (next >= buffer->max_length) {
        next = 0;
    }

    *data = buffer->buffer[buffer->tail];
    buffer->tail = next;

    return 0;
}
