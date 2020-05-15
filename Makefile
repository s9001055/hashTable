$(CC):=gcc

all:
	$(CC) -Wall -g -o hashTable.out hashTable.c

.PHONY:clean
clean:
	rm hashTable.out
