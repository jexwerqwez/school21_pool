#include "graph_drawing.h"

void fill_field(char field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            field[i][j] = '.';
}

void print_field(char field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT - 1; ++i) {
        for (int j = 0; j < WIDTH; ++j)
            printf("%c", field[i][j]);
        printf("\n");
    }
    for (int j = 0; j < WIDTH; ++j)
        printf("%c", field[HEIGHT - 1][j]);
}

void draw(stack_ty *stack) {
    char field[HEIGHT][WIDTH];
    fill_field(field);
    double x = 0.0;
    for (int i = 0; i < WIDTH; x += 4 * pi / WIDTH, ++i) {
        double y = calc(stack, x);
        if (fabs(y) < 1 + eps)
            field[(int) round(HEIGHT / 2 - y * (HEIGHT / 2))][i] = '*';
    }
    print_field(field);
}
