#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define WIDTH 79 + 2
#define HEIGHT 25 + 2
#define TPS_UP_LIMIT 500
#define TPS_BASE_VALUE 30
#define TPS_DOWN_LIMIT 5
#define CHAR_ALIVE '*'
#define CHAR_DEAD ' '

void output(int width, int (*matrix)[width], int i_start, int i_end,
            int j_start, int j_end, char alive, char dead);
void calc_next(int width, int (*previous)[width], int (*next)[width],
               int i_start, int i_end, int j_start, int j_end);
void init_board(int width, int (*matrix)[width], int i_start, int i_end,
                int j_start, int j_end, int cell_type);
int random_board(int width, int (*matrix)[width], int i_start, int i_end,
                 int j_start, int j_end);
void copy_matrix(int width, int (*from)[width], int (*to)[width], int i_start,
                 int i_end, int j_start, int j_end);
int define_viability(int width, int (*matrix)[width], int i, int j);
int calc_population(int width, int (*matrix)[width], int i_start, int i_end,
                    int j_start, int j_end);
void init_shadow_cells(int width, int (*matrix)[width], int i_start, int i_end,
                       int j_start, int j_end);
int input_board(int width, int (*matrix)[width], int i_start, int i_end,
                int j_start, int j_end);
int game(int width, int (*previous)[width], int (*next)[width]);
void colors(void);

int main() {
    int flag = 0;
    int previous[HEIGHT][WIDTH], next[HEIGHT][WIDTH];
    init_board(WIDTH, previous, 0, HEIGHT, 0, WIDTH, 0);
    init_board(WIDTH, next, 0, HEIGHT, 0, WIDTH, 0);
    if (input_board(WIDTH, previous, 1, HEIGHT - 1, 1, WIDTH - 1)) {
        if (freopen("/dev/tty", "r", stdin) == NULL) {
            printf("Can't open file.\n");
            flag = -1;
        }
        game(WIDTH, previous, next);
    } else {
        game(WIDTH, previous, next);
    }
    nocbreak();
    refresh();
    curs_set(1);
    endwin();
    return flag;
}

int game(int width, int (*previous)[width], int (*next)[width]) {
    initscr();
    curs_set(0);
    noecho();
    raw();
    cbreak();
    timeout(40);
    int iteration = 1, tps = TPS_BASE_VALUE, quit = 0;
    while (1) {
        raw();
        char command;
        command = getch();
        switch (command) {
        case 'q': {
            raw();
            quit = 1;
            break;
            }
        case 'r': {
            if (tps != TPS_UP_LIMIT || tps != TPS_DOWN_LIMIT) {
                random_board(WIDTH, previous, 0, HEIGHT - 1, 0, WIDTH - 1);
                iteration = 1;
                refresh();
            } else {}
            break;
            }
        case '.': {
            if (tps != TPS_UP_LIMIT) tps += 5;
            break;
            }
        case ',': {
            if (tps != TPS_DOWN_LIMIT) tps -= 5;
            break;
            }
        case 'p': {
            printw("\nScript paused, to proceed, press any key");
            refresh();
            if (getchar() == 'q') quit = 1;
            break;
            }
        case 'c' : {
            start_color();
            colors();
            refresh();
            break;
            }
        }
        if (quit) break;
        calc_next(WIDTH, previous, next, 1, HEIGHT - 1, 1, WIDTH - 1);
        clear();
        output(WIDTH, next, 1, HEIGHT - 1, 1, WIDTH - 1, CHAR_ALIVE, CHAR_DEAD);
        printw("\nIteration: %d Population: %d TPS: %d\n", iteration,
        calc_population(WIDTH, next, 1, HEIGHT - 1, 1, WIDTH - 1), tps);
        printw("\n Q - quit         R - random generation            >< - speed");
        printw("\n P - pause        C - random color");
        refresh();
        iteration++;
        copy_matrix(WIDTH, next, previous, 0, HEIGHT, 0, WIDTH);
        usleep(1e6 / tps);
        }
    return 1;
}

