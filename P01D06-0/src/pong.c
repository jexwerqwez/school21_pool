#include <stdio.h>

void display(int r1, int r2, int bx, int by, int counter_r1, int counter_r2);
int x_touch_fixation(int bx_v, int bx, int r1, int r2, int by);
int y_touch_fixation(int by_v, int by);
int start(void);

int main() {
    int r1 = 13;      // начальные положения ракеток
    int r2 = 13;
    int bx = 40;
    int by = 12;      // начальное положение шарика
    int bx_v = 1;      // вектора движения шарика
    int by_v = 1;
    int counter_r1 = 0;      // счет
    int counter_r2 = 0;
    char ch;
    while (1) {
        scanf("%c", &ch);
    if (ch != '\n') {
        if ((ch == 'A' || ch == 'a') &&  r1 != 2) {
            r1--;
        } else if ((ch == 'Z' || ch == 'z') && r1 != 22) { r1++;
        } else if ((ch == 'K' || ch == 'k') &&  r2 != 2) { r2--;
        } else if ((ch == 'M' || ch == 'm')&& r2 != 22) { r2++;
        } else if (ch == ' ') {
        } else {
            printf("\033[0d\033[2J");
            display(r1, r2, bx, by, counter_r1, counter_r2);
            bx -= bx_v;
            by -= by_v;
        }
        bx_v = x_touch_fixation(bx_v, bx, r1, r2, by);
        by_v = y_touch_fixation(by_v, by);
        bx += bx_v;
        by += by_v;
        if (bx < 1 || bx > 81) {
            if (bx < 1) {
                counter_r2++;
            } else {counter_r1++;}
            bx = 40;
            by = 13;
            bx_v *= -1;
            }
        display(r1, r2, bx, by, counter_r1, counter_r2);
        if (counter_r1 == 21 || counter_r2 == 21) {
            break;
        }
        } else {
            printf("\033[0d\033[2J");
            display(r1, r2, bx, by, counter_r1, counter_r2);
        }
    }
    return 0;
}


int x_touch_fixation(int bx_v, int bx, int r1, int r2, int by) {
    if (bx == 2 && (by == r1 || by == r1 + 1 || by == r1 - 1)) {
        bx_v = 1;
    } else if (bx == 79 && (by == r2 || by == r2 + 1 || by == r2 - 1 )) {
        bx_v = -1;
    }
    return bx_v;
}

int y_touch_fixation(int by_v, int by) {
    if (by == 1) {
        by_v = 1;
    } else if (by == 23) {
        by_v = -1;
    }
    return by_v;
}

void display(int r1, int r2, int bx, int by, int counter_r1, int counter_r2) {
    printf("\033[0d\033[2J");
    if (counter_r1 == 21 || counter_r2 == 21) {
            printf("\033[0d\033[2J");
            if (counter_r1 == 21) {                                 // ฅ(^◕ᴥ◕^)ฅ
                printf("%s\n", "                             LEFT PLAYER WINS!!!!");
            } else {printf("%s\n", "                            RIGHT PLAYER WINS!!!!");}
            } else {
                printf("                                     %d | %d\n", counter_r1, counter_r2);
            }
    for (int i = 1; i < 24; i++) {
        for (int j = 1; j < 81; j++) {
            if ((i == r1 - 1 || i == r1 || i == r1 + 1)  && j == 1) {
                printf("]");
            } else if ((i == r2 - 1  || i == r2 || i == r2 + 1) && j == 80) {
                printf("[");
            } else if (i == by && j == bx) {
                printf("●");
            } else if ( i %2 == 0 && j == 40 ) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
