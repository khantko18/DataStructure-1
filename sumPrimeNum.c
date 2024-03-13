#include <stdio.h>

int isPrime(int num) {
    int i;

    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, sumPrimeNum = 0;

    for (num = 2; num <= 100; num++) {
        if (isPrime(num)) {
            sumPrimeNum += num;
        }
    }

    printf("0부터 100까지의 소수들의 합: %d\n", sumPrimeNum);
    return 0;
}
