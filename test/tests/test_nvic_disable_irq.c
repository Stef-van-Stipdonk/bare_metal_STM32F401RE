/**************************
*   Includes 
**************************/

#include "../mocks/mock_nvic_regs.h"
#include "unity.h"
#include "nvic.h"
#include <stdint.h>
#include <string.h>

/**************************
*   Public Function templates 
**************************/

void Test_IrqDisableICER0Bounds(void);
void Test_IrqDisableICER1Bounds(void);
void Test_IrqDisableICER2Bounds(void);
void Test_IrqDisableICER3Bounds(void);
void Test_IrqDisableICER4Bounds(void);
void Test_IrqDisableICER5Bounds(void);
void Test_IrqDisableICER6Bounds(void);
void Test_IrqDisableICER7Bounds(void);
void Test_IrqDisableICEROutOfBounds(void);

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

void Test_IrqDisableICER0Bounds(void) {
    nvic_disable_irq(0);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[0]);

    nvic_disable_irq(31);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[0]);
}

void Test_IrqDisableICER1Bounds(void) {
    nvic_disable_irq(32);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[1]);

    nvic_disable_irq(63);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[1]);
}

void Test_IrqDisableICER2Bounds(void) {
    nvic_disable_irq(64);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[2]);

    nvic_disable_irq(95);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[2]);
}

void Test_IrqDisableICER3Bounds(void) {
    nvic_disable_irq(96);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[3]);

    nvic_disable_irq(127);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[3]);
}

void Test_IrqDisableICER4Bounds(void) {
    nvic_disable_irq(128);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[4]);

    nvic_disable_irq(159);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[4]);
}


void Test_IrqDisableICER5Bounds(void) {
    nvic_disable_irq(160);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[5]);

    nvic_disable_irq(191);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[5]);
}


void Test_IrqDisableICER6Bounds(void) {
    nvic_disable_irq(192);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[6]);

    nvic_disable_irq(223);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[6]);
}


void Test_IrqDisableICER7Bounds(void) {
    nvic_disable_irq(224);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[7]);

    nvic_disable_irq(255);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[7]);
}

void Test_IrqDisableICEROutOfBounds(void) {
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

    RUN_TEST(Test_IrqDisableICER0Bounds);
    RUN_TEST(Test_IrqDisableICER1Bounds);
    RUN_TEST(Test_IrqDisableICER2Bounds);
    RUN_TEST(Test_IrqDisableICER3Bounds);
    RUN_TEST(Test_IrqDisableICER4Bounds);
    RUN_TEST(Test_IrqDisableICER5Bounds);
    RUN_TEST(Test_IrqDisableICER6Bounds);
    RUN_TEST(Test_IrqDisableICER7Bounds);
    RUN_TEST(Test_IrqDisableICEROutOfBounds);

    return UnityEnd();
}

