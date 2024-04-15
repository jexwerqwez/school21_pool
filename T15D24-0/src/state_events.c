#include "state_events.h"
int get_records_statevents(FILE *pfile) {
    return getsize(pfile) / sizeof(status_events);
}

void print_statevents(FILE *fp, int size) {
    status_events data;
    int pos = 0;
    printf("=========================================\n");
    while (fread(&data, sizeof(status_events), 1, fp)) {
        if (pos == size) {
            break;
        } else {
            printf("%d %d %d %s %s\n", data.event_id, data.module_id,
                data.new_status, data.change_date, data.change_time);
        }
        pos++;
    }
    printf("=========================================\n");
}

void write_record_in_statevents(FILE *pfile, const status_events *record_to_write, int index) {
    int offset = index * sizeof(status_events);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(status_events), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void insert_statevents(FILE *fp, int index) {
    status_events newnote;
    printf("Please write an note EVENT_ID MODULE_ID STATUS DATE TIME: ");
    scanf("%10d %10d %15d %20s %20s", &(newnote.event_id), &(newnote.module_id),
        &(newnote.new_status), newnote.change_date, newnote.change_time);
    write_record_in_statevents(fp, &newnote, index);
}

status_events read_record_from_statevents(FILE *pfile, int index) {
    int offset = index * sizeof(status_events);
    fseek(pfile, offset, SEEK_SET);
    status_events record;
    fread(&record, sizeof(status_events), 1, pfile);
    rewind(pfile);
    return record;
}

int delete_statevents(FILE* fp, char* filename, int size, int e_i) {
    int index = 0;
    FILE* tempfile;
    if ((tempfile = fopen("temp", "wb")) == NULL) {
        index = -1;
    } else {
        for (int i = 0; i < size; i++) {
            status_events position = read_record_from_statevents(fp, i);
            fwrite(&position, sizeof(position), 1 , tempfile);
            if (position.event_id == e_i) {
                continue;
            }
        }
        fclose(tempfile);
        tempfile = fopen("temp", "rb");
        rename("temp", filename);
        fclose(tempfile);
        remove("temp");
    }
    return index;
}

void swap_records_in_statevents(FILE *pfile, int record_index1, int record_index2) {
    status_events record1 = read_record_from_statevents(pfile, record_index1);
    status_events record2 = read_record_from_statevents(pfile, record_index2);
    write_record_in_statevents(pfile, &record1, record_index2);
    write_record_in_statevents(pfile, &record2, record_index1);
}

void sort_statevents(FILE *fp) {
    int size = get_records_statevents(fp);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            status_events record1 = read_record_from_statevents(fp, j);
            status_events record2 = read_record_from_statevents(fp, j+1);
            if (record1.event_id > record2.event_id)
                swap_records_in_statevents(fp, j, j+1);
        }
    }
}
