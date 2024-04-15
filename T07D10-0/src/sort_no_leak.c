#include <stdio.h>
#include <stdlib.h>
int input_num(int *n);
int input_arr(int *a, int n);
void quicksort(int *a, int left, int right);
void output(int *a, int n);

int main(void) {
    int *data;
    int n;
    if (input_num(&n) != 0) {
        printf("n/a");
        return -1;
    } else {
    	data = (int*)malloc(n * sizeof(int));
    	input_arr(data, n);
        quicksort(data, 0, n - 1);
        output(data, n);
    }
    free(data);
    return 0;
}

int input_num(int *n) {
	int flag = 0;
	if (scanf("%d", n) != 1 || getchar()!= '\n' || (*n < 1) || (*n > 10)) { flag = 1;
	}
	return flag;
}
int input_arr(int *a, int n) {
	int flag = 0;
	char ch;
	for (int* p = a; p - a < n; p++) {
		if (scanf("%d", p) != 1 ) { flag = 1; }
	}
	if (scanf("%c", &ch) == 1 && ch != '\n' && ch != '\0' && ch != EOF)
		flag = 1;
	return flag;
}

void quicksort(int *a, int l, int r) {
    int l_board = l;
    int r_board = r;
    int piv = a[l];
    while ( l < r ) {
        while ( (a[r] >= piv) && (l < r) ) { r--; }
            if (l != r) {
                a[l] = a[r];
                l++;
            }
        while ( (a[l] <= piv) && (l < r) ) {l++;}
        if (l != r) {
            a[r] = a[l];
            r--;
        }
    }
    a[l] = piv;
    piv = l;
    l = l_board;
    r = r_board;
    if (l < piv)
        quicksort(a, l, piv - 1);
    if (r > piv)
        quicksort(a, piv + 1, r);
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if ( i == 0 )
            printf("%d", a[i]);
        else
            printf(" %d", a[i]);
    }
}

