# Data Structures
Repository for learning Data Structures by the group.

### Array list
Complexity of
- `push(arr, el)` (to the end) **O(1) to O(n)** (in case of reallocation) 
- `insertion(arr, index, el)` **O(n) to O(2n)** (in case of reallocation)
- `deletion(arr, index)` **O(n)**
- `get(arr, index)` **O(1)** **[main feature]**
- `"insert after current"` **O(n) to O(2n)** (in case of reallocation)

### Linked list
Complexity of
- `push(head, el)` **O(n)** (can be **O(1)** keeping tail pointer)
- `insertion(head, index, el)` **O(n)** (at worst)
- `deletion(head, index)` **O(n)** (at worst) 
- `get(head, index)` **O(n)** (at worst)
- `"insert after current"` **O(1)** **[main feature]**

### Stack using linked list
- `stack stack_new()` **O(1)**
- `void stack_push(stack s, int element)` **O(n)** (at worst)
- `int stack_pop(stack s)` **O(n)** (at worst) 
- `int stack_len(stack s)` **O(n)** 

### Queue using stack
Complexity of
- `stack_queue_new()` **O(1)** 
- `stack_queue_len(struct stack_queue s)` **O(n)**
- `stack_queue_push(struct stack_queue queue, int a)` **O(1)** (O(n) worst case) 
- `stack_queue_pop(struct stack_queue s)` **O(1)** (O(n) worst case)
