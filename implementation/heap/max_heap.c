#include <stdio.h>
#include <stdlib.h>

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

void MaxHeapify(int32_t* arr, int32_t n, int32_t index) {
    int32_t largest = index;
    int32_t left = largest * 2 + 1;
    int32_t right = largest * 2 + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    } 

    if (largest != index) {
        swap(arr, largest, index);
        MaxHeapify(arr, n, largest);
    }
}

int32_t* MaxHeapNew(int32_t capacity) {
    heap_capacity = capacity;
    heap_size = 0;
    return (int32_t*)malloc(heap_capacity * sizeof(int32_t));
}

// insertKey
void MaxHeapPush(int32_t* arr, int32_t val) {
    if (heap_size == heap_capacity) {
        printf("heap overflow\n");
        return;
    }

    ++heap_size;
    arr[heap_size] = val;

    int32_t i = heap_size - 1;
    while (i != 0 && arr[i] > arr[parent(i)]) {
        swap(arr, i, parent(i));
        i = parent(i);
    }
}

// getMax
int32_t MaxHeapPeek(int32_t* heap) {
    return heap[0];
}

// extractMax
int32_t MaxHeapPop(int32_t* heap) {
    if (heap_size == 0) {
        return 0x7FFFFFFF;
    }
    if (heap_size == 1) {
        --heap_size;
        return heap[0];
    }

    int32_t max = heap[0];
    heap[0] = heap[heap_size - 1];
    --heap_size;
    MaxHeapify(heap, heap_size, 0);

    return max;
}

void MaxHeapDecreaseKey(int32_t* heap, int32_t i, int32_t new_val) {
    if (new_val >= heap[i]) {
        return;
    }

    // sift up
    heap[i] = new_val;
    while (i != 0 && heap[i] > heap[parent(i)]) {
        swap(heap, i, parent(i));
        i = parent(i);
    }
}

void MaxHeapDeleteKey(int32_t* heap, int32_t i) {
    MaxHeapDecreaseKey(heap, i, 0xFFFFFFFF);
    MaxHeapPop(i);
}

void MaxHeapPrint(char* str, int32_t* arr, int32_t size) {
    printf("%s", str);
    for (int32_t i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

// Driver program to test above functions 
int main() 
{
    int32_t* heap = MaxHeapNew(20);
    if (!heap) {
        printf("MaxHeapNew failed\n");
        return 1;
    }

    MaxHeapPush(heap, 3);
    MaxHeapPush(heap, 21);
    MaxHeapPush(heap, 1);
    MaxHeapPush(heap, 15);
    MaxHeapPush(heap, 5);
    MaxHeapPush(heap, 4);
    MaxHeapPush(heap, 45);
    MaxHeapPush(heap, 100);
    MaxHeapPush(heap, 1000);
    MaxHeapPush(heap, 11);
    MaxHeapPush(heap, 12);

    MaxHeapPrint("[heap] ", heap, heap_size);


    printf("MaxHeapPop: %d\n", MaxHeapPop(heap));
    MaxHeapPrint("[heap] ", heap, heap_size);

    printf("MaxHeapPeek(): %d\n", MaxHeapPeek(heap));
    MaxHeapPrint("[heap] ", heap, heap_size);

    printf("MaxHeapPop: %d\n", MaxHeapPop(heap));
    MaxHeapPrint("[heap] ", heap, heap_size);

    printf("MaxHeapPop: %d\n", MaxHeapPop(heap));
    MaxHeapPrint("[heap] ", heap, heap_size);

    printf("MaxHeapPop: %d\n", MaxHeapPop(heap));
    MaxHeapPrint("[heap] ", heap, heap_size);
    
    MaxHeapDecreaseKey(heap, 2, 1);
    MaxHeapPrint("[heap] ", heap, heap_size);
    
    printf("MaxHeapPeek(): %d\n", MaxHeapPeek(heap));
    MaxHeapPrint("[heap] ", heap, heap_size);

    free(heap);

    return 0; 
} 