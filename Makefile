CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=gnu99
INC = -I.

main:
	$(CC) $(CFLAGS) $(INC) -o main main.c

.PHONY: clean
clean:
	rm -f main
