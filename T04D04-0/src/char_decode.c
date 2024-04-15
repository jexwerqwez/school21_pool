#include <stdio.h>

int code(void);
int decode(void);

int main(int argc, char* argv[]) {
    if (argc < 2)
        return -1;
    if ( argv[1][0] != '0' && argv[1][0] != '1' ) {
        return -2;
    } else {
        if (argv[1][0] == '0')
            code();
        else
            decode();
    }
}

int code(void) {
    char c1, c2;
    while ( c2 != '\n' ) {
        scanf("%c%c", &c1, &c2);
        if (c2 != ' ' && c2 != '\n') {
            printf("n/a");
            return -3;
        } else {
            printf("%2X%c", (int)c1, c2);
        }
    }
    return 0;
}

int decode(void) {
    unsigned int c1;
    char c2;
    while ( c2 != '\n' ) {
        scanf("%2X%c", &c1, &c2);
        if (c2 != ' ' && c2 != '\n') {
            printf("n/a");
            return -3;
        } else {
            printf("%c%C", c1, c2);
        }
    }
    return 0;
}
