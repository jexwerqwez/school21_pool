CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: cipher logging_cipher

cipher.o: cipher.c
	$(CC) $(CFLAGS) cipher.c
logger.o: logger.c
	$(CC) $(CFLAGS) logger.c

cipher: cipher.o
	$(CC) cipher.o -o ../build/cipher

logging_cipher: logger.o logger_lib.o
	$(CC) logger.o logger_lib.o -o ../build/logging_cipher
logger_lib.o: cipher.c
	$(CC) $(CFLAGS) -D LOGGER_LIB cipher.c -o logger_lib.o

clean:
	rm -rf *.o ../build/cipher
	rm -rf *.o ../build/logging_cipher

rebuild:
	rm -rf *.o
	make all
