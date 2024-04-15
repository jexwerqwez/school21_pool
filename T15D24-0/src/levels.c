#include "levels.h"
int get_records_level(FILE *pfile) {
    return getsize(pfile) / sizeof(levels);
}

void print_level(FILE *fp, int size) {
    levels data;
    int pos = 0;
    printf("=========================================\n");
    while (fread(&data, sizeof(levels), 1, fp)) {
        if (pos == size) {
            break;
        } else {
            printf("%d %d %d\n", data.lvl_memory_level, data.cell_count, data.protect_flag);
        }
        pos++;
    }
    printf("=========================================\n");
}

void write_record_in_levels(FILE *pfile, const levels *record_to_write, int index) {
    int offset = index * sizeof(levels);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(levels), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void insert_levels(FILE *fp, int index) {
    levels newnote;
    printf("Please write an note LVL COUNT FLAG: ");
    scanf("%d %d %d", &(newnote.lvl_memory_level), &(newnote.cell_count), &(newnote.protect_flag));
    write_record_in_levels(fp, &newnote, index);
}

levels read_record_from_level(FILE *pfile, int index) {
    int offset = index * sizeof(levels);
    fseek(pfile, offset, SEEK_SET);
    levels record;
    fread(&record, sizeof(levels), 1, pfile);
    rewind(pfile);
    return record;
}

int delete_levels(FILE* fp, char* filename, int size, int l_m) {
    int index = 0;
    FILE* tempfile;
    if ((tempfile = fopen("temp", "wb")) == NULL) {
        index = -1;
    } else {
        for (int i = 0; i < size; i++) {
            levels position = read_record_from_level(fp, i);
            printf("%d\n", position.lvl_memory_level);
            if (position.lvl_memory_level != l_m)
                fwrite(&position, sizeof(position), 1 , tempfile);
        }
        fclose(tempfile);
        tempfile = fopen("temp", "rb");
        rename("temp", filename);
        fclose(tempfile);
        remove("temp");
    }
    return index;
}

void swap_records_in_level(FILE *pfile, int record_index1, int record_index2) {
    levels record1 = read_record_from_level(pfile, record_index1);
    levels record2 = read_record_from_level(pfile, record_index2);
    write_record_in_levels(pfile, &record1, record_index2);
    write_record_in_levels(pfile, &record2, record_index1);
}

void sort_level(FILE *fp) {
    int size = get_records_level(fp);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            levels record1 = read_record_from_level(fp, j);
            levels record2 = read_record_from_level(fp, j+1);
            if (record1.lvl_memory_level > record2.lvl_memory_level)
                swap_records_in_level(fp, j, j+1);
        }
    }
}
