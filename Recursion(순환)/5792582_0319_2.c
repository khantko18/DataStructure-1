#include <stdio.h>
#include <time.h>

double power_iter(int base, int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double power_rec(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power_rec(base, exponent - 1);
    }
}

int main() {
    clock_t start, end;
    double result_iter, result_rec;

    start = clock();
    result_iter = power_iter(13, 21);
    end = clock();
    printf("Power Iterative Result : %f\n", result_iter);
    printf("Time : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    result_rec = power_rec(13, 21);
    end = clock();
    printf("Power Recursive Result : %f\n", result_rec);
    printf("Time : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}