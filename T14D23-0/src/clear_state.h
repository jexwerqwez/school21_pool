#ifndef SRC_CLEAR_STATE_H_
#define SRC_CLEAR_STATE_H_
#include <stdio.h>
#define SIZE 256
void printfile(FILE *fp);
int clear_state(FILE *fp, char* filename);
int error(void);
int getpose(FILE* fp, int day, int month, int year, int size);
#endif  // SRC_CLEAR_STATE_H_
