# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Isrc
LDFLAGS = 

# Directories
SRCDIR = src
OBJDIR = obj

# Target executable
TARGET = orka.exe

# Source files
SOURCES = orka.c $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)
OBJFILES = $(addprefix $(OBJDIR)/, $(notdir $(OBJECTS)))

# Default target
all: $(TARGET)

# Create object directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build target executable
$(TARGET): $(OBJDIR) $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET) $(LDFLAGS)

# Compile main source file
$(OBJDIR)/orka.o: orka.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile source files from src directory
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Rebuild everything
rebuild: clean all

# Install (optional - modify path as needed)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall (optional)
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Release build with optimization
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  rebuild  - Clean and build"
	@echo "  debug    - Build with debug information"
	@echo "  release  - Build optimized release version"
	@echo "  install  - Install to system (modify path as needed)"
	@echo "  help     - Show this help message"

# Phony targets
.PHONY: all clean rebuild install uninstall debug release help