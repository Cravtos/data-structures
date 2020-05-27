//  Вот тута пишем сишные импорты.
#include <stdio.h>

// Вот тута пишем локальные инклюды.
#include "stack.h"
#include "linked_list.h"
#include "dynamic_array.h"

/*
    Создали бы уже мейн в конце концов................
*/


void test_linked_list()
{
    int cur = 0;
    linked_list* head = calloc(1, sizeof(linked_list));

    while (!feof(stdin))
    {
        if (fscanf(stdin, "%d", &cur) != 1)
            break;
        push(head, cur);
    }
}

void test_stack()
{
    stack res = stack_new();
    
    while (!feof(stdin))
    {
        int cur = 0;
        if (fscanf(stdin, "%d", &cur) != 1)
            break;
        stack_push(res,cur);
    }

    while(stack_len(res)!=0)
    {
        printf("%d \n", stack_pop(res));
    }
}

void test_dynamic_array()
{
    int cur = 0;
    dyn_arr* da = calloc(1, sizeof(dyn_arr));
    while (!feof(stdin))
    {
        if (fscanf(stdin, "%d", &cur) != 1)
            break;
        push(da, cur);
    }
}

int main()
{
    test_stack();
    
    return 0;
}
