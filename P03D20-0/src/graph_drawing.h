#ifndef SRC_GRAPH_DRAWING_H_
#define SRC_GRAPH_DRAWING_H_


#define pi acos(-1)
#define eps 1e-6

#define WIDTH 80
#define HEIGHT 25

#include <stdio.h>
#include <math.h>

#include "stack.h"
#include "expression_calculation.h"

void draw(stack_ty *stack);
void print_field(char field[HEIGHT][WIDTH]);
void fill_field(char field[HEIGHT][WIDTH]);


#endif  // SRC_GRAPH_DRAWING_H_
