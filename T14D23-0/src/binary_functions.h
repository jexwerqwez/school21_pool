#ifndef SRC_BINARY_FUNCTIONS_H_
#define SRC_BINARY_FUNCTIONS_H_
#include <stdio.h>
struct state {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int stat;
    int code;
};
int getsize(FILE* fp);
int get_records_count_in_file(FILE *pfile);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
void write_record_in_file(FILE *pfile, const struct state *record_to_write, int index);
struct state read_record_from_file(FILE *pfile, int index);

#endif  // SRC_BINARY_FUNCTIONS_H_
