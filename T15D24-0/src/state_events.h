#ifndef SRC_STATE_EVENTS_H_
#define SRC_STATE_EVENTS_H_
#include <stdio.h>
#include <string.h>
typedef struct {
    int event_id;
    int module_id;
    int new_status;
    char change_date[10+1];
    char change_time[8+1];
} status_events;
void print_statevents(FILE *fp, int size);
int get_records_statevents(FILE *pfile);
int getsize(FILE* fp);
void write_record_in_statevents(FILE *pfile, const status_events *record_to_write, int index);
void insert_statevents(FILE *fp, int index);
int upd_statevents(FILE* fp, char* filename, int e_i, int m_i, int n_s, char* c_d, char* c_t, int size);
status_events read_record_from_statevents(FILE *pfile, int index);
int delete_statevents(FILE* fp, char* filename, int size, int e_i);
int error(void);
void swap_records_in_statevents(FILE *pfile, int record_index1, int record_index2);
void sort_statevents(FILE *fp);
#endif  // SRC_STATE_EVENTS_H_
