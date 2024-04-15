#include "expression_calculation.h"

double calc(stack_ty *stack, double x) {
    char symb;
    double num;
    double num1, num2;
    char symb1, symb2;
    stack_ty *ptr = stack;
    stack_ty *temp_stack = NULL;
    while (ptr != NULL) {
        num = ptr->value;
        symb = ptr->data;
        switch (symb) {
            case '+': {
                pop(&temp_stack, &symb1, &num1);
                pop(&temp_stack, &symb2, &num2);
                push(&temp_stack, 'd', num1 + num2);
                break;
            }
            case '-': {
                pop(&temp_stack, &symb1, &num1);
                pop(&temp_stack, &symb2, &num2);
                push(&temp_stack, 'd', num2 - num1);
                break;
            }
            case '_': {
                pop(&temp_stack, &symb1, &num1);
                push(&temp_stack, 'd', -num1);
                break;
            }
            case '*': {
                pop(&temp_stack, &symb1, &num1);
                pop(&temp_stack, &symb2, &num2);
                push(&temp_stack, 'd', num1 * num2);
                break;
            }
            case '/': {
                pop(&temp_stack, &symb1, &num1);
                pop(&temp_stack, &symb2, &num2);
                push(&temp_stack, 'd', num2 / num1);
                break;
            }
            case 's': {
                pop(&temp_stack, &symb1, &num1);
                push(&temp_stack, 'd', sin(num1));
                break;
            }
            case 'q': {
                pop(&temp_stack, &symb1, &num1);
                push(&temp_stack, 'd', sqrt(num1));
                break;
            }
            case 't': {
                pop(&temp_stack, &symb1, &num1);
                push(&temp_stack, 't', tan(num1));
                break;
            }
            case 'g': {
                pop(&temp_stack, &symb1, &num1);
                push(&temp_stack, 'd', 1 / tan(num1));
                break;
            }
            case 'c': {
                pop(&temp_stack, &symb1, &num1);
                push(&temp_stack, 'd', cos(num1));
                break;
            }
            case 'l': {
                pop(&temp_stack, &symb1, &num1);
                push(&temp_stack, 'd', log(num1));
                break;
            }
            case 'd': {
                push(&temp_stack, 'd', num);
                break;
            }
            case 'x': {
                push(&temp_stack, 'd', x);
                break;
            }
            default:
                break;
        }
        ptr = ptr->prev;
    }
    pop(&temp_stack, &symb, &num);
    return num;
}
