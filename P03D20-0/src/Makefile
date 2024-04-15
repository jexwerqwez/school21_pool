CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: expression_calculation.o expression_parsing.o graph_drawing.o graph.o stack.o
	$(CC) expression_calculation.o expression_parsing.o graph_drawing.o graph.o stack.o -o ../build/graph

expression_calculation.o: expression_calculation.c
	$(CC) $(CFLAGS) expression_calculation.c

expression_parsing.o: expression_parsing.c
	$(CC) $(CFLAGS) expression_parsing.c

graph_drawing.o: graph_drawing.c
	$(CC) $(CFLAGS) graph_drawing.c

graph.o: graph.c
	$(CC) $(CFLAGS) graph.c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

clean: 
	rm -rf *.o ../build/graph

rebuild:
	rm -rf *.o
	make all