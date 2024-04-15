#ifndef SRC_STATE_SORT_H_
#define SRC_STATE_SORT_H_
#include <stdio.h>
#define SIZE 256
#define RECORDSIZE 8

void sort(FILE *fp);
int error(void);
void menu(int mode, FILE* fp);
void printfile(FILE *fp);
void write(FILE *fp, int index);

#endif  // SRC_STATE_SORT_H_
