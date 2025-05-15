CFLAGS  ?=  -W -Wall -Wextra -Werror -Wundef -Wshadow -Wdouble-promotion \
            -Wformat-truncation -fno-common -Wconversion \
            -g3 -Os -ffunction-sections -fdata-sections \
            -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 $(EXTRA_CFLAGS) $(P_INC_DIRS)

LDFLAGS ?= -Tlink.ld -nostartfiles -nostdlib -lc -lgcc -Wl,--gc-sections -Wl,-Map=$@.map

SRC_DIR = lib
OBJ_DIR = obj
INC_DIR = include
BIN = main

SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC_DIRS = $(shell find $(INC_DIR) -type d)
P_INC_DIRS = $(addprefix -I,$(INC_DIRS))


MAIN_SRC = main.c
MAIN_OBJ = $(OBJ_DIR)/main.o

all: firmware.bin

firmware.bin: $(BIN)
	arm-none-eabi-objcopy -O binary $< $@

$(BIN): $(MAIN_OBJ) $(OBJS)
	arm-none-eabi-gcc $(CFLAGS) $(LDFLAGS) $^ -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	@mkdir -p $(dir $@)
	arm-none-eabi-gcc $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	arm-none-eabi-gcc $(CFLAGS) -c $< -o $@

firmware.elf: $(SOURCES)
	arm-none-eabi-gcc $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
