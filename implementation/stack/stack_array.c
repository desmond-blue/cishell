typedef struct {
    int32_t capacity;
    int32_t top;
    char* data;
} stack;

stack* newStack(const int32_t size_of_capacity) {
    stack* stk = (stack*)malloc(sizeof(stack));
    stk->capacity = size_of_capacity;
    stk->top = -1;
    stk->data = (char*)malloc(stk->capacity * sizeof(char));

    return stk;
}

void freeStack(stack* stk) {
    free(stk->data);
    free(stk);
}

bool DoubleCapacity(stack* stk) {
    if (stk->capacity == 0)
        stk->capacity = 1;
    else
        stk->capacity *= 2;

    char* ptr_new = realloc(stk->data, stk->capacity * sizeof(char));
    stk->data = ptr_new;
    if (stk->data)
        return true;
    else
        return false;
}

char StackPop(stack* stk) {
    if (stk->top == -1) {
        assert("[Error] pop an empty queue.\n");
    }
    char data = stk->data[stk->top];
    --stk->top;
    return data;
}

char StackPeek(stack* stk) {
    return stk->data[stk->top];
}

void StackPush(stack* stk, char data) {
    if (stk->top == stk->capacity -1) {
        if (!DoubleCapacity(stk)) {
            assert("overflow");
        }
    }

    stk->data[++stk->top] = data;
}

bool StackEmpty(stack* stk) {
    return (stk->top == -1);
}