#include "circular_buffer.h"

uint8_t CircularBuffer_Push(struct circular_buffer *buffer, uint8_t data) {
    uint16_t next;

    next = buffer->head + 1;

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
