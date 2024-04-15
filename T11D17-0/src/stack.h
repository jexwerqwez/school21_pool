#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include "door_struct.h"
typedef int Data;

struct stack {
    struct stack* next;
    Data item;
};
struct stack* init(struct stack* ptr);
int push(struct stack* tmp, Data num);
int pop();
int destroy(struct stack* ptr);
#endif  // SRC_STACK_H_
