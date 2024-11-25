# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -O2

# Directories
SRCDIR = src
BINDIR = bin
OBJDIR = $(BINDIR)/obj

# Source and object files
SRCS = $(wildcard $(SRCDIR)/**/*.c) $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Target executable
TARGET = $(BINDIR)/program

# Default rule
all: $(TARGET)

# Rule to create the final executable
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BINDIR)

# Run rule
run: all
	./$(TARGET)
