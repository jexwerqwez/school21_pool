CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: build

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) ../data_libs/data_io.c
data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) ../data_libs/data_stat.c
data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) ../data_module/data_process.c
decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) ../yet_another_decision_module/decision.c
main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) main_executable_module.c

data_stat.a: data_stat.o 
	ar rcs data_stat.a data_stat.o

data_process.so: ../data_module/data_process.c
	$(CC) -shared -o data_process.so -c -fPIC ../data_module/data_process.c

Quest_3: main_executable_module.o data_process.o decision.o data_stat.o data_io.o
	$(CC) main_executable_module.o data_process.o decision.o data_stat.o data_io.o -o ../../build/Quest_3

build_with_static: main_executable_module.o data_process.o decision.o data_io.o data_stat.a
	$(CC) main_executable_module.o data_process.o decision.o data_io.o data_stat.a -o ../../build/Quest_5

build_with_dynamic: main_executable_module.o decision.o data_stat.o data_process.so data_io.o
	$(CC) main_executable_module.o decision.o data_stat.o data_process.so data_io.o -o ../../build/Quest_6

clean:
	rm -rf *.o *.a *.so

rebuild: rm -rf *.o *.a *.so all
