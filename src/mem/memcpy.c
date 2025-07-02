#include <stddef.h>

void *memcpy(void *dest, const void *src, size_t len) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    while (len--)
        *d++ = *s++;
    return dest;
}
