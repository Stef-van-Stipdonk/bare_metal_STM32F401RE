CC = gcc
CFLAGS = -I./nvic -I../test -I../unity -I../include -I../include/arch/stm32/401RE -Wall -Wextra -std=c99 -DUNDER_UNIT_TEST

SRC = ../lib/nvic/nvic_enable_irq.c ../lib/nvic/nvic_disable_irq.c
TEST_SRC = ./nvic/test_nvic.c ../unity/unity.c ./nvic/mock_nvic_regs.c

TARGET = build/test_nvic

all: $(TARGET)

$(TARGET): $(SRC) $(TEST_SRC)
	@mkdir -p build
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) -o $(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build *.o
