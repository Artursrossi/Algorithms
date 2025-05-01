# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./src
MEMORY_FLAGS = -fsanitize=address -g -fno-omit-frame-pointer

# Directories
SRC_DIR := src
BUILD_DIR := build
TARGET := algorithms
MEMORY_TARGET := memory-test

# Find all source and object files
SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
MEMORY_OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.mem.o, $(SRCS))

# Default rule
all: $(TARGET)

# Link all object files into the final binary
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile source files to object files
# This rule ensures directory exists and compiles .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
  # Create the necessary directory structure inside build/ if it doesn't exist
	@mkdir -p $(dir $@)
  # Compile the .c file into a .o file
	$(CC) $(CFLAGS) -c $< -o $@

# Memory test build
memory-test: $(MEMORY_TARGET)

# Rule to build the memory-test binary (main-memory)
# This links all .mem.o files using AddressSanitizer and debug symbols
$(MEMORY_TARGET): $(MEMORY_OBJS)
  # Link all memory-checking object files into the memory-test executable
	$(CC) $(MEMORY_OBJS) -o $@ $(MEMORY_FLAGS)

# Rule to compile each .c file into a corresponding .mem.o object file
# using memory sanitizer and debug flags
$(BUILD_DIR)/%.mem.o: $(SRC_DIR)/%.c
  # Create the necessary directory structure inside build/ if it doesn't exist
	@mkdir -p $(dir $@)
  # Compile the .c file with AddressSanitizer and debug flags into a .mem.o file
	$(CC) $(CFLAGS) $(MEMORY_FLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(MEMORY_TARGET)

.PHONY: all clean memory-test
