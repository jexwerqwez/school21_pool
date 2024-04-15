/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int* find_numbers(int* buffer, int length, int number, int* numbers);


/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX], find[NMAX];
    int sum = 0;
    if (input(data, &n) < 0) {
        printf("n/a");
        return -1;
    } else {
        if ((sum = sum_numbers(data, n)) == 0) {
            printf("n/a");
            return -1;
        } else {
            printf("%d\n", sum);
            find_numbers(data, n, sum, find);
            output(find, n);
        }
    }
    return 0;
}

int input(int *buffer, int *length) {
    if (scanf("%d", length) != 1 || getchar()!= '\n' || (*length < 1) || (*length > 10)) { return -1;
    } else {
        for (int* p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) { return -2; }
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        } else {
            if ( i == 0 )
                printf("%d", a[i]);
            else
                printf(" %d", a[i]);
        }
    }
    printf("\n");
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if ((buffer[i] % 2) == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}
/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
------------------------------------- */
int* find_numbers(int* buffer, int length, int number, int* numbers) {
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0)
                numbers[i] = buffer[i];
            else
                numbers[i] = 0;
        } else {
            numbers[i] = 0;
        }
    }
    return numbers;
}
