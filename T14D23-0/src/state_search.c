#include "state_search.h"
#include "binary_functions.h"

int main() {
    FILE* fp;
    char filename[SIZE-10];
    char fullname[SIZE];
    int exit_flag = 0;
    int d, m, y;
    scanf("%s", filename);
    snprintf(fullname, sizeof fullname, "%s%s", "../", filename);
    if ((fp = fopen(fullname, "rb")) == NULL) {
        exit_flag = error();
    } else {
        if (scanf("%d%*1[.]%d%*1[.]%d", &d, &m, &y) != 3) {
            exit_flag = error();
        } else {
            int answer = search(fp, d, m, y);
            if (answer == 0) {
                exit_flag = error();
            } else {
                printf("%d", answer);
            }
            fclose(fp);
        }
    }
    return exit_flag;
}

int error(void) {
    printf("n/a");
    return -1;
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
