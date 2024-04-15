#ifndef SRC_STACK_H_
#define SRC_STACK_H_


#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack {
    char data;
    double value;
    struct s_stack *prev;
} stack_ty;

void pop(stack_ty **stack, char *symb, double *num);
void push(stack_ty **stack, char symb, double num);
void reverse_stack(stack_ty *old, stack_ty **new);
void destroy_stack(stack_ty **stack);


#endif  // SRC_STACK_H_
