#include "modules.h"

int get_records_module(FILE *pfile) {
    return getsize(pfile) / sizeof(modules);
}

void print_module(FILE *fp, int size) {
    modules data;
    int pos = 0;
    printf("=========================================\n");
    while (fread(&data, sizeof(modules), 1, fp)) {
        if (pos == size) {
            break;
        } else {
            printf("%d %20s %5d %2d %2d\n", data.id, data.name, data.mod_memory_level,
                data.cell_num, data.delete_flag);
        }
        pos++;
    }
    printf("=========================================\n");
}

void write_record_in_module(FILE *pfile, const modules *record_to_write, int index) {
    int offset = index * sizeof(modules);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(modules), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void insert_module(FILE *fp, int index) {
    modules newnote;
    printf("Please write a note: ID NAME LVL NUM FLAG ");
    scanf("%d %20s %5d %2d %2d", &(newnote.id), newnote.name, &(newnote.mod_memory_level),
        &(newnote.cell_num), &(newnote.delete_flag));
    write_record_in_module(fp, &newnote, index);
}

modules read_record_from_module(FILE *pfile, int index) {
    int offset = index * sizeof(modules);
    fseek(pfile, offset, SEEK_SET);
    modules record;
    fread(&record, sizeof(modules), 1, pfile);
    rewind(pfile);
    return record;
}

int delete_module(FILE* fp, char* filename, int size, int idd) {
    int index = 0;
    FILE* tempfile;
    if ((tempfile = fopen("temp", "wb")) == NULL) {
        index = -1;
    } else {
        rewind(fp);
        for (int i = 0; i < size; i++) {
            modules position = read_record_from_module(fp, i);
            if (position.id != idd) {
                fwrite(&position, sizeof(position), 1 , tempfile);
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

void swap_records_in_module(FILE *pfile, int record_index1, int record_index2) {
    modules record1 = read_record_from_module(pfile, record_index1);
    modules record2 = read_record_from_module(pfile, record_index2);
    write_record_in_module(pfile, &record1, record_index2);
    write_record_in_module(pfile, &record2, record_index1);
}

void sort_module(FILE *fp) {
    int size = get_records_module(fp);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            modules record1 = read_record_from_module(fp, j);
            modules record2 = read_record_from_module(fp, j+1);
            if (record1.id > record2.id)
                swap_records_in_module(fp, j, j+1);
        }
    }
}
