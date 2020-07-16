#ifndef DATA_STRUCTURES__QUEUE_H
#define DATA_STRUCTURES__QUEUE_H

#include "linked_list.h"
#include <stdio.h>

struct queue
{
    linked_list *first;
    linked_list *last;
};

typedef struct queue queue;

queue queue_new();
void queue_push(queue q, int element);
int queue_pop(queue q);
int queue_len(queue q);

#endif //DATA_STRUCTURES__QUEUE_H