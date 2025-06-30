// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "include/circular_buffer.h"
#include "obj/vendor/unity/src/unity.h"
#include "obj/vendor/unity/src/unity_internals.h"

void Test_PassNullBufferToCircularBufferPop(void);
void Test_PassNullDataToCircularBufferPop(void);
void Test_PassNullRetDataToCircularBufferPop(void);
void Test_PopOnEmptyCircularBufferPop(void);
void Test_PopAndCheckSingleElementOnCircularBuffer(void);
void Test_PopAndCheckSingleThenPopOnEmtpyBufferElementOnCircularBuffer(void);
void Test_PopFullCircularBuffer(void);
void Test_CirculateEntireBuffer(void);
uint8_t data[10];
struct circular_buffer buffer = {
    .buffer = data,
    .head = 0,
    .tail = 0,
    .max_length = 10,
};

void setUp(void)
{
    buffer.buffer = data;
    buffer.head = 0;
    buffer.tail = 0;
}

void tearDown(void)
{}

void Test_PassNullBufferToCircularBufferPop(void)
{
    uint8_t ret_data = 1;

    uint8_t retval = CircularBuffer_Pop((void *)0, &ret_data);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);
}

void Test_PassNullDataToCircularBufferPop(void)
{
    uint8_t ret_data = 1;

    buffer.buffer =
                   ((void *)0)

    uint8_t retval = CircularBuffer_Pop(&buffer, &ret_data);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);
}

void Test_PassNullRetDataToCircularBufferPop(void)
{
    uint8_t retval = CircularBuffer_Pop(&buffer, (void *)0);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);
}

void Test_PopOnEmptyCircularBufferPop(void)
{
    uint8_t ret_data = 1;
    uint8_t retval = CircularBuffer_Pop(&buffer, &ret_data);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);
}

void Test_PopAndCheckSingleElementOnCircularBuffer(void)
{
    uint8_t ret_data = 0;

    CircularBuffer_Push(&buffer, 10);
    uint8_t retval = CircularBuffer_Pop(&buffer, &ret_data);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_INT);
}

void Test_PopAndCheckSingleThenPopOnEmtpyBufferElementOnCircularBuffer(void)
{
    uint8_t ret_data = 0;

    CircularBuffer_Push(&buffer, 10);
    uint8_t retval = CircularBuffer_Pop(&buffer, &ret_data);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

    retval = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retval)), (
   ((void *)0)
   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_INT);
}

void Test_PopFullCircularBuffer(void)
{
    uint8_t ret_data = 0;
    uint8_t ret_status = 0;

    buffer.buffer = data;
    buffer.head = 0;
    buffer.tail = 0;

    for (uint8_t i = 0; i < 10 - 1; i++)
{
        CircularBuffer_Push(&buffer, i);
    }
    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(137), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(138), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(139), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(142), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(148), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(149), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(152), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(153), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(154), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(157), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(159), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(162), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(173), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(174), UNITY_DISPLAY_STYLE_INT);
}

void Test_CirculateEntireBuffer(void)
{
    uint8_t ret_data = 0;
    uint8_t ret_status = 0;

    buffer.buffer = data;
    buffer.head = 0;
    buffer.tail = 0;

    for (uint8_t i = 0; i < 10 - 1; i++)
{
        CircularBuffer_Push(&buffer, i);
    }

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(190), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(191), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(192), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(194), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(197), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(198), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(199), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(201), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(204), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(205), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(206), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(208), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(211), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(212), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(215), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(218), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(219), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(220), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(222), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(225), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(226), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(227), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(229), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(232), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(233), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(234), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(236), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(239), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(240), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(241), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(243), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(246), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(247), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(248), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(250), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(253), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(254), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(255), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(257), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(260), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(261), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(262), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(264), UNITY_DISPLAY_STYLE_INT);

    ret_status = CircularBuffer_Pop(&buffer, &ret_data);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret_status)), (
   ((void *)0)
   ), (UNITY_UINT)(267), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((ret_data)), (
   ((void *)0)
   ), (UNITY_UINT)(268), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((buffer.tail)), (
   ((void *)0)
   ), (UNITY_UINT)(269), UNITY_DISPLAY_STYLE_INT);
    CircularBuffer_Push(&buffer, 10);
    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((buffer.head)), (
   ((void *)0)
   ), (UNITY_UINT)(271), UNITY_DISPLAY_STYLE_INT);
}