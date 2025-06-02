CC = gcc
CFLAGS = -I./nvic -I../test -I../unity -I../include -I../include/arch/stm32/401RE -Wall -Wextra -std=c99 -DUNDER_UNIT_TEST

SRC = ../lib/nvic/nvic_enable_irq.c ../lib/nvic/nvic_disable_irq.c
UNITY = ../unity/unity.c
MOCKS = ./nvic/mock_nvic_regs.c

TESTS = \
    ./nvic/test_nvic_enable_irq.c \
    ./nvic/test_nvic_disable_irq.c

TARGETS = $(patsubst ./nvic/test_%.c, build/test_%, $(TESTS))

all: $(TARGETS) test

build/test_%: ./nvic/test_%.c $(SRC) $(UNITY) $(MOCKS)
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@

test: $(TARGETS)
	@for t in $(TARGETS); do echo "Running $$t"; ./$$t; done

clean:
	rm -rf build *.o

