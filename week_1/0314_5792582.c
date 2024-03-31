#include <stdio.h>
#include <time.h>

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
    clock_t start, end;
    double cpu_time_used;

    start = clock(); 

    for (num = 2; num <= 100; num++) {
        if (isPrime(num)) {
            sumPrimeNum += num;
        }
    }

    end = clock(); 

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 

    printf("0부터 100까지의 소수들의 합: %d\n", sumPrimeNum);
    printf("프로그램 실행 시간: %f 초\n", cpu_time_used);
    return 0;
}
