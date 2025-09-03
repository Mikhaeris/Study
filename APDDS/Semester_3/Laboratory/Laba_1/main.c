#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void process_agr_in_file(FILE *fp, long long x);

int main(int argc, char **argv) {
    if (argc == 1) {

        return 0;
    }

    FILE *fp;
    while ((argc-=2) > 0) {
        if ((fp = fopen(*++argv, "r")) == NULL) {
            printf("error: can't open %s\n", *argv);
            return 1;
        }
        
        printf("file: %s\n", *argv);
        process_agr_in_file(fp, atoi(*++argv));
    }

    return 0;
}

long double polynom_function(long double v, long long x, long long param) {
    return v*pow(x, param);
}

void reset_str(char str[30]) {
    char *ptr = str;
    for (int i = 0; i < 30; ++i) {
        *ptr++ = '\0';
    }
}

void process_agr_in_file(FILE *fp, long long x) {
    char str[30] = {0};
    char *ptr_str = str;
    long double val = 0.0;

    int c;
    int line = 0, param = 1;
    while ((c = getc(fp)) != EOF) {
        if (c == '\n') {
            val += polynom_function(atof(str), x, param);
            printf("\tline %d: val pal: %Lf\n", line++, val);
            val = 0.0;

            ptr_str = str;
            reset_str(str);
            continue;
        }

        if (c == ' ') {
            val += polynom_function(atof(str), x, param);
            ptr_str = str;
            reset_str(str);
            continue;
        }
        
        *ptr_str++ = c;
    }
}
