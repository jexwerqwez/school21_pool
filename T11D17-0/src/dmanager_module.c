#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "door_struct.h"

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT; j++) {
            if (doors[j+1].id < doors[j].id) {
                struct door tmp = doors[j+1];
                doors[j+1] = doors[j];
                doors[j] = tmp;
            }
            if (doors[i].status == 1)
                doors[i].status = 0;
        }
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; ++i) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}
