#include "stack.h"

#include <stdio.h>

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

//int main()
//{
//    stack res = stack_new();
//    while (!feof(stdin))
//    {
//        int cur = 0;
//        if (fscanf(stdin, "%d", &cur) != 1)
//            break;
//        stack_push(res,cur);
//    }
//
//    //printf("%d \n", stack_pop(res));
//    while(stack_len(res)!=0)
//    {
//        printf("%d \n", stack_pop(res));
//    }
//    return 0;
//}

