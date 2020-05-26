#ifndef DATA_STRUCTURES__LINKED_LIST_H
#define DATA_STRUCTURES__LINKED_LIST_H

#include <stdlib.h>

struct _linked_list
{
    int el;
    struct _linked_list* next;
};

typedef struct _linked_list linked_list;

void push(linked_list* ll, int el);
void insert(linked_list* ll, int pos, int el);
int len(linked_list* ll);
void tail_uneffective(linked_list* head, size_t size, size_t k);
void tail(linked_list* head, size_t amount);
void print(linked_list* head);
int has_cycle(linked_list* head);
void reverse(linked_list* head);
void cycle_reverse(linked_list* head);

#endif //DATA_STRUCTURES__LINKED_LIST_H
