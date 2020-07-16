#include <stdio.h>
#include "linked_list.c"

struct queue
{
    linked_list *first;
    linked_list *last;
};

typedef struct queue queue;

queue queue_new()
{
    linked_list* firstq = calloc(1, sizeof(linked_list));
    linked_list* lastq = firstq;
    queue res ={ .first = firstq, .last = lastq};
    return res;
}

void queue_push(queue q, int element)
{
    push(q.last, element);   
    q.last = q.last->next;
}

int queue_pop(queue q)
{
    return delete(q.first, 0);
}

int queue_len(queue q)
{
    return len(q.last);
}
