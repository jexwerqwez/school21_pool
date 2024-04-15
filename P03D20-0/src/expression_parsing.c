#include "expression_parsing.h"

void pars(char *str, stack_ty **stack) {
    int i = 0;
    char prev = '=';
    stack_ty *temp_stack = NULL;
    char op;
    double num;
    while (*(str + i) != '\0') {
        if (*(str + i) == ' ') {
            ++i;
            continue;
        }
        if (i != 0 && *(str + i - 1) != ' ')
            prev = *(str + i - 1);
        if (*(str + i) == '*' || *(str + i) == '/') {
            ++i;
            while (temp_stack != NULL && (temp_stack->data == '*' || temp_stack->data == '/')) {
                pop(&temp_stack, &op, &num);
                push(stack, op, num);
            }
            push(&temp_stack, *(str + i - 1), 0.0);
            continue;
        }
        if (*(str + i) == '-' && (prev == '=' || prev == '(')) {
            ++i;
            push(&temp_stack, '_', 0.0);
            continue;
        }
        if (*(str + i) == '+' || *(str + i) == '-') {
            ++i;
            while (temp_stack != NULL && (temp_stack->data == '-' || temp_stack->data == '+'
                || temp_stack->data == '*' || temp_stack->data == '/')) {
                pop(&temp_stack, &op, &num);
                push(stack, op, num);
            }
            push(&temp_stack, *(str + i - 1), 0.0);
            continue;
        }
        if (*(str + i) == '(') {
            ++i;
            push(&temp_stack, '(', 0.0);
            continue;
        }
        if (*(str + i) == ')') {
            ++i;
            while (temp_stack->data != '(') {
                pop(&temp_stack, &op, &num);
                push(stack, op, num);
            }
            pop(&temp_stack, &op, &num);
            if (temp_stack != NULL && (temp_stack->data == 's' || temp_stack->data == 'q' ||
                temp_stack->data == 'c' || temp_stack->data == 'g' || temp_stack->data == 't' ||
                temp_stack->data == 'l')) {
                pop(&temp_stack, &op, &num);
                push(stack, op, num);
            }
            continue;
        }
        if (*(str + i) == 's' && *(str + i + 1) == 'i') {
            i += 3;
            push(&temp_stack, 's', 0.0);
            continue;
        }
        if (*(str + i) == 's' && *(str + i + 1) == 'q') {
            i += 4;
            push(&temp_stack, 'q', 0.0);
            continue;
        }
        if (*(str + i) == 'c' && *(str + i + 1) == 'o') {
            i += 3;
            push(&temp_stack, 'c', 0.0);
            continue;
        }
        if (*(str + i) == 'c' && *(str + i + 1) == 't') {
            i += 3;
            push(&temp_stack, 'g', 0.0);
            continue;
        }
        if (*(str + i) == 't') {
            i += 3;
            push(&temp_stack, 't', 0.0);
            continue;
        }
        if (*(str + i) == 'l') {
            i += 2;
            push(&temp_stack, 'l', 0.0);
            continue;
        }
        if (*(str + i) == 'x') {
            ++i;
            push(stack, 'x', 0.0);
            continue;
        }
        char *end;
        double value = strtod(str + i, &end);
        i += end - str - i;
        push(stack, 'd', value);
    }
    while (temp_stack != NULL) {
        pop(&temp_stack, &op, &num);
        push(stack, op, num);
    }
}
