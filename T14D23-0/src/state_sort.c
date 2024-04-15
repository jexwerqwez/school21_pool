#include "state_sort.h"
#include "binary_functions.h"

int main() {
    FILE *fp;
    char filename[SIZE-10];
    char fullname[SIZE];
    int mode = 0;
    int exit_flag = 0;
    int size = 0;
    scanf("%s", filename);
    snprintf(fullname, sizeof fullname, "%s%s", "../", filename);
    if ((fp = fopen(fullname, "r+b")) == NULL) {
        exit_flag = error();
    } else {
        if ( (scanf("%d", &mode) != 1) || (mode != 1 && mode != 0 && mode != 2) ) {
            exit_flag = error();
        } else {
            if (((size = getsize(fp)) == 0) && (mode != 2)) {
                exit_flag = error();
            } else {
                menu(mode, fp);
            }
        }
    }
    return exit_flag;
}

int error(void) {
    printf("n/a");
    return -1;
}

void menu(int mode, FILE* fp) {
    int index = get_records_count_in_file(fp);
    if (mode == 0) {
        printfile(fp);
    } else if (mode == 1) {
        sort(fp);
        printfile(fp);
    } else if (mode == 2) {
        write(fp, index);
        sort(fp);
        printfile(fp);
    }
    fclose(fp);
}

void sort(FILE *fp) {
    int size = get_records_count_in_file(fp);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            struct state record1 = read_record_from_file(fp, j);
            struct state record2 = read_record_from_file(fp, j+1);
            long int first = (long)record1.year*12*31*24*60*60+record1.month*31*24*60*60+
                record1.day*24*60*60+record1.hour*60*60+record1.min*60+record1.sec;
            long int second = (long)record2.year*12*31*24*60*60+record2.month*31*24*60*60+
                record2.day*24*60*60+record2.hour*60*60+record2.min*60+record2.sec;
            if (first > second)
                swap_records_in_file(fp, j, j+1);
        }
    }
}

void printfile(FILE *fp) {
    struct state data;
    int pos = 0;
    int size = get_records_count_in_file(fp);
    while (fread(&data, sizeof(struct state), 1, fp)) {
        if (pos == size-1) {
            printf("%d %d %d %d %d %d %d %d", data.year,
                            data.month, data.day, data.hour, data.min, data.sec, data.stat, data.code);
        } else {
            printf("%d %d %d %d %d %d %d %d\n", data.year,
                data.month, data.day, data.hour, data.min, data.sec, data.stat, data.code);
        }
        pos++;
    }
}

void write(FILE *fp, int index) {
    struct state newnote;
    scanf("%d %d %d %d %d %d %d %d", &(newnote.year), &(newnote.month), &(newnote.day),
        &(newnote.hour), &(newnote.min), &(newnote.sec), &(newnote.stat), &(newnote.code));
    write_record_in_file(fp, &newnote, index);
}
