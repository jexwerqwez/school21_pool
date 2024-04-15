#include "shared.h"

int main() {
    int operation = 0;
    int exit_flag = 1;
    while (exit_flag) {
        printf("=========================================\n");
        printf("Please choose one operation:\n");  // заголовок
        printf("1. SELECT\n2. INSERT\n3. UPDATE\n4. DELETE\n");  // стандартные операции
        printf("-1. EXIT\n");
        printf("=========================================\n");
        while (scanf("%d", &operation) != 1 || (operation != 1 && operation != 2 &&
            operation != 3  && operation != 4 && operation != -1)) {
                while (getchar() != '\n')
                    printf("Please choose one operation:\n");
            }
        switch (operation) {
            case 1:
                select_menu();
                break;
            case 2:
                insert_menu();
                break;
            case 3:
                update_menu();
                break;
            case 4:
            delete_menu();
                break;
            case -1:
            exit_flag = 0;
            break;
        }
    }
    return 0;
}
