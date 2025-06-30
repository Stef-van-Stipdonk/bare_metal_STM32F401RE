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

void Test_PassNullBufferToCircularBufferPop(void);
void Test_PassNullDataToCircularBufferPop(void);
void Test_PassNullRetDataToCircularBufferPop(void);
void Test_PopOnEmptyCircularBufferPop(void);
void Test_PopAndCheckSingleElementOnCircularBuffer(void);
void Test_PopAndCheckSingleThenPopOnEmtpyBufferElementOnCircularBuffer(void);
void Test_PopFullCircularBuffer(void);
void Test_CirculateEntireBuffer(void);

/**************************
*   Private Function templates 
**************************/

/**************************
*   Macros 
**************************/
#define BUFFER_SIZE 10


/**************************
*   Type definitions 
**************************/
uint8_t data[10];
struct circular_buffer buffer = {
    .buffer = data,
    .head = 0,
    .tail = 0,
    .max_length = BUFFER_SIZE,
};

void setUp(void) {
    buffer.buffer = data;
    buffer.head = 0;
    buffer.tail = 0;
}

/**************************
*   Implementation
**************************/

void tearDown(void) {}

void Test_PassNullBufferToCircularBufferPop(void) {
    uint8_t ret_data = 1;

    uint8_t retval = CircularBuffer_Pop((void *)0, &ret_data);
    
    TEST_ASSERT_EQUAL_INT(1, retval);
    TEST_ASSERT_EQUAL_INT(0, ret_data);
}

void Test_PassNullDataToCircularBufferPop(void) {
    uint8_t ret_data = 1;
    
    buffer.buffer = NULL;
    uint8_t retval = CircularBuffer_Pop(&buffer, &ret_data);
    
    TEST_ASSERT_EQUAL_INT(1, retval);
    TEST_ASSERT_EQUAL_INT(0, ret_data);
}


void Test_PassNullRetDataToCircularBufferPop(void) {
    uint8_t retval = CircularBuffer_Pop(&buffer, (void *)0);
    
    TEST_ASSERT_EQUAL_INT(1, retval);
}

void Test_PopOnEmptyCircularBufferPop(void) {
    uint8_t ret_data = 1;
    uint8_t retval = CircularBuffer_Pop(&buffer, &ret_data);
    
    TEST_ASSERT_EQUAL_INT(1, retval);
    TEST_ASSERT_EQUAL_INT(0, ret_data);
}

void Test_PopAndCheckSingleElementOnCircularBuffer(void) {
    uint8_t ret_data = 0;

    CircularBuffer_Push(&buffer, 10);
    uint8_t retval = CircularBuffer_Pop(&buffer, &ret_data);
    
    TEST_ASSERT_EQUAL_INT(0, retval);
    TEST_ASSERT_EQUAL_INT(10, ret_data);
}

void Test_PopAndCheckSingleThenPopOnEmtpyBufferElementOnCircularBuffer(void) {
    uint8_t ret_data = 0;

    CircularBuffer_Push(&buffer, 10);
    uint8_t retval = CircularBuffer_Pop(&buffer, &ret_data);
    
    TEST_ASSERT_EQUAL_INT(0, retval);
    TEST_ASSERT_EQUAL_INT(10, ret_data);

    
    retval = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(1, retval);
    TEST_ASSERT_EQUAL_INT(0, ret_data);
}

void Test_PopFullCircularBuffer(void) {
    uint8_t ret_data = 0;
    uint8_t ret_status = 0;

    buffer.buffer = data;
    buffer.head = 0;
    buffer.tail = 0;

    for (uint8_t i = 0; i < BUFFER_SIZE - 1; i++) {
        CircularBuffer_Push(&buffer, i);
    }
    TEST_ASSERT_EQUAL_INT(9, buffer.head);


    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(0, ret_data);
    TEST_ASSERT_EQUAL_INT(1, buffer.tail);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(1, ret_data);
    TEST_ASSERT_EQUAL_INT(2, buffer.tail);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(2, ret_data);
    TEST_ASSERT_EQUAL_INT(3, buffer.tail);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(3, ret_data);
    TEST_ASSERT_EQUAL_INT(4, buffer.tail);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(4, ret_data);
    TEST_ASSERT_EQUAL_INT(5, buffer.tail);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(5, ret_data);
    TEST_ASSERT_EQUAL_INT(6, buffer.tail);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(6, ret_data);
    TEST_ASSERT_EQUAL_INT(7, buffer.tail);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(7, ret_data);
    TEST_ASSERT_EQUAL_INT(8, buffer.tail);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(8, ret_data);
    TEST_ASSERT_EQUAL_INT(9, buffer.tail);
}

void Test_CirculateEntireBuffer(void) {
    uint8_t ret_data = 0;
    uint8_t ret_status = 0;

    buffer.buffer = data;
    buffer.head = 0;
    buffer.tail = 0;

    for (uint8_t i = 0; i < BUFFER_SIZE - 1; i++) {
        CircularBuffer_Push(&buffer, i);
    }

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(0, ret_data);
    TEST_ASSERT_EQUAL_INT(1, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(0, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(1, ret_data);
    TEST_ASSERT_EQUAL_INT(2, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(1, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(2, ret_data);
    TEST_ASSERT_EQUAL_INT(3, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(2, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(3, ret_data);
    TEST_ASSERT_EQUAL_INT(4, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(3, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(4, ret_data);
    TEST_ASSERT_EQUAL_INT(5, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(4, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(5, ret_data);
    TEST_ASSERT_EQUAL_INT(6, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(5, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(6, ret_data);
    TEST_ASSERT_EQUAL_INT(7, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(6, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(7, ret_data);
    TEST_ASSERT_EQUAL_INT(8, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(7, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(8, ret_data);
    TEST_ASSERT_EQUAL_INT(9, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(8, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(10, ret_data);
    TEST_ASSERT_EQUAL_INT(0, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(9, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(10, ret_data);
    TEST_ASSERT_EQUAL_INT(1, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(0, buffer.head);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    TEST_ASSERT_EQUAL_INT(0, ret_status);
    TEST_ASSERT_EQUAL_INT(10, ret_data);
    TEST_ASSERT_EQUAL_INT(2, buffer.tail);
    CircularBuffer_Push(&buffer, 10);
    TEST_ASSERT_EQUAL_INT(1, buffer.head);
}
