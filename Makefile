
CC = gcc
CFLAGS = -Wall -g


SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin
TEST_DIR = test
INCLUDE_DIR = include


LIBRARY = $(LIB_DIR)/liballoInfo.a
TEST_BINARY = $(BIN_DIR)/alloInfoTest


SRC = $(SRC_DIR)/alloInfo.c
OBJ = $(SRC:.c=.o)


all: $(LIBRARY) $(TEST_BINARY)
	@echo "Running unit tests:"
	./$(TEST_BINARY)


$(LIBRARY): $(OBJ)
	@mkdir -p $(LIB_DIR)
	ar rcs $(LIBRARY) $(OBJ)


$(TEST_BINARY): $(LIBRARY) $(TEST_DIR)/alloInfoTest.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(TEST_BINARY) $(TEST_DIR)/alloInfoTest.c -L$(LIB_DIR) -lalloInfo


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(SRC_DIR)/*.o $(LIB_DIR)/*.a $(BIN_DIR)/*

.PHONY: all clean