int input_board(int width, int (*matrix)[width], int i_start, int i_end,
                int j_start, int j_end) {
    int result = 1, tmp = 0;
    char c;
    for (int i = i_start; i < i_end; i++) {
        for (int j = j_start; j < j_end; j++) {
            if (scanf("%d%c", &tmp, &c) != 2 ||
                (c != ' ' && c != '\n' && c != '\0' && c != EOF)) {
                    result = 0;
            } else {
                matrix[i][j] = (tmp != 0);
            }
        }
    }
    return result;
}

/**
 * @brief Подсчитывает количество ненулевых значений в данной матрице.
 * В контексте игры "Жизнь" подсчитывает количество живых клеток
 * @param width Количество столбцов матрицы
 * @param matrix Данная матрица
 * @param i_start Индекс строки, c которой начнется обработка матрицы
 * @param i_end Индекс строки, на которой закончится обработка матрицы
 * @param j_start Индекс столбца, с которого начнется обработка матрицы
 * @param j_end Индекс столбца, на котором закончится обработка матрицы
 * @return Количество живых клеток в данной матрицу
 */
int calc_population(int width, int (*matrix)[width], int i_start, int i_end,
                    int j_start, int j_end) {
    int result = 0;
    for (int i = i_start; i < i_end; i++) {
        for (int j = j_start; j < j_end; j++) {
            if (matrix[i][j]) {
                result += 1;
            }
        }
    }
    return result;
}

/**
 * @brief Копирует все значения матрицы и
 * заполняет этими значениями другую матрицу
 * @param width Количество столбцов матрицы
 * @param from Матрица откуда копировать
 * @param to Матрица куда копировать
 * @param i_start Индекс строки, c которой начнется обработка матрицы
 * @param i_end Индекс строки, на которой закончится обработка матрицы
 * @param j_start Индекс столбца, с которого начнется обработка матрицы
 * @param j_end Индекс столбца, на котором закончится обработка матрицы
 */
void copy_matrix(int width, int (*from)[width], int (*to)[width], int i_start,
                int i_end, int j_start, int j_end) {
    for (int i = i_start; i < i_end; i++) {
        for (int j = j_start; j < j_end; j++) {
            to[i][j] = from[i][j];
        }
    }
}

/**
 * @brief Модифицирует матрицу, применяя одну итерацию
 * игры "Жизнь", и записывает значения в другую матрицу.
 * Размерности матриц должны быть одинаковыми!
 * @param width Количество столбцов матриц
 * @param previous Матрица откуда нужно брать информацию
 * @param next Матрица куда записывается информация
 * @param i_start Индекс строки, c которой начнется обработка матрицы
 * @param i_end Индекс строки, на которой закончится обработка матрицы
 * @param j_start Индекс столбца, с которого начнется обработка матрицы
 * @param j_end Индекс столбца, на котором закончится обработка матрицы
 */
void calc_next(int width, int (*previous)[width], int (*next)[width],
                int i_start, int i_end, int j_start, int j_end) {
    for (int i = i_start; i < i_end; i++) {
        for (int j = j_start; j < j_end; j++) {
            next[i][j] = define_viability(width, previous, i, j);
                // ? Для каждой клетки поля подсчитывается ее следующее значение с
                // помощью функции define_viability
        }
    }
    init_shadow_cells(WIDTH, next, 1, HEIGHT - 1, 1, WIDTH - 1);
}

/**
 * @brief Подсчет следующего состояния клетки по ее координатами
 *
 * @param width Количество столбцов матриц
 * @param matrix Данная матрица
 * @param i координата строки
 * @param j координата столбца
 * @return 1 если клетка теперь жива, 0 если мертва
 */
int define_viability(int width, int (*matrix)[width], int i, int j) {
    int result = 1, control_sum = 0;
  /**
   * ? Подсчет контрольной суммы - это сумма значений самой клетки и всех ее 8
   * соседей
   * * В зависимости от суммы можно сразу подсчитать следующее состояние клетки
   */
    control_sum =
        matrix[i - 1][j - 1] + matrix[i - 1][j + 0] + matrix[i - 1][j + 1] +
        matrix[i + 0][j - 1] + matrix[i + 0][j + 0] + matrix[i + 0][j + 1] +
        matrix[i + 1][j - 1] + matrix[i + 1][j + 0] + matrix[i + 1][j + 1];

    if (matrix[i][j] == 0) {  // ? Если клетка мертва, она возродится если рядом
                              // есть ровно 3 живых клетки
        result = (control_sum == 3);
        } else { // ? Если клетка жива, она умрет если рядом с ней менее 4 и больше 1
                 // живого соседа (+ она сама)
            result = (control_sum < 4 + 1 && control_sum > 1 + 1);
        }
    return result;
}

