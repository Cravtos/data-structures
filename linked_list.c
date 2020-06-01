#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

void push(linked_list* ll, int el)
{
    while (ll->next != NULL)
        ll = ll->next;
    ll->next = calloc(1, sizeof(ll));   // check if allocated
    ll->next->el = el;
}

void insert(linked_list* ll, int pos, int el)
{
    for (int i = 0; i < pos; i++)
    {
        ll = ll->next;
    }
    linked_list* ll1 = calloc(1, sizeof(linked_list));
    ll1->el = el;
    ll1->next = ll->next;
    ll->next = ll1;
}

int len(linked_list* ll)
{
    int res=0;
    while (ll->next != NULL)
    {
        ll = ll->next;
        res++;
    }
    return res;
}

// Print last elements
void tail_uneffective(linked_list* head, size_t size, size_t k)
{
    linked_list* list = head->next;

    for (int i = 0; i < size - k; i++)
    {
        list = list->next;
    }

    for (int j = size - k; j < size; j++)
    {
        printf("%d ", list->el);
        list = list->next;
    }
}

// Print last elements.
void tail(linked_list* head, size_t amount)
{
    linked_list* beg = head->next;
    linked_list* end = head->next;

    for (size_t i = 0; i < amount; i++)
    {
        end = end->next;
    }

    while (end != NULL)
    {
        beg = beg->next;
        end = end->next;
    }

    for (int i = 0; i < amount; i++)
    {
        printf("%d ", beg->el);
        beg = beg->next;
    }
}

void print(linked_list* head)
{
    linked_list* next = head->next;
    while (next != NULL)
    {
        printf("%d ", next->el);
        next = next->next;
    }
}

// Detects cycles in list using fast and slow pointers.
int has_cycle(linked_list* head)
{
    linked_list* slow=head->next;
    linked_list* fast=head->next;

    while (fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next->next;
        slow=slow->next->next;
        if (fast==slow)
        {
            return 1;
        }
        
    }
    return 0;
}


linked_list* _reverse(linked_list* ll)
{
    if (ll->next == NULL)
    {
        return ll;
    }

    linked_list* head = ll;
    linked_list* tail = ll->next;

    linked_list* new_head = _reverse(tail);

    tail->next = head;
    head->next = NULL;

    return new_head;
}

void reverse(linked_list* head)
{
    if (head->next == NULL)
        return;
    linked_list* reversed = _reverse(head->next);
    head->next = reversed;
}

void cycle_reverse(linked_list* head)
{
    linked_list* prev = NULL;
    linked_list* cur = head->next;

    while (cur != NULL)
    {
        linked_list* next = cur->next;

        cur->next = prev;

        prev = cur;
        cur = next;
    }

    head->next = prev;#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

void push(linked_list* ll, int el)
{
    while (ll->next != NULL)
        ll = ll->next;
    ll->next = calloc(1, sizeof(ll));   // check if allocated
    ll->next->el = el;
}

void insert(linked_list* ll, int pos, int el)
{
    for (int i = 0; i < pos; i++)
    {
        ll = ll->next;
    }
    linked_list* ll1 = calloc(1, sizeof(linked_list));
    ll1->el = el;
    ll1->next = ll->next;
    ll->next = ll1;
}

int len(linked_list* ll)
{
    int res=0;
    while (ll->next != NULL)
    {
        ll = ll->next;
        res++;
    }
    return res;
}

// Print last elements
void tail_uneffective(linked_list* head, size_t size, size_t k)
{
    linked_list* list = head->next;

    for (int i = 0; i < size - k; i++)
    {
        list = list->next;
    }

    for (int j = size - k; j < size; j++)
    {
        printf("%d ", list->el);
        list = list->next;
    }
}

int delete(linked_list* ll, int pos)
{
    for (int i = 0; i < pos; i++)
    {
        ll = ll->next;
    }

    int el = ll->next->el;
    linked_list* ll1 = ll->next;
    ll->next=ll->next->next;
    free(ll1);

    return el;
}

// Print last elements.
void tail(linked_list* head, size_t amount)
{
    linked_list* beg = head->next;
    linked_list* end = head->next;

    for (size_t i = 0; i < amount; i++)
    {
        end = end->next;
    }

    while (end != NULL)
    {
        beg = beg->next;
        end = end->next;
    }

    for (int i = 0; i < amount; i++)
    {
        printf("%d ", beg->el);
        beg = beg->next;
    }
}

void print(linked_list* head)
{
    linked_list* next = head->next;
    while (next != NULL)
    {
        printf("%d ", next->el);
        next = next->next;
    }
}

// Detects cycles in list using fast and slow pointers.
int has_cycle(linked_list* head)
{
    linked_list* slow=head->next;
    linked_list* fast=head->next;

    while (fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next->next;
        slow=slow->next->next;
        if (fast==slow)
        {
            return 1;
        }
        
    }
    return 0;
}


linked_list* _reverse(linked_list* ll)
{
    if (ll->next == NULL)
    {
        return ll;
    }

    linked_list* head = ll;
    linked_list* tail = ll->next;

    linked_list* new_head = _reverse(tail);

    tail->next = head;
    head->next = NULL;

    return new_head;
}

void reverse(linked_list* head)
{
    if (head->next == NULL)
        return;
    linked_list* reversed = _reverse(head->next);
    head->next = reversed;
}

void cycle_reverse(linked_list* head)
{
    linked_list* prev = NULL;
    linked_list* cur = head->next;

    while (cur != NULL)
    {
        linked_list* next = cur->next;

        cur->next = prev;

        prev = cur;
        cur = next;
    }

    head->next = prev;
}
