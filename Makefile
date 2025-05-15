CFLAGS  ?=  -W -Wall -Wextra -Werror -Wundef -Wshadow -Wdouble-promotion \
            -Wformat-truncation -fno-common -Wconversion \
            -g3 -Os -ffunction-sections -fdata-sections \
            -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 $(EXTRA_CFLAGS) $(INC_DIRS)

LDFLAGS ?= -Tlink.ld -nostartfiles -nostdlib -lc -lgcc -Wl,--gc-sections -Wl,-Map=$@.map

SRC_DIR = lib
OBJ_DIR = obj
INC_DIR = include
BUILD_NAME = tmp
BIN_DIR = bin
BIN = firmware.bin

SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC_DIRS = $(addprefix -I,$(shell find $(INC_DIR) -type d))


MAIN_SRC = main.c
MAIN_OBJ = $(OBJ_DIR)/main.o

all: $(BIN) 

$(BIN): $(BUILD_NAME)
	@mkdir -p $(BIN_DIR)
	arm-none-eabi-objcopy -O binary $< $@
	mv $@ $(BIN_DIR)
	rm $(BUILD_NAME)

$(BUILD_NAME): $(MAIN_OBJ) $(OBJS)
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
	rm -rf $(OBJ_DIR) $(BUILD_NAME) $(BIN)

.PHONY: all clean
