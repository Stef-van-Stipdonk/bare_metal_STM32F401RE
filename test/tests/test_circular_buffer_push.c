#include "circular_buffer.h"
#include "unity.h"
#include "unity_internals.h"
#include <bits/stdint-uintn.h>
#include <stdint.h>
#include <string.h>

void setUp(void) {
}

void tearDown(void) {}

void test_pass_null_to_circular_buffer_push(void) {

    uint8_t retval = CircularBuffer_Push((void *)0, 8);

    TEST_ASSERT_EQUAL_INT(1, retval);
}


void test_pass_null_data_to_circular_buffer_push(void) {
    CircularBuffer_init(test, 5);
    test.buffer = NULL;
    uint8_t retval = CircularBuffer_Push(&test, 8);

    TEST_ASSERT_EQUAL_INT(1, retval);
}

void test_add_1_to_circular_buffer_of_size_10(void) {
    uint16_t buf_size = 10;

    CircularBuffer_init(test_buffer, buf_size);
    CircularBuffer_Push(&test_buffer, 'A');

    TEST_ASSERT_NOT_NULL(test_buffer.buffer);
    TEST_ASSERT_EQUAL_INT(1, test_buffer.head);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.tail);
    TEST_ASSERT_EQUAL_INT(buf_size, test_buffer.max_length);
    TEST_ASSERT_EQUAL_CHAR('A', test_buffer.buffer[0]);
}

void test_add_5_to_circular_buffer_of_size_10(void) {
    uint16_t buf_size = 10;

    CircularBuffer_init(test_buffer, buf_size);

    CircularBuffer_Push(&test_buffer, 'A');
    CircularBuffer_Push(&test_buffer, 'B');
    CircularBuffer_Push(&test_buffer, 'C');
    CircularBuffer_Push(&test_buffer, 'D');
    CircularBuffer_Push(&test_buffer, 'E');

    TEST_ASSERT_NOT_NULL(test_buffer.buffer);
    TEST_ASSERT_EQUAL_INT(5, test_buffer.head);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.tail);
    TEST_ASSERT_EQUAL_INT(buf_size, test_buffer.max_length);
    TEST_ASSERT_EQUAL_CHAR('A', test_buffer.buffer[0]);
    TEST_ASSERT_EQUAL_CHAR('B', test_buffer.buffer[1]);
    TEST_ASSERT_EQUAL_CHAR('C', test_buffer.buffer[2]);
    TEST_ASSERT_EQUAL_CHAR('D', test_buffer.buffer[3]);
    TEST_ASSERT_EQUAL_CHAR('E', test_buffer.buffer[4]);
}

void test_fill_up_buffer_of_5(void) {
    uint16_t buf_size = 5;

    CircularBuffer_init(test_buffer, buf_size);

    uint8_t ret0 = CircularBuffer_Push(&test_buffer, 'A');
    uint8_t ret1 = CircularBuffer_Push(&test_buffer, 'B');
    uint8_t ret2 = CircularBuffer_Push(&test_buffer, 'C');
    uint8_t ret3 = CircularBuffer_Push(&test_buffer, 'D');
    uint8_t ret4 = CircularBuffer_Push(&test_buffer, 'E');

    TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret0, "var : ret0");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret1, "var : ret1");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret2, "var : ret2");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret3, "var : ret3");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, ret4, "var : ret4");

    TEST_ASSERT_NOT_NULL(test_buffer.buffer);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.head);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.tail);
    TEST_ASSERT_EQUAL_INT(buf_size, test_buffer.max_length);
    TEST_ASSERT_EQUAL_CHAR('A', test_buffer.buffer[0]);
    TEST_ASSERT_EQUAL_CHAR('B', test_buffer.buffer[1]);
    TEST_ASSERT_EQUAL_CHAR('C', test_buffer.buffer[2]);
    TEST_ASSERT_EQUAL_CHAR('D', test_buffer.buffer[3]);
    TEST_ASSERT_EQUAL_CHAR('E', test_buffer.buffer[4]);
}

int main(void) {
    char buf[1024];
    snprintf(buf, sizeof(buf), "[ %s ]", __FILE__);
    UnityBegin(buf);

    RUN_TEST(test_pass_null_to_circular_buffer_push);
    RUN_TEST(test_pass_null_data_to_circular_buffer_push);
    RUN_TEST(test_add_1_to_circular_buffer_of_size_10);
    RUN_TEST(test_add_5_to_circular_buffer_of_size_10);
    RUN_TEST(test_fill_up_buffer_of_5);

    return UnityEnd();
}

