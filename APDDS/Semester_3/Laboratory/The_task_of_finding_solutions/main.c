#include "./include/arrgen.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 12ULL

void print_arr(uint64_t *arr, size_t _size);

int main() {
    srand(time(NULL));

    /* need to free */ 
    uint64_t *arr = malloc(MAX_SIZE * sizeof *arr);
    
    /* generate arr with two max zero elemants */
    fill_arr(arr, MAX_SIZE);
    shuffle_arr(arr, MAX_SIZE);

    print_arr(arr, MAX_SIZE);

    return 0;
}

void print_arr(uint64_t *arr, size_t _size) {
    printf("arr: ");
    for (size_t i = 0; i < _size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
