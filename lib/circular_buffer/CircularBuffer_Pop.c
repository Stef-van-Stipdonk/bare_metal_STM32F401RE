#include "circular_buffer.h"
#include <stdint.h>

uint8_t CircularBuffer_Pop(volatile struct circular_buffer *buffer, uint8_t *data) {
    uint16_t next;

    if (buffer->head == buffer->tail) {
        return 1;
    }

    next = buffer->tail + 1;
    if (next >= buffer->max_length) {
        next = 0;
    }

    *data = buffer->buffer[buffer->tail];
    buffer->tail = next;

    return 0;
}
