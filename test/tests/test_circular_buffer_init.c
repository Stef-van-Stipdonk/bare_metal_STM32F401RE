#include "circular_buffer.h"
#include "unity.h"
#include "unity_internals.h"
#include <stdint.h>
#include <string.h>

void setUp(void) {
}

void tearDown(void) {}

void test_init_circular_buffer_local(void) {
    uint16_t buf_size = 10;

    CircularBuffer_init(test_buffer, buf_size);
    TEST_ASSERT_NOT_NULL(test_buffer.buffer);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.head);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.tail);
    TEST_ASSERT_EQUAL_INT(buf_size, test_buffer.max_length);
}

int main(void) {
    char buf[1024];
    snprintf(buf, sizeof(buf), "[ %s ]", __FILE__);
    UnityBegin(buf);

    RUN_TEST(test_init_circular_buffer_local);

    return UnityEnd();
}

