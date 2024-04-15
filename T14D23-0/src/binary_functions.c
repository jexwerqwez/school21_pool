#include "binary_functions.h"

int getsize(FILE* fp) {
    int size = 0;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    return size;
}

int get_records_count_in_file(FILE *pfile) {
    return getsize(pfile) / sizeof(struct state);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct state record1 = read_record_from_file(pfile, record_index1);
    struct state record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

void write_record_in_file(FILE *pfile, const struct state *record_to_write, int index) {
    int offset = index * sizeof(struct state);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct state), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

struct state read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct state);
    fseek(pfile, offset, SEEK_SET);
    struct state record;
    fread(&record, sizeof(struct state), 1, pfile);
    rewind(pfile);
    return record;
}