/**
 * @brief Модифицирует матрицу, заполняя ее живыми или мертвыми клетками
 * @param width Количество столбцов матрицы
 * @param matrix Данная матрица
 * @param i_start Индекс строки, c которой начнется обработка матрицы
 * @param i_end Индекс строки, на которой закончится обработка матрицы
 * @param j_start Индекс столбца, с которого начнется обработка матрицы
 * @param j_end Индекс столбца, на котором закончится обработка матрицы
 */
void init_board(int width, int (*matrix)[width], int i_start, int i_end,
                int j_start, int j_end, int cell_type) {
    for (int i = i_start; i < i_end; i++) {
        for (int j = j_start; j < j_end; j++) {
            matrix[i][j] = cell_type != 0;
        }
    }
}

/**
 * @brief Модифицирует матрицу, заполняя ее псевдослучайным
 * сочетанием 1 и 0
 * @param matrix Данная матрица
 */
int random_board(int width, int (*matrix)[width], int i_start, int i_end,
                int j_start, int j_end) {
    srand(time(NULL));
    for (int i = 1 + i_start; i < HEIGHT - 1 + i_end - i_end; i++) {
        for (int j = 1 + j_start; j < WIDTH - 1 + j_end - j_end; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    init_shadow_cells(WIDTH, matrix, 1, HEIGHT - 1, 1, WIDTH - 1);
    return 1;
}

void colors(void) {
    int color = rand()%8;
    init_pair(1, COLOR_BLUE, 0);
    init_pair(2, COLOR_RED, 0);
    init_pair(3, COLOR_GREEN, 0);
    init_pair(4, COLOR_YELLOW, 0);
    init_pair(5, COLOR_MAGENTA, 0);
    init_pair(6, COLOR_CYAN, 0);
    init_pair(7, COLOR_WHITE, 0);
    attron(COLOR_PAIR(color));
    clear();
}

/**
 * @brief Модифицирует матрицу, заполняя ее границы
 * копиями противоположных клеток матрицы
 * @param matrix Данная матрица
 */
void init_shadow_cells(int width, int (*matrix)[width], int i_start, int i_end,
                        int j_start, int j_end) {
    for (int j = j_start; j < j_end; j++) {
        matrix[0][j] = matrix[i_end - 1][j];
        matrix[i_end][j] = matrix[1][j];
    }

    for (int i = i_start; i < i_end; i++) {
        matrix[i][0] = matrix[i][j_end - 1];
        matrix[i][j_end] = matrix[i][1];
    }

    matrix[0][0] = matrix[i_end - 1][j_end - 1];
    matrix[0][j_end] = matrix[i_end - 1][1];
    matrix[i_end][0] = matrix[1][j_end - 1];
    matrix[i_end][j_end] = matrix[1][1];
}

/**
 * @brief Выводит матрицу с использованием
 * printw для записи в буфер ncurses
 * @param width Количество столбцов последующей матрицы
 * @param matrix Данная матрица
 * @param i_start Индекс строки, c которой начнет выводится матрица
 * @param i_end Индекс строки, на которой закончит выводится матрица
 * @param j_start Индекс столбца, с которого начнет выводится матрица
 * @param j_end Индекс столбца, на котором закончит выводится матрица
 * @param alive Символ, которым заполняются живые клетки
 * @param dead Символ, которым заполняются мертвые клетки
 */
void output(int width, int (*matrix)[width], int i_start, int i_end,
            int j_start, int j_end, char alive, char dead) {
    for (int i = i_start; i < i_end; i++) {
        for (int j = j_start; j < j_end; j++) {
            if (matrix[i][j]) printw("%c", alive);
            else
                printw("%c", dead);
        }
        if (i != i_end - 1) printw("\n");
    }
}
