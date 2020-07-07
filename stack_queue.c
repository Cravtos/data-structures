//
// Created by slaventy on 04.07.2020.
//
#include "stack.h"
#include <stdio.h>

struct stack_queue
{
    stack a;
    stack b;
};

struct stack_queue stack_queue_new()
{
    struct stack_queue queue =
            {
                    .a = stack_new(),
                    .b = stack_new()
            };
    return queue;
}

int stack_queue_pop(struct stack_queue s)
{
    if(stack_is_empty(s.b))
    {
        while (!stack_is_empty(s.a))
        {
            stack_push(s.b, stack_pop(s.a));
        }
    }
    return stack_pop(s.b);
}

void stack_queue_push(struct stack_queue queue, int a)
{
    stack_push(queue.a, a);
}

int stack_queue_len(struct stack_queue s)
{
    return stack_len(s.a) + stack_len(s.b);
}
