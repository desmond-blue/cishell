struct StackNode;
typedef struct {
    struct StackNode* next;
    char data;
} StackNode;

typedef struct {
    int32_t index;
    StackNode* top;
} StackList;

StackList* newStack() {
    StackList* stack_list = (StackList*)malloc(sizeof(StackList));
    stack_list->index = -1;
    stack_list->top = NULL;

    return stack_list;
}

bool StackEmpty(StackList* stack_list) {
    return (stack_list->index == -1);
}

char StackPop(StackList** stack_list) {
    if (StackEmpty(*stack_list)) {
        assert("[Error] pop an empty queue.\n");
    }
    char data = (*stack_list)->top->data;
    //printf("pop %c\n", data);
    StackNode* del_node = (*stack_list)->top;
    (*stack_list)->top = (*stack_list)->top->next;
    free(del_node);
    --(*stack_list)->index;
    return data;
}

char StackPeek(StackList* stack_list) {
    //printf("peek %c\n", stack_list->top->data);
    return stack_list->top->data;
}

void StackPush(StackList** stack_list, char data) {
    //printf("push %c\n", data);
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->next = (*stack_list)->top;
    new_node->data = data;
    (*stack_list)->top = new_node;
    ++(*stack_list)->index;
}

void freeStack(StackList* stack_list) {
    StackNode *delete_node = stack_list->top;
    while (delete_node = stack_list->top) {
        stack_list->top = stack_list->top->next;
        free(delete_node);
    }
    free(stack_list);
}