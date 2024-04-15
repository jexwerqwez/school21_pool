#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

void init_test(struct stack* tmp);
void push_test(struct stack* tmp);
void pop_test(struct stack* tmp);
void destroy_test(struct stack* tmp);

int main() {
    struct stack* tmp = (struct stack*)malloc(sizeof(struct stack));
    init_test(tmp);
    push_test(tmp);
    pop_test(tmp);
    destroy_test(tmp);
    return 0;
}

void init_test(struct stack* tmp) {
    printf("INIT TEST\n");
    if (init(tmp) != 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void push_test(struct stack* tmp) {
    printf("PUSH TEST\n");
    if (push(tmp, 3) == 0 || push(tmp, 3) != (tmp->item))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void pop_test(struct stack* tmp) {
    printf("POP TEST\n");
    if (pop(tmp) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void destroy_test(struct stack* tmp) {
    printf("DESTROY TEST\n");
    if (destroy(tmp) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}
