/* array boot camp */
void EvenOdd(int32_t* array, int32_t size_of_array) {
    int32_t next_even = 0, next_odd = size_of_array - 1;
    while (next_even < next_odd) {
        if (array[next_even] % 2 == 0) {
            next_even++;
        } else {
            swap(array[next_even], array[next_odd]);
            --next_odd;
        }
    }
}

/* 6.1 Dutch Flag Partition*/
typedef enum {
    RED,
    WHITE,
    BLUE
} Color;
void DutchFlagPartition(int32_t pivot_index, Color* A_ptr) {
    Color* A = A_ptr;
    Color pivot = A[pivot_index];

    int32_t smaller = 0, equal = 0, larger = A.size();
    while (equal < larger) {
        if (A[equal] < pivot) {
            swap(A[smaller++], A[equal++]);
        } else if (A[equal] == pivot) {
            ++equal;
        } else {
            swap(A[equal++], A[--larger]);
        }
    }
}

/* 6.2 Increment an arbitrary-precision integer */
