// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "include/circular_buffer.h"
#include "obj/vendor/unity/src/unity.h"
#include "obj/vendor/unity/src/unity_internals.h"

void Test_PassNullToCircularBufferPush(void);
void Test_PassNullDataToCircularBufferPush(void);
void Test_AddOneToCircularBufferOfSizeTen(void);
void Test_AddFiveToCircularBufferOfSizeTen(void);
void Test_FillUpBufferOfFive(void);
void setUp(void)
{
}

void tearDown(void)
{}

void Test_PassNullToCircularBufferPush(void)
{
    uint8_t retval = CircularBuffer_Push((void *)0, 8);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);
}

void Test_PassNullDataToCircularBufferPush(void)
{
    uint8_t test_data_space[5]; struct circular_buffer test = { .buffer = test_data_space, .head = 0, .tail = 0, .max_length = 5 };;
    test.buffer =
                 ((void *)0)

    uint8_t retval = CircularBuffer_Push(&test, 8);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);
}

void Test_AddOneToCircularBufferOfSizeTen(void)
{
    uint16_t buf_size = 10;

    uint8_t test_buffer_data_space[buf_size]; struct circular_buffer test_buffer = { .buffer = test_buffer_data_space, .head = 0, .tail = 0, .max_length = buf_size };;
    CircularBuffer_Push(&test_buffer, 'A');

    do { if ((((test_buffer.buffer)) !=
   ((void *)0)
   ))
{ } else { UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)(((65)))); } } while (0);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((test_buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((buf_size)), (UNITY_INT)((test_buffer.max_length)), (
   ((void *)0)
   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('A')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[0])), (
   ((void *)0)
   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_CHAR);
}

void Test_AddFiveToCircularBufferOfSizeTen(void)
{
    uint16_t buf_size = 10;

    uint8_t test_buffer_data_space[buf_size]; struct circular_buffer test_buffer = { .buffer = test_buffer_data_space, .head = 0, .tail = 0, .max_length = buf_size };;

    CircularBuffer_Push(&test_buffer, 'A');
    CircularBuffer_Push(&test_buffer, 'B');
    CircularBuffer_Push(&test_buffer, 'C');
    CircularBuffer_Push(&test_buffer, 'D');
    CircularBuffer_Push(&test_buffer, 'E');

    do { if ((((test_buffer.buffer)) !=
   ((void *)0)
   ))
{ } else { UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)(((83)))); } } while (0);
    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((test_buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((buf_size)), (UNITY_INT)((test_buffer.max_length)), (
   ((void *)0)
   ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('A')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[0])), (
   ((void *)0)
   ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_CHAR);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('B')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[1])), (
   ((void *)0)
   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_CHAR);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('C')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[2])), (
   ((void *)0)
   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_CHAR);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('D')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[3])), (
   ((void *)0)
   ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_CHAR);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('E')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[4])), (
   ((void *)0)
   ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_CHAR);
}

void Test_FillUpBufferOfFive(void)
{
    uint16_t buf_size = 5;

    uint8_t test_buffer_data_space[buf_size]; struct circular_buffer test_buffer = { .buffer = test_buffer_data_space, .head = 0, .tail = 0, .max_length = buf_size };;

    uint8_t ret0 = CircularBuffer_Push(&test_buffer, 'A');
    uint8_t ret1 = CircularBuffer_Push(&test_buffer, 'B');
    uint8_t ret2 = CircularBuffer_Push(&test_buffer, 'C');
    uint8_t ret3 = CircularBuffer_Push(&test_buffer, 'D');
    uint8_t ret4 = CircularBuffer_Push(&test_buffer, 'E');

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret0)), (("var : ret0")), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret1)), (("var : ret1")), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret2)), (("var : ret2")), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret3)), (("var : ret3")), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ret4)), (("var : ret4")), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

    do { if ((((test_buffer.buffer)) !=
   ((void *)0)
   ))
{ } else { UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)(((111)))); } } while (0);
    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((test_buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((buf_size)), (UNITY_INT)((test_buffer.max_length)), (
   ((void *)0)
   ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('A')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[0])), (
   ((void *)0)
   ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_CHAR);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('B')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[1])), (
   ((void *)0)
   ), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_CHAR);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('C')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[2])), (
   ((void *)0)
   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_CHAR);
    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(('D')), (UNITY_INT)(UNITY_INT8 )((test_buffer.buffer[3])), (
   ((void *)0)
   ), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_CHAR);
}