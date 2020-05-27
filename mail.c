#include "stack.h"


/*

    Создали бы уже мейн в конце концов................

*/



int main()
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
    return 0;
}
