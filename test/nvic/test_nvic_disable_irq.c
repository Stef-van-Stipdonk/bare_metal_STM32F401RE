#include "mock_nvic_regs.h"
#include "unity.h"
#include "nvic.h"
#include <stdint.h>
#include <string.h>

void setUp(void) {
    memset(&mock_nvic, 0, sizeof(mock_nvic));
}

void tearDown(void) {}

void test_irq_enable_ICER0_bounds(void) {
    nvic_disable_irq(0);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[0]);

    nvic_disable_irq(31);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[0]);
}

void test_irq_enable_ICER1_bounds(void) {
    nvic_disable_irq(32);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[1]);

    nvic_disable_irq(63);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[1]);
}

void test_irq_enable_ICER2_bounds(void) {
    nvic_disable_irq(64);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[2]);

    nvic_disable_irq(95);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[2]);
}

void test_irq_enable_ICER3_bounds(void) {
    nvic_disable_irq(96);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[3]);

    nvic_disable_irq(127);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[3]);
}

void test_irq_enable_ICER4_bounds(void) {
    nvic_disable_irq(128);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[4]);

    nvic_disable_irq(159);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[4]);
}


void test_irq_enable_ICER5_bounds(void) {
    nvic_disable_irq(160);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[5]);

    nvic_disable_irq(191);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[5]);
}


void test_irq_enable_ICER6_bounds(void) {
    nvic_disable_irq(192);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[6]);

    nvic_disable_irq(223);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[6]);
}


void test_irq_enable_ICER7_bounds(void) {
    nvic_disable_irq(224);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ICER[7]);

    nvic_disable_irq(255);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ICER[7]);
}

void test_irq_enable_ICER_out_of_bounds(void) {
    nvic_enable_irq(256);
    nvic_enable_irq(501);
    nvic_enable_irq(300);
    nvic_enable_irq(1000);

    uint32_t expected_array[8] = { 0 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, mock_nvic.ISER, 8);
}

int main(void) {
    UnityBegin("[ test/nvic/test_nvic_disable_irq.c ] ");

    RUN_TEST(test_irq_enable_ICER0_bounds);
    RUN_TEST(test_irq_enable_ICER1_bounds);
    RUN_TEST(test_irq_enable_ICER2_bounds);
    RUN_TEST(test_irq_enable_ICER3_bounds);
    RUN_TEST(test_irq_enable_ICER4_bounds);
    RUN_TEST(test_irq_enable_ICER5_bounds);
    RUN_TEST(test_irq_enable_ICER6_bounds);
    RUN_TEST(test_irq_enable_ICER7_bounds);
    RUN_TEST(test_irq_enable_ICER_out_of_bounds);

    return UnityEnd();
}

