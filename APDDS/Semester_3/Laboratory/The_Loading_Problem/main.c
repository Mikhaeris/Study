/* TODO: 1) Дописать проверку комбинаций, учитывая 11 продук(10 бит) и перевозку товара 1 со 2
 *       2) Написать функцию вывода ответа(количества комбинаций и первую комбинацию и т.д.)
 *       2) Написать функцию вывода всех комбинаций с суммой */
#include <stdio.h>

#define COUNT_CARGO 20
#define ALL_COMBINATIONS 1048575
#define TARGET 600

int getAllCombinations(int *arr, int *goods);
void checkCombinations(int *arr, int count, int *goods);

int main() {
    int goods[COUNT_CARGO] = {
        72, 13, 64, 83, 62, 8, 79, 84, 69, 14, 98, 78, 29, 93, 46, 3, 1, 6, 10, 30
    }; /* 942 */
   
    static int max_comb[ALL_COMBINATIONS] = {0};
    int count_valid_combinations = getAllCombinations(max_comb, goods);

    // printf("cargo weight: %d\n", max_sum);
    printf("count comb: %d\n", count_valid_combinations);
    printf("some combination: ");

    int check_sum = 0;
    for (int i = 0; i < COUNT_CARGO; ++i) {
        if (max_comb[0] & (1 << i)) {
            printf("%d ", i+1);
            check_sum += goods[i];
        }
    }
    printf("\n%d\n", check_sum);

    /* printf("all combinations\n");
    for (int *i = max_comb; i < pc; ++i) {
        for (int j = 0; j < COUNT_CARGO; ++j) {
            if (*i & (1 << j)) {
                //printf("%d ", j+1);
            }
        }
        printf("\n");
    } */

    return 0;
}

int getAllCombinations(int *arr, int* goods) {
    int *pc = arr;

    int curr_sum;
    for (int mask = 1; mask < (1 << COUNT_CARGO); ++mask) {
        /* перевозка товара 1 не имеет смысла без товара 2,
         * но перевозка товара 2 имеет смысл без товара 1 */
        if ((mask & (1 << 0)) && !(mask & (1 << 1))) {
            continue;
        }

        curr_sum = 0;
        for (int i = 0; i < COUNT_CARGO; ++i) {
            if (mask & (1 << i)) {
                curr_sum += goods[i];
            }
        }
       
        /* так как товар 11 может быть раздроблен,
         * то его можно добавить текущую сумму */
        char flag = 0;
        if (curr_sum < TARGET && (TARGET - curr_sum) <= goods[10]) {
            curr_sum += TARGET - curr_sum;
            flag = 1;
        }

        if (curr_sum == TARGET) {
            int temp_mask = mask;
            /* если был взят 11 товар,
             * то нужно добавить его в маску */
            if (flag) {
                temp_mask |= (1 << 10);     
            }
            *pc++ = temp_mask;
        }
    }

    return pc - arr;
}

/* check combinations */
void checkCombinations(int *arr, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < COUNT_CARGO; ++j) {
            if (arr[i] & (1 << j)) {

            }
        }
    }
}
