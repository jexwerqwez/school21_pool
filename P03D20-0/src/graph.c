#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "expression_parsing.h"
#include "expression_calculation.h"
#include "graph_drawing.h"
#include "stack.h"

#define EXIT_INPUT_ERROR 2

#define MAX_STR_LEN 1000

int expression_check(char *expr);
int input(char *expres, int *n);

int main(void) {
    int return_code = EXIT_SUCCESS;
    char* expression = (char*)malloc(sizeof(char));
    int n = 0;
    if (input(expression, &n)) {
        printf("Incorrect mathematical expression input, list of allowed operations and functions:\n"
               "\"+\" \n"
               "\"-\" (unary and binary) \n"
               "\"*\" \n"
               "\"/\" \n"
               "\"()\" \n"
               "sin(x) \n"
               "cos(x) \n"
               "tan(x) \n"
               "ctg(x) \n"
               "sqrt(x) \n"
               "ln(x)");
        return_code = EXIT_INPUT_ERROR;
    } else {
        stack_ty *stack = NULL;
        pars(expression, &stack);
        stack_ty *reversed_stack = NULL;
        reverse_stack(stack, &reversed_stack);
        draw(reversed_stack);
        destroy_stack(&stack);
        destroy_stack(&reversed_stack);
    }
    free(expression);
    return return_code;
}

int expression_check(char *expr) {
    int exit_flag = EXIT_FAILURE;
    char* expr_dup = strdup(expr);
    const char* delims = "()+-*/";
    char* token;
    int i = 0;
    int k = 0;
    token = strtok(expr_dup, delims);
    while (token != 0) {
        char delim = expr[token - expr_dup + strlen(token)];
        if (delim != '\0') {
            if ( (strcmp(token, "0") != 0) && (atof(token) == 0) && (strcmp(token, "x") != 0) ) {
                k++;
            if (strcmp(token, "cos") == 0 || strcmp(token, "sin") == 0 || strcmp(token, "tan") == 0
                || strcmp(token, "ctg") == 0 || strcmp(token, "sqrt") == 0 || strcmp(token, "ln") == 0)
                i++;
            }
        } else {
            if ((strcmp(token, "0") != 0) && (atof(token) == 0) && (strcmp(token, "x") != 0))
                k++;
        }
        token = strtok(0, delims);
    }
    if (k == i) { exit_flag = EXIT_SUCCESS; }
    free(expr_dup);
    return exit_flag;
}

int input(char *expres, int *n) {
    int exit_flag = EXIT_FAILURE;
    int attention = 0;
    char symbol = '0';
    char prev_symbol = symbol;
    int m = 0;
    int flag = 0;
    int open = 0;
    int close = 0;
    char *expr = (char*)malloc(sizeof(char));
    const char letter[32] = "cosintangqrln.+-) (*/x1234567890";
    while ((symbol = getchar()) && symbol != '\n') {
        if (*n == 0 && (symbol == '-' || symbol == '+')) {
            expr[(*n)++] = '0';
            expr[(*n)++] = symbol;
            expres[0] = '0';
            if (symbol == '-') {expres[1] = '-';}
            if (symbol == '+') {continue;}
        } else if (symbol == ' ') { continue;
        } else if (symbol == '-' && prev_symbol == '(') {
            expr[(*n)++] = '0';
            expr[(*n)++] = symbol;
        } else if ( (symbol == ')' || symbol == '(') && ( (prev_symbol == '+') || (prev_symbol == '-') ||
            (prev_symbol == '*') || (prev_symbol == '/')) ) {
            expr[(*n)++] = '1';
            expr[(*n)++] = symbol;
        } else if ( prev_symbol == '-' && (symbol == '-' || symbol == '+')) { continue;
        } else if ( (prev_symbol == '+' || prev_symbol == '0') && symbol == '+') { continue;
        } else {expr[(*n)++] = symbol;}
        prev_symbol = symbol;
        char *p_expr = (char*)realloc(expr, (*n)*sizeof(char));
        if (p_expr == NULL) {
            free(p_expr);
            attention = 1;
            break;
        } else { expr = p_expr; }
        flag = 0;
        for (int i = 0; !flag && i < 32; i++) {
            if (symbol == letter[i]) { flag = 1; }
        }
        if (symbol == '(') {open++;}
        if (symbol == ')') {close++;}
        expres[m++] = symbol;
        expres = (char*)realloc(expres, m*sizeof(char));
    }
    expr[*n] = '\0';
    if (attention || flag == 0 || open != close) { exit_flag = EXIT_FAILURE;
    } else {exit_flag = expression_check(expr);}
    free(expr);
    return exit_flag;
}
