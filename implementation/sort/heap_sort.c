#include <stdio.h>
#include <stdlib.h>

void swap(int32_t* array, int32_t left, int32_t right) {
    int32_t temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}

void MaxHeapify(int32_t* arr, int32_t n /* size of the map*/, int32_t index/*index of the node*/) {
    int32_t largest = index;
    int32_t left = 2 * index + 1;
    int32_t right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr, index, largest);
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(int32_t* arr, int32_t n) {
    for (int32_t i = n / 2 - 1; i >= 0; --i) {
        MaxHeapify(arr, n, i);
    }
}

void HeapSort(int32_t* arr, int32_t l, int32_t r) {
    int32_t n = r - l + 1;
    BuildMaxHeap(arr, n);

    for (int32_t i = r; i >= l; i--) {
        swap(arr, 0, i);

        MaxHeapify(arr, --n, 0);
    }
}

void main(int argc, char** argv) {
    printf("HeapSort\n");
    int32_t array[10] = {55, 56, 100, 1, 3, 4, 10000, 88, 334, 0};
    printf("before sorted: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    HeapSort(array, 0, 9);

    printf("\nafter sorted: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
}