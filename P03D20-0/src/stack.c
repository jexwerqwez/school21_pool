#include "stack.h"

void push(stack_ty **stack, char symb, double num) {
    stack_ty *temp = (stack_ty *) malloc(sizeof(stack_ty));
    temp->data = symb;
    temp->value = num;
    temp->prev = *stack;
    *stack = temp;
}

void pop(stack_ty **stack, char *symb, double *num) {
    stack_ty *temp = (*stack)->prev;
    *symb = (*stack)->data;
    *num = (*stack)->value;
    free(*stack);
    *stack = temp;
}

void reverse_stack(stack_ty *old, stack_ty **new) {
    stack_ty *temp = old;
    while (temp != NULL) {
        push(new, temp->data, temp->value);
        temp = temp->prev;
    }
}

void destroy_stack(stack_ty **stack) {
    while (*stack != NULL) {
        stack_ty *temp = *stack;
        stack = &(*stack)->prev;
        free(temp);
    }
}
