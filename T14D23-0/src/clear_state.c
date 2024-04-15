#include "clear_state.h"
#include "binary_functions.h"

int main() {
    FILE* fp;
    char filename[SIZE-10];
    char fullname[SIZE];
    int exit_flag = 0;
    scanf("%s", filename);
    snprintf(fullname, sizeof fullname, "%s%s", "../", filename);
    if ((fp = fopen(fullname, "rb")) == NULL) {
        exit_flag = error();
    } else {
        if (getsize(fp) == 0) {
            exit_flag = error();
        } else {
            exit_flag = clear_state(fp, fullname);
        }
    }
    fclose(fp);
    return exit_flag;
}

int error(void) {
    printf("n/a");
    return -1;
}

int clear_state(FILE *fp, char* filename) {
    int exit_flag = 0;
    int start_d, start_m, start_y;
    int fin_d, fin_m, fin_y;
    FILE* tempfile;
    int start_index = 0;
    int finish_index = 0;
    if (scanf("%d%*1[.]%d%*1[.]%d", &start_d, &start_m, &start_y) != 3 ||
        scanf("%d%*1[.]%d%*1[.]%d", &fin_d, &fin_m, &fin_y) != 3) {
             exit_flag = error();
    } else {
        if ((tempfile = fopen("temp", "wb")) == NULL) {
            exit_flag = error();
        } else {
            int size = get_records_count_in_file(fp);
            start_index = getpose(fp, start_d, start_m, start_y, size);
            finish_index = getpose(fp, fin_d, fin_m, fin_y, size);
            rewind(fp);
            for (int i = 0; i < size; i++) {
                if (i < start_index || i > finish_index) {
                    struct state record = read_record_from_file(fp, i);
                    fwrite(&record, sizeof(struct state), 1, tempfile);
                }
            }
            fclose(tempfile);
            tempfile = fopen("temp", "rb");
            printfile(tempfile);
            rename("temp", filename);
            fclose(tempfile);
            remove("temp");
        }
    }
    return exit_flag;
}

int search(FILE* fp, int d, int m, int y) {
    struct state record;
    int result = 0;
    while (fread(&record, sizeof(struct state), 1, fp)) {
        if (record.year == y && record.month == m && record.day == d) {
            result = record.code;
        }
    }
    return result;
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

int getpose(FILE* fp, int day, int month, int year, int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        struct state position = read_record_from_file(fp, i);
        if (position.year == year && position.month == month && position.day == day) {
            index = i;
            break;
        }
    }
    return index;
}
