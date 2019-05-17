#include <stdlib.h>
#include <stdio.h>


static int32_t heap_capacity;
static int32_t heap_size;

void swap(int32_t* array, int32_t left, int32_t right) {
    int32_t temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}

int32_t parent(int32_t i) {
    return (i - 1) / 2;
}

int32_t left(int32_t i) {
    return 2 * i + 1;
}

int32_t right(int32_t i) {
    return 2 * i + 2;
}

void MinHeapify(int32_t* arr, int32_t n, int32_t index) {
    int32_t smallest = index;
    int32_t left = smallest * 2 + 1;
    int32_t right = smallest * 2 + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    } 

    if (smallest != index) {
        swap(arr, smallest, index);
        MinHeapify(arr, n, smallest);
    }
}

/*
void BuildMinHeap(int32_t* arr, int32_t n) {
    for (int32_t i = (n - 1) / 2; i >= 0; i--) {
        MinHeapify(arr, n, i);
    }
}
*/

int32_t* MinHeapNew(int32_t capacity) {
    heap_capacity = capacity;
    heap_size = 0;
    return (int32_t*)malloc(heap_capacity * sizeof(int32_t));
}

// insertKey
void MinHeapPush(int32_t* arr, int32_t val) {
    if (heap_size == heap_capacity) {
        printf("heap overflow\n");
        return;
    }

    ++heap_size;
    arr[heap_size] = val;

    int32_t i = heap_size - 1;
    while (i != 0 && arr[i] < arr[parent(i)]) {
        swap(arr, i, parent(i));
        i = parent(i);
    }
}

// getMin
int32_t MinHeapPeek(int32_t* heap) {
    return heap[0];
}

// extractMin
int32_t MinHeapPop(int32_t* heap) {
    if (heap_size == 0) {
        return 0x7FFFFFFF;
    }
    if (heap_size == 1) {
        --heap_size;
        return heap[0];
    }

    int32_t min = heap[0];
    heap[0] = heap[heap_size - 1];
    --heap_size;
    MinHeapify(heap, heap_size, 0);

    return min;
}

void MinHeapDecreaseKey(int32_t* heap, int32_t i, int32_t new_val) {
    if (new_val >= heap[i]) {
        return;
    }

    // sift up
    heap[i] = new_val;
    while (i != 0 && heap[i] < heap[parent(i)]) {
        swap(heap, i, parent(i));
        i = parent(i);
    }
}

void MinHeapDeleteKey(int32_t* heap, int32_t i) {
    MinHeapDecreaseKey(heap, i, 0xFFFFFFFF);
    MinHeapPop(i);
}

void MinHeapPrint(char* str, int32_t* arr, int32_t size) {
    printf("%s", str);
    for (int32_t i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

// Driver program to test above functions 
int main() 
{
    int32_t* heap = MinHeapNew(20);
    if (!heap) {
        printf("MinHeapNew failed\n");
        return 1;
    }

    MinHeapPush(heap, 3);
    MinHeapPush(heap, 21);
    MinHeapPush(heap, 1);
    MinHeapPush(heap, 15);
    MinHeapPush(heap, 5);
    MinHeapPush(heap, 4);
    MinHeapPush(heap, 45);
    MinHeapPush(heap, 100);
    MinHeapPush(heap, 1000);
    MinHeapPush(heap, 11);
    MinHeapPush(heap, 12);

    MinHeapPrint("[heap] ", heap, heap_size);


    printf("MinHeapPop: %d\n", MinHeapPop(heap));
    MinHeapPrint("[heap] ", heap, heap_size);

    printf("MinHeapPeek(): %d\n", MinHeapPeek(heap));
    MinHeapPrint("[heap] ", heap, heap_size);

    printf("MinHeapPop: %d\n", MinHeapPop(heap));
    MinHeapPrint("[heap] ", heap, heap_size);

    printf("MinHeapPop: %d\n", MinHeapPop(heap));
    MinHeapPrint("[heap] ", heap, heap_size);

    printf("MinHeapPop: %d\n", MinHeapPop(heap));
    MinHeapPrint("[heap] ", heap, heap_size);
    
    MinHeapDecreaseKey(heap, 2, 1);
    MinHeapPrint("[heap] ", heap, heap_size);
    
    printf("MinHeapPeek(): %d\n", MinHeapPeek(heap));
    MinHeapPrint("[heap] ", heap, heap_size);

    free(heap);

    return 0; 
} 