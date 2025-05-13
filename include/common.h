#ifndef COMMON_H
#define COMMON_H 1

#include <stdint.h>

static inline void spin(volatile uint32_t count) {
  while (count--) (void) 0;
}

#endif // COMMON_H
