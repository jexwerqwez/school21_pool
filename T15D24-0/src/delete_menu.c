#include "modules.h"
#include "levels.h"
#include "state_events.h"
#include "shared.h"
int delete_modules_menu() {
    int exit_flag = 0;
    int del_id = 0;
    FILE* fp1;
    if ((fp1 = fopen("../materials/master_modules.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_module(fp1);
        printf("Please choose an index: ");
        scanf("%d", &del_id);
        delete_module(fp1, "../materials/master_modules.db", rec_num, del_id);
        fclose(fp1);
    }
    return exit_flag;
}

int delete_levels_menu() {
    int exit_flag = 0;
    int del_id = 0;
    FILE* fp2;
    if ((fp2 = fopen("../materials/master_levels.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_level(fp2);
        printf("Please choose an index: ");
        scanf("%d", &del_id);
        delete_levels(fp2, "../materials/master_levels.db", rec_num, del_id);
        fclose(fp2);
    }
    return exit_flag;
}

int delete_statevents_menu() {
    int exit_flag = 0;
    int del_id = 0;
    FILE* fp3;
    if ((fp3 = fopen("../materials/master_status_events.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        int rec_num = get_records_statevents(fp3);
        printf("Please choose an index: ");
        scanf("%d", &del_id);
        delete_statevents(fp3, "../materials/master_status_events.db",
            rec_num, del_id);
        fclose(fp3);
    }
    return exit_flag;
}
