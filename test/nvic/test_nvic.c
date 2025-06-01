#include "mock_nvic_regs.h"
#include "unity.h"
#include "nvic.h"
#include <string.h>

void setUp(void) {
    memset(&mock_nvic, 0, sizeof(mock_nvic));
}

void tearDown(void) {}

void test_enable_irq_sets_correct_ISER_bit(void) {
    nvic_enable_irq(5);
    TEST_ASSERT_EQUAL_HEX32(1 << 5, mock_nvic.ISER[0]);
}

void test_disable_irq_sets_correct_ICER_bit(void) {
    nvic_disable_irq(37); // 37 maps to ICER1 (index 1), bit 5
    TEST_ASSERT_EQUAL_HEX32(1 << 5, mock_nvic.ICER[1]);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_enable_irq_sets_correct_ISER_bit);
    RUN_TEST(test_disable_irq_sets_correct_ICER_bit);
    return UNITY_END();
}

