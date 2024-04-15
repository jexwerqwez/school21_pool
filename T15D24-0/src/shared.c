#include "select_menu.h"
#include "insert_menu.h"
#include "update_menu.h"
#include "delete_menu.h"
#include "shared.h"

void select_menu() {
    int table = 0;
    printf("=========================================\n");
    printf("Please choose a table:\n");
    printf("1. Modules\n2. Levels\n3. Status events\n");
    printf("=========================================\n");
    while (scanf("%d", &table) != 1 || (table != 1 && table != 2 && table != 3)) {
        while (getchar() != '\n')
            printf("Please choose a table:\n");
    }
    switch (table) {
        case 1:
            modules_menu();
            break;
        case 2:
            levels_menu();
            break;
        case 3:
            statevents_menu();
            break;
    }
}

void insert_menu() {
    int table = 0;
    printf("=========================================\n");
    printf("Please choose a table:\n");
    printf("1. Modules\n2. Levels\n3. Status events\n");
    printf("=========================================\n");
    while (scanf("%d", &table) != 1 || (table != 1 && table != 2 && table != 3)) {
        while (getchar() != '\n')
            printf("Please choose a table:\n");
    }
    switch (table) {
        case 1:
            insert_modules_menu();
            break;
        case 2:
            insert_levels_menu();
            break;
        case 3:
            insert_statevents_menu();
            break;
    }
}

void update_menu() {
    int table = 0;
    printf("=========================================\n");
    printf("Please choose a table:\n");
    printf("1. Modules\n2. Levels\n3. Status events\n");
    printf("=========================================\n");
    while (scanf("%d", &table) != 1 || (table != 1 && table != 2 && table != 3)) {
        while (getchar() != '\n')
            printf("Please choose a table:\n");
    }
    switch (table) {
        case 1:
            update_modules_menu();
            break;
        case 2:
            update_levels_menu();
            break;
        case 3:
            update_statevents_menu();
            break;
    }
}

void delete_menu() {
    int table = 0;
    printf("=========================================\n");
    printf("Please choose a table:\n");
    printf("1. Modules\n2. Levels\n3. Status events\n");
    printf("=========================================\n");
    while (scanf("%d", &table) != 1 || (table != 1 && table != 2 && table != 3)) {
        while (getchar() != '\n')
            printf("Please choose a table:\n");
    }
    switch (table) {
        case 1:
            delete_modules_menu();
            break;
        case 2:
            delete_levels_menu();
            break;
        case 3:
            delete_statevents_menu();
            break;
    }
}
