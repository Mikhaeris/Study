#include "../include/arrgen.h"

#include <stdlib.h>

void fill_arr(uint64_t *arr, size_t _size) {
    for (size_t i = 0; i < _size-2; ++i) {
        arr[i] = i+1;
    }
    arr[_size-2] = arr[_size-1] = 0;
}

static void swap(uint64_t *a, uint64_t *b) {
    uint64_t t = *a;
    *a = *b;
    *b = t;
}

void shuffle_arr(uint64_t *arr, size_t _size) {
    if (_size == 0) return;
    for (size_t last = _size-1; last > 0; --last) {
        size_t rand_idx = 0 + rand() % (last+1);
        swap(&arr[rand_idx], &arr[last]);
    }
}
