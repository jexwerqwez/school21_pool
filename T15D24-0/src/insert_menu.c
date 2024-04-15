#include "modules.h"
#include "levels.h"
#include "state_events.h"
#include "shared.h"

int insert_modules_menu() {
    int exit_flag = 0;
    FILE* fp1;
    if ((fp1 = fopen("../materials/master_modules.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_module(fp1);
        insert_module(fp1, rec_num);
        sort_module(fp1);
        fclose(fp1);
    }
    return exit_flag;
}

int insert_levels_menu() {
    int exit_flag = 0;
    FILE* fp2;
    if ((fp2 = fopen("../materials/master_levels.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_level(fp2);
        insert_levels(fp2, rec_num);
        sort_level(fp2);
        fclose(fp2);
    }
    return exit_flag;
}

int insert_statevents_menu() {
    int exit_flag = 0;
    FILE* fp3;
    if ((fp3 = fopen("../materials/master_status_events.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_statevents(fp3);
        insert_statevents(fp3, rec_num);
        sort_statevents(fp3);
        fclose(fp3);
    }
    return exit_flag;
}
