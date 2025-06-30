/**************************
*   Includes 
**************************/

#include "circular_buffer.h"
#include "unity.h"
#include "unity_internals.h"
#include <stdint.h>
#include <string.h>

/**************************
*   Public Function templates 
**************************/

void Test_InitCircularBufferLocal(void);

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

void Test_InitCircularBufferLocal(void) {
    uint16_t buf_size = 10;

    CircularBuffer_init(test_buffer, buf_size);
    TEST_ASSERT_NOT_NULL(test_buffer.buffer);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.head);
    TEST_ASSERT_EQUAL_INT(0, test_buffer.tail);
    TEST_ASSERT_EQUAL_INT(buf_size, test_buffer.max_length);
}
