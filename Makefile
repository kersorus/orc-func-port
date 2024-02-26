CC = gcc
CFLAGS = -Wall -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2
OPT = -O3
FUNC_DIR = func.c
TEST_DIR = tests
BIN_DIR = bin
INCLUDE = $(shell pkg-config --cflags glib-2.0)
FUNC =
GEN_FUNC_FILE = dest_files/gstaudiopack-dist.c
DEFINE = 
ARG = 

gen:
	$(CC) $(CFLAGS) $(OPT) $(DEFINE) $(GEN_FUNC_FILE) $(TEST_DIR)/test_$(FUNC).c -o $(BIN_DIR)/$(FUNC) $(INCLUDE) -D_ORC -DDISABLE_ORC

sse:
	$(CC) $(CFLAGS) $(OPT) $(DEFINE) $(FUNC_DIR)/$(FUNC).c $(TEST_DIR)/test_$(FUNC).c -o $(BIN_DIR)/$(FUNC) $(INCLUDE) -D_SSE

cmp:
	$(CC) $(CFLAGS) $(OPT) $(DEFINE) $(GEN_FUNC_FILE) $(FUNC_DIR)/$(FUNC).c $(TEST_DIR)/test_$(FUNC).c -o $(BIN_DIR)/$(FUNC) $(INCLUDE) -D_CMP -DDISABLE_ORC

run:
	./$(BIN_DIR)/$(FUNC) $(ARG)

