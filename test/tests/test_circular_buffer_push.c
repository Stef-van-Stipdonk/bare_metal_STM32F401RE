/**************************
*   Includes 
**************************/

#include "circular_buffer.h"
#include "unity.h"
#include "unity_internals.h"
#include <bits/stdint-uintn.h>
#include <stdint.h>
#include <string.h>

/**************************
*   Public Function templates 
**************************/

void Test_PassNullToCircularBufferPush(void);
void Test_PassNullDataToCircularBufferPush(void);
void Test_AddOneToCircularBufferOfSizeTen(void);
void Test_AddFiveToCircularBufferOfSizeTen(void);
void Test_FillUpBufferOfFive(void);

/**************************
*   Private Function templates 
**************************/

/**************************
*   Macros 
**************************/

/**************************
*   Type definitions 
**************************/

/**************************
*   Implementation
**************************/

void setUp(void) {
}

void tearDown(void) {}

void Test_PassNullToCircularBufferPush(void) {

    uint8_t retval = CircularBuffer_Push((void *)0, 8);

    TEST_ASSERT_EQUAL_INT(1, retval);
}


void Test_PassNullDataToCircularBufferPush(void) {
    CircularBuffer_init(test, 5);
    test.buffer = NULL;
    uint8_t retval = CircularBuffer_Push(&test, 8);

    TEST_ASSERT_EQUAL_INT(1, retval);
}

void Test_AddOneToCircularBufferOfSizeTen(void) {
    uint16_t buf_size = 10;

    CircularBuffer_init(test_buffer, buf_size);
    CircularBuffer_Push(&test_buffer, 'A');

    TEST_ASSERT_NOT_NULL(test_buffer.buffer);
    TEST_ASSERT_EQUAL_INT(1, test_buffer.head);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.tail);
    TEST_ASSERT_EQUAL_INT(buf_size, test_buffer.max_length);
    TEST_ASSERT_EQUAL_CHAR('A', test_buffer.buffer[0]);
}

void Test_AddFiveToCircularBufferOfSizeTen(void) {
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

void Test_FillUpBufferOfFive(void) {
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
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, ret4, "var : ret4");

    TEST_ASSERT_NOT_NULL(test_buffer.buffer);
    TEST_ASSERT_EQUAL_INT(4, test_buffer.head);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.tail);
    TEST_ASSERT_EQUAL_INT(buf_size, test_buffer.max_length);
    TEST_ASSERT_EQUAL_CHAR('A', test_buffer.buffer[0]);
    TEST_ASSERT_EQUAL_CHAR('B', test_buffer.buffer[1]);
    TEST_ASSERT_EQUAL_CHAR('C', test_buffer.buffer[2]);
    TEST_ASSERT_EQUAL_CHAR('D', test_buffer.buffer[3]);
}

int main(void) {
    char buf[1024];
    snprintf(buf, sizeof(buf), "[ %s ]", __FILE__);
    UnityBegin(buf);

    RUN_TEST(Test_PassNullToCircularBufferPush);
    RUN_TEST(Test_PassNullDataToCircularBufferPush);
    RUN_TEST(Test_AddOneToCircularBufferOfSizeTen);
    RUN_TEST(Test_AddFiveToCircularBufferOfSizeTen);
    RUN_TEST(Test_FillUpBufferOfFive);

    return UnityEnd();
}
