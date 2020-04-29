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

    insert(head, 3, 1337);
    int res=len(head);
    printf("%d\n", res);

    linked_list* next = head->next;
    while (next != NULL)
    {
        printf("%d ", next->el);
        next = next->next;
    }

    output(head, res);
    return 0;
}