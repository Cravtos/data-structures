#include <stdio.h>
#include <stdlib.h>

struct _dyn_arr
{
    int *arr;
    size_t capacity;
    size_t len;
};

typedef struct _dyn_arr dyn_arr;

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
    // bound check here

    for (int i = da->len - 1; i >= pos; i--)
    {
        da->arr[i+1] = da->arr[i];
    }
    da->arr[pos] = el;
    da->len++;
}

int main()
{
    int cur = 0;
    dyn_arr* da = calloc(1, sizeof(dyn_arr));
    while (!feof(stdin))
    {
        if (fscanf(stdin, "%d", &cur) != 1)
            break;
        push(da, cur);
    }
    insert(da, 2, 1337);
    for (int i = da->len - 1; i >= 0; i--)
    {
        printf("%d ", da->arr[i]);
    }
}
