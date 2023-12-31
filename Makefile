CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/logger.c src/lk.c src/stack.c src/main.c
EXEC = ./bin/main

all:
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -f $(EXEC)
