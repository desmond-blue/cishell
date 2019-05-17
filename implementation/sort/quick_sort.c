#include <stdio.h>
#include <stdlib.h>

void swap(int32_t* array, int32_t left, int32_t right) {
    int32_t temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}

void QuickSort(int32_t* array, int32_t left, int32_t right) {
    int32_t index = Partition(array, left, right);

    if (left < index - 1) {
        QuickSort(array, left, index -1 );
    }
    if (right > index) {
        QuickSort(array, index, right);
    }
}

int32_t Partition(int32_t* array, int32_t left, int32_t right) {
    int32_t pivot = array[(left + right) / 2];

    while (left <= right) {
        while (array[left] < pivot) ++left;

        while (array[right] > pivot) --right;

        if (left <= right) {
            swap(array, left, right);
            ++left;
            --right;
        }
    }

    return left;
}

void main(int argc, char** argv) {
    printf("QuickSort\n");
    int32_t array[10] = {55, 56, 100, 1, 3, 4, 10000, 88, 334, 0};
    printf("before sorted: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    QuickSort(array, 0, 9);

    printf("\nafter sorted: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
}