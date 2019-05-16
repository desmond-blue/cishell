#include <stdio.h>
#include <stdlib.h>

void MergeSort(int32_t* array, int32_t* helper, int32_t l, int32_t r) {
    if (l < r) {
        int32_t m = (l + r) / 2; // m = l+ (r - l) / 2;

        MergeSort(array, helper, l, m);
        MergeSort(array, helper, m + 1, r);
        Merge(array, helper, l, m, r);
    }
}
// merge 2 sorted array
void Merge(int32_t* array, int32_t* helper, int32_t l, int32_t m, int32_t r) {
    for (int i = l; i <= r; i++) {
        helper[i] = array[i];
    }
    int32_t left = l;
    int32_t right = m + 1;
    int32_t current = left;
    while (left <= m && right <= r) {
        if (helper[left] <= helper[right]) {
            array[current] = helper[left];
            ++left;
        } else {
            array[current] = helper[right];
            ++right;
        }
        ++current;
    }

    int32_t remaining = m - left;
    for (int32_t i = 0; i <= remaining; i++) {
        array[current + i] = helper[left + i];
    }
}

void main(int argc, char** argv) {
    printf("main\n");
    int32_t array[10] = {55, 56, 100, 1, 3, 4, 10000, 88, 334, 0};
    printf("before sorted: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    int32_t* helper = (int32_t*)malloc(10 * sizeof(int32_t));
    MergeSort(array, helper, 0, 9);
    free(helper);

    printf("\nafter sorted: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
}