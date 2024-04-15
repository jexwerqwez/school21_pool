#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack* init(struct stack* ptr) {
    ptr->next = NULL;
    ptr->item = 0;
    return ptr;
}

struct stack *top;
int push(struct stack* tmp, Data num) {
    int flag = 0;
    if (tmp == NULL)
        flag = 1;
    tmp->item = num;
    tmp->next = NULL;
    if (top == NULL) {
        top = tmp;
    } else {
        tmp->next = top;
        top = tmp;
    }
    return flag;
}

int pop() {
    int flag = 0;
    if (top == NULL) {
        flag = 1;
    } else {
        top = top->next;
    }
    return flag;
}

int destroy(struct stack* ptr) {
    int flag = 0;
    struct stack *end = ptr;
    if (ptr == NULL)
        flag = 1;
    while (end != NULL) {
        struct stack *tmp = end;
        end = end->next;
        free(tmp);
    }
    return flag;
}
