CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: add-nbo

add-nbo: add-nbo.c
	$(CC) $(CFLAGS) -o add-nbo add-nbo.c

clean:
	rm -f add-nbo
