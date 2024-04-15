#ifndef SRC_LEVELS_H_
#define SRC_LEVELS_H_
#include <stdio.h>
#include <string.h>
typedef struct {
    int lvl_memory_level;
    int cell_count;
    int protect_flag;
} levels;
void print_level(FILE *fp, int size);
int get_records_level(FILE *pfile);
int getsize(FILE* fp);
void write_record_in_levels(FILE *pfile, const levels *record_to_write, int index);
void insert_levels(FILE *fp, int index);
int getpose_levels(FILE* fp, int l_m, int c_c, int p_f);
levels read_record_from_level(FILE *pfile, int index);
int upd_levels(FILE* fp, char* filename, int l_m, int c_c, int p_f, int size);
int delete_levels(FILE* fp, char* filename, int size, int idd);
int error(void);
void sort_level(FILE *fp);
void swap_records_in_level(FILE *pfile, int record_index1, int record_index2);
#endif  // SRC_LEVELS_H_
