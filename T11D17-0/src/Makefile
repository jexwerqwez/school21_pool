CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: door_struct list_test stack_test

door_struct: dmanager_module.o
	$(CC) dmanager_module.o -o ../build/Quest_1
list_test: list_test.o list.o
	$(CC) list_test.o list.o -o ../build/Quest_2
stack_test: stack_test.o stack.o
	$(CC) stack_test.o stack.o -o ../build/Quest_3

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) dmanager_module.c
list_test.o: list_test.c
	$(CC) $(CFLAGS) list_test.c
list.o: list.c
	$(CC) $(CFLAGS) list.c
stack.o: stack.c
	$(CC) $(CFLAGS) stack.c
stack_test.o: stack_test.c
	$(CC) $(CFLAGS) stack_test.c

clean:
	rm -rf *.o

rebuild:
	rm -rf *.o all