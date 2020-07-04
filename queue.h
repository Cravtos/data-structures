//
// Created by slaventy on 04.07.2020.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include "stack.h"

struct stack_queue
{
    stack a;
    stack b;
};

struct stack_queue stack_queue_new();
int stack_queue_len(struct stack_queue s);
void stack_queue_push(struct stack_queue queue, int a);
int stack_queue_pop(struct stack_queue s);

#endif //QUEUE_QUEUE_H
