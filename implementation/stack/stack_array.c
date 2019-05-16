
typedef struct {
    int32_t capacity;
    int32_t top;
    int32_t* data;
} stack;

stack* newStack() {
    const int32_t size_of_capacity = 5;

    stack* stk = (stack*)malloc(sizeof(stack));
    stk->capacity = size_of_capacity;
    stk->top = -1;
    stk->data = (int32_t*)malloc(stk->capacity * sizeof(int32_t));

    return stk;
}

void freeStack(stack* stk) {
    free(stk->data);
    free(stk);
}

bool_t DoubleCapacity(stack* stk) {
    return false;
}

int32_t StackPop(stack* stk) {
    int32_t data = stk->data[top];
    --top;
    return data;
}

int32_t StackPeek(stack* stk) {
    return stk->data[top];
}

void StackPush(int32_ data) {
    ++top;
    stk->data[top] = data;
}

bool_t StackEmpty() {
    return (top == -1);
}

bool_t ForTest() {
    return 1;
}
