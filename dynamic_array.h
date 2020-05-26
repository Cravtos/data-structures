#ifndef DATA_STRUCTURES__DYNAMIC_ARRAY_H
#define DATA_STRUCTURES__DYNAMIC_ARRAY_H

#include <stdlib.h>

struct _dyn_arr
{
    int *arr;
    size_t capacity;
    size_t len;
};

typedef struct _dyn_arr dyn_arr;

void push(dyn_arr* da, int el);
void insert(dyn_arr* da, int pos, int el);

#endif //DATA_STRUCTURES__DYNAMIC_ARRAY_H
