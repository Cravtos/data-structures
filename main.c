//  Вот тута пишем сишные импорты.
#include <stdio.h>
// Вот тута пишем локальные инклюды.
#include "linked_list.h"
#include "stack.h"
#include "stack_queue.h"



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
    print(head);
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

void test_stack_queue()
{
    struct stack_queue q = stack_queue_new();
    stack_queue_push(q, 1);
    stack_queue_push(q, 2);

    printf("%d ", stack_queue_pop(q));
    stack_queue_push(q, 3);
    printf("%d ", stack_queue_pop(q));
    printf("%d ", stack_queue_pop(q));
}
int main()
{
    //test_linked_list();
    //test_stack();
    //test_dynamic_array();
    test_stack_queue();

    return 0;
}
