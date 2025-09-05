#include "../include/arrgen.h"

#include <stdlib.h>

void fill_arr(uint64_t *arr, size_t _size) {
    for (size_t i = 0; i < _size; ++i) {
        arr[i] = i+1;
    }
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

void del_twomel(uint64_t *arr, size_t _size) {
    for (size_t i = 0; i < _size; ++i) {
        if ((arr[i] == _size-1) || (arr[i] == _size)) {
            arr[i] = 0;
        }
    }
}
