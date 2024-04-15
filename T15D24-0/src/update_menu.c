#include "modules.h"
#include "levels.h"
#include "state_events.h"
#include "shared.h"
int update_modules_menu() {
    int exit_flag = 0;
    int rec_num = 0;
    FILE* fp1;
    if ((fp1 = fopen("../materials/master_modules.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        printf("Please write an index: ");
        scanf("%d", &rec_num);
        insert_module(fp1, rec_num);
        fclose(fp1);
    }
    return exit_flag;
}

int update_levels_menu() {
    int exit_flag = 0;
    int rec_num = 0;
    FILE* fp2;
    if ((fp2 = fopen("../materials/master_levels.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        printf("Please write an index: ");
        scanf("%d", &rec_num);
        insert_levels(fp2, rec_num);
        fclose(fp2);
    }
    return exit_flag;
}

int update_statevents_menu() {
    int exit_flag = 0;
    int rec_num = 0;
    FILE* fp3;
    if ((fp3 = fopen("../materials/master_status_events.db", "r+b")) == NULL) {
        exit_flag = error();
    } else {
        printf("Please write an index: ");
        scanf("%d", &rec_num);
        insert_statevents(fp3, rec_num);
        fclose(fp3);
    }
    return exit_flag;
}
