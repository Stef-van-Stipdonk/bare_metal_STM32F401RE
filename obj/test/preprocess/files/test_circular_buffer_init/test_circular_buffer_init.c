// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "include/circular_buffer.h"
#include "obj/vendor/unity/src/unity.h"
#include "obj/vendor/unity/src/unity_internals.h"

void Test_InitCircularBufferLocal(void);
void setUp(void)
{
}

void tearDown(void)
{}

void Test_InitCircularBufferLocal(void)
{
    uint16_t buf_size = 10;

    uint8_t test_buffer_data_space[buf_size]; struct circular_buffer test_buffer = { .buffer = test_buffer_data_space, .head = 0, .tail = 0, .max_length = buf_size };;
    do { if ((((test_buffer.buffer)) !=
   ((void *)0)
   ))
{ } else { UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)(((43)))); } } while (0);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((buf_size)), (UNITY_INT)((test_buffer.max_length)), (
   ((void *)0)
   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);
}