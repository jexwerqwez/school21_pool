#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

struct door {
    int id;
    int status;
};

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void output(struct door* doors);
#endif  // SRC_DOOR_STRUCT_H_
