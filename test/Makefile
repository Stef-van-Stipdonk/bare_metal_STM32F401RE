CC = gcc
CFLAGS = -I./tests -I../test -I../unity -I../include -I../include/arch/stm32/401RE -Wall -Wextra -std=c99 -DUNDER_UNIT_TEST

SRC = ../src/nvic/nvic_enable_irq.c \
	  ../src/nvic/nvic_disable_irq.c \
	  ../src/circular_buffer/CircularBuffer_Push.c \
	  ../src/circular_buffer/CircularBuffer_Pop.c

UNITY = ../unity/unity.c

TESTS = \
    ./tests/test_nvic_enable_irq.c \
    ./tests/test_nvic_disable_irq.c \
	./tests/test_circular_buffer_init.c \
	./tests/test_circular_buffer_push.c \
	./tests/test_circular_buffer_pop.c

TARGETS = $(patsubst ./tests/test_%.c, build/test_%, $(TESTS))

all: $(TARGETS) test

build/test_%: ./tests/test_%.c $(SRC) $(UNITY)
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@

test: $(TARGETS)
	@for t in $(TARGETS); do echo "Running $$t"; ./$$t; done

clean:
	rm -rf build *.o

