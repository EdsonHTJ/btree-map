CC = gcc
CFLAGS = -Wall -g

# Include directories
C_INCLUDES = -I./btree

# Define the build directory
BUILD_DIR = ./build

# Define the object files
OBJ = $(BUILD_DIR)/btree.o $(BUILD_DIR)/test.o

# Define the executable file
EXEC = $(BUILD_DIR)/test

# The first rule is the default rule
# Build the executable by linking object files
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(C_INCLUDES) -o $(EXEC) $(OBJ)

# Rule for building object file for btree
$(BUILD_DIR)/btree.o: btree/btree.c btree/btree.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(C_INCLUDES) -c btree/btree.c -o $(BUILD_DIR)/btree.o

# Rule for building object file for test
$(BUILD_DIR)/test.o: test.c btree/btree.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(C_INCLUDES) -c test.c -o $(BUILD_DIR)/test.o

# Custom command for building and running the test
test: $(EXEC)
	./$(EXEC)

# Clean rule
clean:
	rm -rf $(BUILD_DIR)
