#include <stdio.h>
#include "linked_list.c"

struct stack
{
    linked_list *ll;
};

typedef struct stack stack;

stack stack_new()
{
    linked_list* head = calloc(1, sizeof(linked_list));
    stack res ={ .ll = head};
    return res;
}

void stack_push(stack s, int element)
{
    insert(s.ll, 0, element);
}

int stack_pop(stack s)
{
    return delete(s.ll, 0);
}

int stack_len(stack s)
{
    return len(s.ll);
}

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
    while (stack_len(s.a) != 0)
    {
        stack_push(s.b, stack_pop(s.a));
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
