CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: state_sort state_search clear_state

state_sort.o: state_sort.c
	$(CC) $(CFLAGS) state_sort.c
binary_functions.o: binary_functions.c
	$(CC) $(CFLAGS) binary_functions.c
state_search.o: state_search.c
	$(CC) $(CFLAGS) state_search.c
clear_state.o: clear_state.c
	$(CC) $(CFLAGS) clear_state.c

state_sort: state_sort.o binary_functions.o
	$(CC) state_sort.o binary_functions.o -o ../build/Quest_1
state_search: state_search.o binary_functions.o
	$(CC) state_search.o binary_functions.o -o ../build/Quest_2
clear_state: clear_state.o binary_functions.o
	$(CC) clear_state.o binary_functions.o -o ../build/Quest_3

clean:
	rm -rf *.o ../build/Quest_1
	rm -rf *.o ../build/Quest_2
	rm -rf *.o ../build/Quest_3
rebuild:
	rm -rf *.o
	make all
