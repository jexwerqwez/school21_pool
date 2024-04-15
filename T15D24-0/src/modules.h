#ifndef SRC_MODULES_H_
#define SRC_MODULES_H_
#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[30];
    int mod_memory_level;  // Номер уровня памяти,  где находится модуль (int);
    int cell_num;  // Номер ячейки, где находится модуль на данном уровне (int);
    int delete_flag;
} modules;
int get_records_module(FILE *pfile);
int getsize(FILE* fp);
void print_module(FILE *fp, int size);
void insert_module(FILE *fp, int index);
void write_record_in_module(FILE *pfile, const modules *record_to_write, int index);
modules read_record_from_module(FILE *pfile, int index);
int upd_module(FILE* fp, char* filename, int idd, char* n, int m_l, int c_n, int d_f, int size);
int delete_module(FILE* fp, char* filename, int size, int idd);
void swap_records_in_module(FILE *pfile, int record_index1, int record_index2);
void sort_module(FILE *fp);
#endif  // SRC_MODULES_H_
