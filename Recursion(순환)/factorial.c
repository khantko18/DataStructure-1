#include <stdio.h>

double factorial_iter(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double factorial_rec(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial_rec(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a positive number: ");
    scanf("%d", &num);

    double result_iter = factorial_iter(num);
    double result_rec = factorial_rec(num);

    printf("Factorial using iteration for %d: %f\n", num, result_iter);
    printf("Factorial using recursion for %d: %f\n", num, result_rec);

    return 0;
}

