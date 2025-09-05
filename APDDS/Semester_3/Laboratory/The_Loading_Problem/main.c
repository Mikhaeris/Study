#include <stdio.h>

#define COUNT_CARGO 20
#define ALL_COMBINATIONS 1048575
#define TARGET 600

int getAllCombinations(int *arr, int *goods);
void checkCombinations(int *arr, int count, int *goods);
void printAllCombinations(int *arr, int count);

int main() {
    int goods[COUNT_CARGO] = {
        72, 13, 64, 83, 62, 8, 79, 84, 69, 14, 98, 78, 29, 93, 46, 3, 1, 6, 10, 30
    }; /* 942 */
   
    static int max_comb[ALL_COMBINATIONS] = {0};
    int count_valid_combinations = getAllCombinations(max_comb, goods);

    printf("count comb: %d\n", count_valid_combinations);

    printf("check combinations? [y/N]: ");
    char c = getchar();
    if (c == 'y') {
        getchar();
        puts("");
        checkCombinations(max_comb, count_valid_combinations, goods);
        puts("");
    }
    c = 0;

    printf("print all combinations? [y/N]: ");
    c = getchar();
    if (c == 'y') {
        getchar();
        puts("");
        printAllCombinations(max_comb, count_valid_combinations);
        puts("");
    }
    c = 0;

    printf("print random combination? [y/N]: ");
    c = getchar();
    if (c == 'y') {
        getchar();
        puts("");
        printf("combination: ");
        int check_sum = 0;
        for (int i = 0; i < COUNT_CARGO; ++i) {
            if (max_comb[1] & (1 << i)) {
                printf("%d ", i+1);
                check_sum += goods[i];
            }
        }
        printf("\nsum: %d\n", check_sum);
    }

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
        if (curr_sum < TARGET && (TARGET - curr_sum) <= goods[10] && !(mask & (1 << 10))) {
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
void checkCombinations(int *arr, int count, int *goods) {
    char flag = 1;
    for (int i = 0; i < count; ++i) {
        int curr_sum = 0;
        for (int j = 0; j < COUNT_CARGO; ++j) {
            if (arr[i] & (1 << j)) {
                curr_sum += goods[j];
            }
        }

        if (curr_sum < 600) {
            printf("error: combination %d less then %d\n", i, TARGET);
            flag = 0;
        }

        if (curr_sum > 600) {
            if (!(arr[i] & (1 << 10))) {
                printf("error: combination %d more then %d and 11 good don't pick\n", i, TARGET);
                flag = 0;
            }

            if ((arr[i] & (1 << 10)) && curr_sum > TARGET+goods[10]) {
                printf("error: combination %d with 11 good, but sum more than %d\n", i, TARGET+goods[10]);
                flag = 0;
            }
        }

        if ((arr[i] & (1 << 0)) && !(arr[i] & (1 << 1))) {
            printf("error: combination %d with good 1, but don't have good 2", i);
            flag = 0;
        }
    }

    if (flag) {
        printf("all combinations good!\n");
    }
}

void printAllCombinations(int *arr, int count) {
    printf("all combinations:\n");
    for (int i = 0; i < count; ++i) {
        printf("combination %d", i);
        for (int j = 0; j < COUNT_CARGO; ++j) {
            if (arr[i] & (1 << j)) {
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
}
