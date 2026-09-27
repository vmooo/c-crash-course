.PHONY: all build clean task1 task2 task3

CC = clang
CFLAGS = -Wall -Wextra -Werror -std=c17

all: build

build: task1 task2 task3

task1: task1.c
	$(CC) $(CFLAGS) task1.c -o task1

task2: task2.c
	$(CC) $(CFLAGS) task2.c -o task2

task3: task3.c
	$(CC) $(CFLAGS) task3.c -o task3

task4: task4.c
	$(CC) $(CFLAGS) task4.c -o task4

clean:
	rm -rf *.o task1 task2 task3
