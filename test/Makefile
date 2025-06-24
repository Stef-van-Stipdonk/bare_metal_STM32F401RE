CC = gcc
CFLAGS = -I./tests -I../test -I../unity -I../include -I../include/arch/stm32/401RE -Wall -Wextra -std=c99 -DUNDER_UNIT_TEST

SRC = ../lib/nvic/nvic_enable_irq.c \
	  ../lib/nvic/nvic_disable_irq.c \
	  ../lib/circular_buffer/CircularBuffer_Push.c \
	  ../lib/circular_buffer/CircularBuffer_Pop.c

UNITY = ../unity/unity.c
MOCKS = ./mocks/mock_nvic_regs.c

TESTS = \
    ./tests/test_nvic_enable_irq.c \
    ./tests/test_nvic_disable_irq.c \
	./tests/test_circular_buffer_init.c \
	./tests/test_circular_buffer_push.c

TARGETS = $(patsubst ./tests/test_%.c, build/test_%, $(TESTS))

all: $(TARGETS) test

build/test_%: ./tests/test_%.c $(SRC) $(UNITY) $(MOCKS)
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@

test: $(TARGETS)
	@for t in $(TARGETS); do echo "Running $$t"; ./$$t; done

clean:
	rm -rf build *.o

