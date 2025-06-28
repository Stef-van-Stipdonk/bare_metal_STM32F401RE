/**************************
*   Includes 
**************************/

#include "../mocks/mock_nvic_regs.h"
#include "unity.h"
#include "nvic.h"
#include "unity_internals.h"
#include <stdint.h>
#include <string.h>

/**************************
*   Public Function templates 
**************************/

void Test_IrqEnableISER0Bounds(void);
void Test_IrqEnableISER1Bounds(void);
void Test_IrqEnableISER2Bounds(void);
void Test_IrqEnableISER3Bounds(void);
void Test_IrqEnableISER4Bounds(void);
void Test_IrqEnableISER5Bounds(void);
void Test_IrqEnableISER6Bounds(void);
void Test_IrqEnableISER7Bounds(void);
void Test_IrqEnableISEROutOfBounds(void);

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
    memset(&mock_nvic, 0, sizeof(mock_nvic));
}

void tearDown(void) {}

void Test_IrqEnableISER0Bounds(void) {
    nvic_enable_irq(0);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[0]);

    nvic_enable_irq(31);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[0]);
}

void Test_IrqEnableISER1Bounds(void) {
    nvic_enable_irq(32);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[1]);

    nvic_enable_irq(63);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[1]);
}

void Test_IrqEnableISER2Bounds(void) {
    nvic_enable_irq(64);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[2]);

    nvic_enable_irq(95);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[2]);
}

void Test_IrqEnableISER3Bounds(void) {
    nvic_enable_irq(96);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[3]);

    nvic_enable_irq(127);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[3]);
}

void Test_IrqEnableISER4Bounds(void) {
    nvic_enable_irq(128);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[4]);

    nvic_enable_irq(159);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[4]);
}


void Test_IrqEnableISER5Bounds(void) {
    nvic_enable_irq(160);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[5]);

    nvic_enable_irq(191);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[5]);
}


void Test_IrqEnableISER6Bounds(void) {
    nvic_enable_irq(192);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[6]);

    nvic_enable_irq(223);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[6]);
}


void Test_IrqEnableISER7Bounds(void) {
    nvic_enable_irq(224);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[7]);

    nvic_enable_irq(255);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[7]);
}

void Test_IrqEnableISEROutOfBounds(void) {
    nvic_enable_irq(256);
    nvic_enable_irq(501);
    nvic_enable_irq(300);
    nvic_enable_irq(1000);

    uint32_t expected_array[8] = { 0 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, mock_nvic.ISER, 8);
}

int main(void) {
    char buf[1024];
    snprintf(buf, sizeof(buf), "[ %s ]", __FILE__);
    UnityBegin(buf);

    RUN_TEST(Test_IrqEnableISER0Bounds);
    RUN_TEST(Test_IrqEnableISER1Bounds);
    RUN_TEST(Test_IrqEnableISER2Bounds);
    RUN_TEST(Test_IrqEnableISER3Bounds);
    RUN_TEST(Test_IrqEnableISER4Bounds);
    RUN_TEST(Test_IrqEnableISER5Bounds);
    RUN_TEST(Test_IrqEnableISER6Bounds);
    RUN_TEST(Test_IrqEnableISER7Bounds);
    RUN_TEST(Test_IrqEnableISEROutOfBounds);

    return UNITY_END();
}

