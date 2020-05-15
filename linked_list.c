#include <stdio.h>
#include <stdlib.h>

struct _linked_list
{
    int el;
    struct _linked_list* next;
};

typedef struct _linked_list linked_list;

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

void output(linked_list* head, int res) //output 'k' last elements
{
    printf("\n");
    linked_list* head1 = head->next;
    int k=2;

    for (int i=0; i < res-k; i++)
    {
        head1 = head1->next;
    }

    for (int j=res-k; j < res; j++)
    {
        printf("%d ", head1->el);
        head1 = head1->next;
    }
}

void print_k_raz(linked_list* head, int kolvo)
{
    linked_list* beg = head->next;
    linked_list* kon = head->next;

    for (int i=0; i<kolvo; i++)
    {
        kon=kon->next;
    }

    while (kon!=NULL)
    {
        beg=beg->next;
        kon=kon->next;
    }

    for (int i = 0; i < kolvo; i++)
    {
        printf("%d ",beg->el);
        beg=beg->next;
    }

    puts("");
}

void printik(linked_list* head)
{
    linked_list* next = head->next;
    while (next != NULL)
    {
        printf("%d ", next->el);
        next = next->next;
    }   
    puts("");
}

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

    // ll = 1-2-3-4-5...
    linked_list* head = ll;
    linked_list* tail = ll->next;
    // head = 1
    // tail -> 2-3-4-5...

    linked_list* new_head = _reverse(tail);
    // new_head -> ...5-4-3-2 <- tail

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
        // @-1-  2-3-4-5
        // cur^  ^next

        cur->next = prev;
        // @-1  2-3-4-5
        //cur^  ^next

        prev = cur;
        cur = next;
        // @-2-1 3-4-5
        //   c p n
    }

    head->next = prev;
}

int main()
{
    int cur = 0;
    linked_list* head = calloc(1, sizeof(linked_list));

    while (!feof(stdin))
    {
        if (fscanf(stdin, "%d", &cur) != 1)
            break;
        push(head, cur);
    }
//
//    insert(head, 3, 1337);
//    int res=len(head);
//    printf("%d\n", res);
//
    reverse(head);
    // printik(head);
//
//    output(head, res);
//    puts("");
//
//    print_k_raz(head,4);
//
//    head->next->next->next->next=head->next;
//
//    if (has_cycle(head))
//    {
//        puts("Is cycle");
//    }
//    else
//    {
//        puts("No cycle");
//    }
//
//
//
    return 0;
}