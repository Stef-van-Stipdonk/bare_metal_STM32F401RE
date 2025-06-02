#include "mock_nvic_regs.h"
#include "unity.h"
#include "nvic.h"
#include "unity_internals.h"
#include <stdint.h>
#include <string.h>

void setUp(void) {
    memset(&mock_nvic, 0, sizeof(mock_nvic));
}

void tearDown(void) {}

void test_irq_enable_ISER0_bounds(void) {
    nvic_enable_irq(0);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[0]);

    nvic_enable_irq(31);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[0]);
}

void test_irq_enable_ISER1_bounds(void) {
    nvic_enable_irq(32);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[1]);

    nvic_enable_irq(63);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[1]);
}

void test_irq_enable_ISER2_bounds(void) {
    nvic_enable_irq(64);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[2]);

    nvic_enable_irq(95);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[2]);
}

void test_irq_enable_ISER3_bounds(void) {
    nvic_enable_irq(96);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[3]);

    nvic_enable_irq(127);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[3]);
}

void test_irq_enable_ISER4_bounds(void) {
    nvic_enable_irq(128);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[4]);

    nvic_enable_irq(159);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[4]);
}


void test_irq_enable_ISER5_bounds(void) {
    nvic_enable_irq(160);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[5]);

    nvic_enable_irq(191);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[5]);
}


void test_irq_enable_ISER6_bounds(void) {
    nvic_enable_irq(192);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[6]);

    nvic_enable_irq(223);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[6]);
}


void test_irq_enable_ISER7_bounds(void) {
    nvic_enable_irq(224);
    TEST_ASSERT_EQUAL_HEX32(1 << 0, mock_nvic.ISER[7]);

    nvic_enable_irq(255);
    TEST_ASSERT_EQUAL_HEX32(1 << 31, mock_nvic.ISER[7]);
}

void test_irq_enable_ISER_out_of_bounds(void) {
    nvic_enable_irq(256);
    nvic_enable_irq(501);
    nvic_enable_irq(300);
    nvic_enable_irq(1000);

    uint32_t expected_array[8] = { 0 };
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_array, mock_nvic.ISER, 8);
}

int main(void) {
    UnityBegin("[ test/nvic/test_nvic_enable_irq.c ] ");

    RUN_TEST(test_irq_enable_ISER0_bounds);
    RUN_TEST(test_irq_enable_ISER1_bounds);
    RUN_TEST(test_irq_enable_ISER2_bounds);
    RUN_TEST(test_irq_enable_ISER3_bounds);
    RUN_TEST(test_irq_enable_ISER4_bounds);
    RUN_TEST(test_irq_enable_ISER5_bounds);
    RUN_TEST(test_irq_enable_ISER6_bounds);
    RUN_TEST(test_irq_enable_ISER7_bounds);
    RUN_TEST(test_irq_enable_ISER_out_of_bounds);

    return UNITY_END();
}

