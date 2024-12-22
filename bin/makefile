# Compiler and Flags
CC = x86_64-w64-mingw32-gcc
CFLAGS = -I ../Src -Wall -Wextra -std=c99

# Source and Build Directories
SRC_DIR = ../Src
BUILD_DIR = ../Build
BIN_DIR = ../bin

# Source Files
FEATURE_SRC = $(filter-out $(wildcard $(SRC_DIR)/Feature/driver*.c), $(wildcard $(SRC_DIR)/Feature/*.c))
ADT_SRC = $(filter-out $(wildcard $(SRC_DIR)/ADT/*/driver*.c), $(wildcard $(SRC_DIR)/ADT/*/*.c))
MAIN_SRC = $(SRC_DIR)/main.c
SRC_FILES = $(FEATURE_SRC) $(ADT_SRC) $(MAIN_SRC)

# Object Files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Output Binary
TARGET = $(BIN_DIR)/program.exe

# Rules
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	@echo "Linking..."
	$(CC) $(OBJ_FILES) -o $(TARGET)
	@echo "Build complete! Executable is located at $(TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)/program.exe
	@echo "Clean complete!"
