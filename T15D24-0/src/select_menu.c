#include "modules.h"
#include "levels.h"
#include "state_events.h"
#include "shared.h"
int modules_menu() {
    int exit_flag = 0;
    FILE* fp1;
    if ((fp1 = fopen("../materials/master_modules.db", "rb")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_module(fp1);
        printf("Insert the number of records or leave empty to output all of them: ");
        scanf("%d", &rec_num);
        print_module(fp1, rec_num);
        fclose(fp1);
    }
    return exit_flag;
}

int levels_menu() {
    int exit_flag = 0;
    FILE* fp2;
    if ((fp2 = fopen("../materials/master_levels.db", "rb")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_level(fp2);
        printf("Insert the number of records or leave empty to output all of them: ");
        scanf("%d", &rec_num);
        print_level(fp2, rec_num);
        fclose(fp2);
    }
    return exit_flag;
}

int statevents_menu() {
    int exit_flag = 0;
    FILE* fp3;
    if ((fp3 = fopen("../materials/master_status_events.db", "rb")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_statevents(fp3);
        printf("Insert the number of records or leave empty to output all of them: ");
        scanf("%d", &rec_num);
        print_statevents(fp3, rec_num);
        fclose(fp3);
    }
    return exit_flag;
}


int error(void) {
    printf("n/a");
    return -1;
}
int getsize(FILE* fp) {
    int size = 0;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    return size;
}
