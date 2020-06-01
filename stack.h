#ifndef DATA_STRUCTURES__STACK_H
#define DATA_STRUCTURES__STACK_H

#include "linked_list.h"
#include <stdio.h>

struct _stack
{
    linked_list *ll;
};

typedef struct _stack stack;

stack stack_new();
void stack_push(stack s, int element);
int stack_pop(stack s);
int stack_len(stack s);

struct stack_queue
{
    stack a;
    stack b;
};

struct stack_queue stack_queue_new();
int stack_queue_len(struct stack_queue s);
void stack_queue_push(struct stack_queue queue, int a);
int stack_queue_pop(struct stack_queue s);


#endif //DATA_STRUCTURES__STACK_H
