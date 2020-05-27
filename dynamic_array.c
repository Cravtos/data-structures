#include "dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>

void push(dyn_arr* da, int el)
{
    if (da->arr == NULL)
    {
        da->arr = calloc(32, sizeof(int));
        da->capacity = 32;
        da->len = 0;
    }

    if (da->len >= da->capacity - 1)
    {
        da->arr = realloc(da->arr, da->capacity * 2 * sizeof(int));
        da->capacity *= 2;
    }

    da->arr[da->len] = el;
    da->len++;
}

void insert(dyn_arr* da, int pos, int el)
{
    // bound check should be here

    for (int i = da->len - 1; i >= pos; i--)
    {
        da->arr[i + 1] = da->arr[i];
    }
    da->arr[pos] = el;
    da->len++;
}
