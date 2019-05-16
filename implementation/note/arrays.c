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