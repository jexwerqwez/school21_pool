CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

all: data_base

data_base: modules_db.o shared.o modules.o select_menu.o levels.o state_events.o insert_menu.o update_menu.o delete_menu.o
	$(CC) modules_db.o shared.o modules.o select_menu.o levels.o state_events.o insert_menu.o update_menu.o delete_menu.o -o ./data_base

modules_db.o: modules_db.c
	$(CC) $(CFLAGS) modules_db.c
shared.o: shared.c
	$(CC) $(CFLAGS) shared.c
modules.o: modules.c
	$(CC) $(CFLAGS) modules.c
levels.o: levels.c
	$(CC) $(CFLAGS) levels.c
state_events.o: state_events.c
	$(CC) $(CFLAGS) state_events.c
select_menu.o: select_menu.c
	$(CC) $(CFLAGS) select_menu.c
insert_menu.o: insert_menu.c
	$(CC) $(CFLAGS) insert_menu.c
update_menu.o: update_menu.c
	$(CC) $(CFLAGS) update_menu.c
delete_menu.o: delete_menu.c
	$(CC) $(CFLAGS) delete_menu.c

clean:
	rm -rf *.o ./data_base
rebuild:
	rm -rf *.o
	make all